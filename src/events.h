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

#ifndef FS_EVENTS_H
#define FS_EVENTS_H

#include "luascript.h"
#include "const.h"
#include "creature.h"

class Party;
class ItemType;
class NetworkMessage;
class Tile;

class Events
{
	struct EventsInfo {
		// Creature
		int32_t creatureOnChangeOutfit = -1;
		int32_t creatureOnAreaCombat = -1;
		int32_t creatureOnTargetCombat = -1;
		int32_t creatureOnHear = -1;
		int32_t creatureOnChangeZone = -1;

		// Party
		int32_t partyOnJoin = -1;
		int32_t partyOnLeave = -1;
		int32_t partyOnDisband = -1;
		int32_t partyOnInvite = -1;
		int32_t partyOnRevokeInvitation = -1;
		int32_t partyOnPassLeadership = -1;
		int32_t partyOnShareExperience = -1;

		// Player
		int32_t playerOnLook = -1;
		int32_t playerOnLookInBattleList = -1;
		int32_t playerOnLookInTrade = -1;
		int32_t playerOnLookInShop = -1;
		int32_t playerOnMoveItem = -1;
		int32_t playerOnItemMoved = -1;
		int32_t playerOnMoveCreature = -1;
		int32_t playerOnReportRuleViolation = -1;
		int32_t playerOnReportBug = -1;
		int32_t playerOnTurn = -1;
		int32_t playerOnTradeRequest = -1;
		int32_t playerOnTradeAccept = -1;
		int32_t playerOnTradeCompleted = -1;
		int32_t playerOnGainExperience = -1;
		int32_t playerOnLoseExperience = -1;
		int32_t playerOnGainSkillTries = -1;
		int32_t playerOnInventoryUpdate = -1;
		int32_t playerOnStepTile = -1;
		int32_t playerOnNetworkMessage = -1;
		int32_t playerOnUpdateStorage = -1;
		int32_t playerOnSay = -1;
		int32_t playerOnChangeGhostMode = -1;
		int32_t playerOnSpellCheck = -1;

		// Monster
		int32_t monsterOnDropLoot = -1;
		int32_t monsterOnSpawn = -1;
		
		// Item
		int32_t itemOnImbue = -1;
		int32_t itemOnRemoveImbue = -1;
	};

	public:
		Events();

		bool load();

		// Creature
		bool eventCreatureOnChangeOutfit(Creature* creature, const Outfit_t& outfit);
		ReturnValue eventCreatureOnAreaCombat(Creature* creature, Tile* tile, bool aggressive);
		ReturnValue eventCreatureOnTargetCombat(Creature* creature, Creature* target);
		void eventCreatureOnHear(Creature* creature, Creature* speaker, const std::string& words, SpeakClasses type);
		void eventCreatureOnChangeZone(Creature* creature, ZoneType_t fromZone, ZoneType_t toZone);

		// Party
		bool eventPartyOnJoin(Party* party, Player* player);
		bool eventPartyOnLeave(Party* party, Player* player);
		bool eventPartyOnDisband(Party* party);
		bool eventPartyOnInvite(Party* party, Player* player);
		bool eventPartyOnRevokeInvitation(Party* party, Player* player);
		bool eventPartyOnPassLeadership(Party* party, Player* player);
		void eventPartyOnShareExperience(Party* party, uint64_t& exp);

		// Player
		void eventPlayerOnLook(Player* player, const Position& position, Thing* thing, uint8_t stackpos, int32_t lookDistance);
		void eventPlayerOnLookInBattleList(Player* player, Creature* creature, int32_t lookDistance);
		void eventPlayerOnLookInTrade(Player* player, Player* partner, Item* item, int32_t lookDistance);
		bool eventPlayerOnLookInShop(Player* player, const ItemType* itemType, uint8_t count, const std::string& description);
		bool eventPlayerOnMoveItem(Player* player, Item* item, uint16_t count, const Position& fromPosition, const Position& toPosition, Cylinder* fromCylinder, Cylinder* toCylinder);
		void eventPlayerOnItemMoved(Player* player, Item* item, uint16_t count, const Position& fromPosition, const Position& toPosition, Cylinder* fromCylinder, Cylinder* toCylinder);
		bool eventPlayerOnMoveCreature(Player* player, Creature* creature, const Position& fromPosition, const Position& toPosition);
		void eventPlayerOnReportRuleViolation(Player* player, const std::string& targetName, uint8_t reportType, uint8_t reportReason, const std::string& comment, const std::string& translation);
		bool eventPlayerOnReportBug(Player* player, const std::string& message);
		bool eventPlayerOnTurn(Player* player, Direction direction);
		bool eventPlayerOnTradeRequest(Player* player, Player* target, Item* item);
		bool eventPlayerOnTradeAccept(Player* player, Player* target, Item* item, Item* targetItem);
		void eventPlayerOnTradeCompleted(Player* player, Player* target, Item* item, Item* targetItem, bool isSuccess);
		void eventPlayerOnGainExperience(Player* player, Creature* source, uint64_t& exp, uint64_t rawExp, bool sendText);
		void eventPlayerOnLoseExperience(Player* player, uint64_t& exp);
		void eventPlayerOnGainSkillTries(Player* player, skills_t skill, uint64_t& tries);
		void eventPlayerOnInventoryUpdate(Player* player, Item* item, slots_t slot, bool equip);
		bool eventPlayerOnStepTile(Player* player, const Position& fromPosition, const Position& toPosition);
		void eventPlayerOnNetworkMessage(Player* player, uint8_t recvByte, NetworkMessage* msg);
		void eventPlayerOnUpdateStorage(Player* player, const uint32_t key, const int32_t value, const int32_t oldValue, bool isLogin);
		bool eventPlayerOnSay(Player* player, const std::string& message);
		void eventPlayerOnChangeGhostMode(Player* player);
		bool eventPlayerOnSpellCheck(Player* player, const Spell* spell);

		// Monster
		void eventMonsterOnDropLoot(Monster* monster, Container* corpse);
		bool eventMonsterOnSpawn(Monster* monster, const Position& position, bool startup, bool artificial);
		
		// Item
		bool eventItemOnImbue(Item* item, std::shared_ptr<Imbuement> imbuement, bool created = true);
		void eventItemOnRemoveImbue(Item* item, ImbuementType imbueType, bool decayed = false);

	private:
		LuaScriptInterface scriptInterface;
		EventsInfo info;
};

#endif
