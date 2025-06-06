/**
 * The Forgotten Server - a free and open-source MMORPG server emulator
 * Copyright (C) 2019  Mark Samman <mark.samman@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "otpch.h"

#include "configmanager.h"
#include "database.h"

#include <mysql/errmsg.h>

extern ConfigManager g_config;

static bool connectToDatabase(MYSQL*& handle, const bool retryIfError)
{
	bool isFirstAttemptToConnect = true;

retry:
	if (!isFirstAttemptToConnect) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	// close the connection handle
	mysql_close(handle);
	// connection handle initialization
	handle = mysql_init(nullptr);
	if (!handle) {
		std::cout << std::endl << "Failed to initialize MySQL connection handle." << std::endl;
		goto error;
	}

	// connects to database
	if (!mysql_real_connect(handle, g_config.getString(ConfigManager::MYSQL_HOST).c_str(), g_config.getString(ConfigManager::MYSQL_USER).c_str(), g_config.getString(ConfigManager::MYSQL_PASS).c_str(), g_config.getString(ConfigManager::MYSQL_DB).c_str(), g_config.getNumber(ConfigManager::SQL_PORT), g_config.getString(ConfigManager::MYSQL_SOCK).c_str(), 0)) {
		std::cout << std::endl << "MySQL Error Message: " << mysql_error(handle) << std::endl;
		goto error;
	}
	return true;

error:
	if (retryIfError) {
		goto retry;
	}
	return false;
}

static bool isLostConnectionError(const unsigned error)
{
	return error == CR_SERVER_LOST || error == CR_SERVER_GONE_ERROR || error == CR_CONN_HOST_ERROR ||
	    error == 1053 /*ER_SERVER_SHUTDOWN*/ || error == CR_CONNECTION_ERROR;
}

static bool executeQuery(MYSQL*& handle, const std::string_view query, const bool retryIfLostConnection)
{
	while (mysql_real_query(handle, query.data(), query.length()) != 0) {
		std::cout << "[Error - mysql_real_query] Query: " << query.substr(0, 256) << std::endl
		          << "Message: " << mysql_error(handle) << std::endl;
		const unsigned error = mysql_errno(handle);
		if (!isLostConnectionError(error) || !retryIfLostConnection) {
			return false;
		}
		connectToDatabase(handle, true);
	}

	return true;
}

Database::~Database() { mysql_close(handle); }

bool Database::connect()
{
	if (!connectToDatabase(handle, false)) {
		return false;
	}

	DBResult_ptr result = storeQuery("SHOW VARIABLES LIKE 'max_allowed_packet'");
	if (result) {
		maxPacketSize = result->getNumber<uint64_t>("Value");
	}
	return true;
}

bool Database::beginTransaction()
{
	databaseLock.lock();
	const bool result = executeQuery("START TRANSACTION");
	retryQueries = !result;
	if (!result) {
		databaseLock.unlock();
	}

	return result;
}

bool Database::rollback()
{
	const bool result = executeQuery("ROLLBACK");
	retryQueries = true;
	databaseLock.unlock();
	return result;
}

bool Database::commit()
{
	const bool result = executeQuery("COMMIT");
	retryQueries = true;
	databaseLock.unlock();
	return result;
}

bool Database::executeQuery(const std::string& query)
{
	std::lock_guard<std::recursive_mutex> lockGuard(databaseLock);
	return ::executeQuery(handle, query, retryQueries);
}

DBResult_ptr Database::storeQuery(const std::string& query)
{
	std::lock_guard<std::recursive_mutex> lockGuard(databaseLock);

	retry:
	if (!::executeQuery(handle, query, retryQueries) && !retryQueries) {
		return nullptr;
	}

	// we should call that every time as someone would call executeQuery('SELECT...')
	// as it is described in MySQL manual: "it doesn't hurt" :P
	MYSQL_RES* res = mysql_store_result(handle);
	if (res == nullptr) {
		std::cout << "[Error - mysql_store_result] Query: " << query << std::endl << "Message: " << mysql_error(handle) << std::endl;
		const unsigned error = mysql_errno(handle);
		if (!isLostConnectionError(error) || !retryQueries) {
			return nullptr;
		}
		goto retry;
	}

	// retrieving results of query
	DBResult_ptr result = std::make_shared<DBResult>(res);
	if (!result->hasNext()) {
		return nullptr;
	}
	return result;
}

std::string Database::escapeString(const std::string& s) const
{
	return escapeBlob(s.c_str(), s.length());
}

std::string Database::escapeBlob(const char* s, uint32_t length) const
{
	// the worst case is 2n + 1
	size_t maxLength = (length * 2) + 1;

	std::string escaped;
	escaped.reserve(maxLength + 2);
	escaped.push_back('\'');

	if (length != 0) {
		char* output = new char[maxLength];
		mysql_real_escape_string(handle, output, s, length);
		escaped.append(output);
		delete[] output;
	}

	escaped.push_back('\'');
	return escaped;
}

DBResult::DBResult(MYSQL_RES* res)
{
	handle = res;

	size_t i = 0;

	MYSQL_FIELD* field = mysql_fetch_field(handle);
	while (field) {
		listNames[field->name] = i++;
		field = mysql_fetch_field(handle);
	}

	row = mysql_fetch_row(handle);
}

DBResult::~DBResult()
{
	mysql_free_result(handle);
}

std::string DBResult::getString(const std::string& s) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getString] Column '" << s << "' does not exist in result set." << std::endl;
		return std::string();
	}

	if (row[it->second] == nullptr) {
		return std::string();
	}

	return std::string(row[it->second]);
}

const char* DBResult::getStream(const std::string& s, unsigned long& size) const
{
	auto it = listNames.find(s);
	if (it == listNames.end()) {
		std::cout << "[Error - DBResult::getStream] Column '" << s << "' doesn't exist in the result set" << std::endl;
		size = 0;
		return nullptr;
	}

	if (row[it->second] == nullptr) {
		size = 0;
		return nullptr;
	}

	size = mysql_fetch_lengths(handle)[it->second];
	return row[it->second];
}

bool DBResult::hasNext() const
{
	return row != nullptr;
}

bool DBResult::next()
{
	row = mysql_fetch_row(handle);
	return row != nullptr;
}

DBInsert::DBInsert(std::string query) : query(std::move(query))
{
	this->length = this->query.length();
}

bool DBInsert::addRow(const std::string& row)
{
	// adds new row to buffer
	const size_t rowLength = row.length();
	length += rowLength;
	if (length > Database::getInstance().getMaxPacketSize() && !execute()) {
		return false;
	}

	if (values.empty()) {
		values.reserve(rowLength + 2);
		values.push_back('(');
		values.append(row);
		values.push_back(')');
	} else {
		values.reserve(values.length() + rowLength + 3);
		values.push_back(',');
		values.push_back('(');
		values.append(row);
		values.push_back(')');
	}
	return true;
}

bool DBInsert::addRow(std::ostringstream& row)
{
	bool ret = addRow(row.str());
	row.str(std::string());
	return ret;
}

bool DBInsert::execute()
{
	if (values.empty()) {
		return true;
	}

	// executes buffer
	bool res = Database::getInstance().executeQuery(query + values);
	values.clear();
	length = query.length();
	return res;
}
