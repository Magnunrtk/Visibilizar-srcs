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

#ifndef FS_CONST_H
#define FS_CONST_H

static constexpr int32_t NETWORKMESSAGE_MAXSIZE = 65500;
static constexpr int32_t MIN_MARKET_FEE = 20;
static constexpr int32_t MAX_MARKET_FEE = 100000;

enum MagicEffectClasses : uint8_t {
	CONST_ME_NONE,

	CONST_ME_DRAWBLOOD = 1,
	CONST_ME_LOSEENERGY = 2,
	CONST_ME_POFF = 3,
	CONST_ME_BLOCKHIT = 4,
	CONST_ME_EXPLOSIONAREA = 5,
	CONST_ME_EXPLOSIONHIT = 6,
	CONST_ME_FIREAREA = 7,
	CONST_ME_YELLOW_RINGS = 8,
	CONST_ME_GREEN_RINGS = 9,
	CONST_ME_HITAREA = 10,
	CONST_ME_TELEPORT = 11,
	CONST_ME_ENERGYHIT = 12,
	CONST_ME_MAGIC_BLUE = 13,
	CONST_ME_MAGIC_RED = 14,
	CONST_ME_MAGIC_GREEN = 15,
	CONST_ME_HITBYFIRE = 16,
	CONST_ME_HITBYPOISON = 17,
	CONST_ME_MORTAREA = 18,
	CONST_ME_SOUND_GREEN = 19,
	CONST_ME_SOUND_RED = 20,
	CONST_ME_POISONAREA = 21,
	CONST_ME_SOUND_YELLOW = 22,
	CONST_ME_SOUND_PURPLE = 23,
	CONST_ME_SOUND_BLUE = 24,
	CONST_ME_SOUND_WHITE = 25,
	CONST_ME_BUBBLES = 26,
	CONST_ME_CRAPS = 27,
	CONST_ME_GIFT_WRAPS = 28,
	CONST_ME_FIREWORK_YELLOW = 29,
	CONST_ME_FIREWORK_RED = 30,
	CONST_ME_FIREWORK_BLUE = 31,
	CONST_ME_STUN = 32,
	CONST_ME_SLEEP = 33,
	CONST_ME_WATERCREATURE = 34,
	CONST_ME_GROUNDSHAKER = 35,
	CONST_ME_HEARTS = 36,
	CONST_ME_FIREATTACK = 37,
	CONST_ME_ENERGYAREA = 38,
	CONST_ME_SMALLCLOUDS = 39,
	CONST_ME_HOLYDAMAGE = 40,
	CONST_ME_BIGCLOUDS = 41,
	CONST_ME_ICEAREA = 42,
	CONST_ME_ICETORNADO = 43,
	CONST_ME_ICEATTACK = 44,
	CONST_ME_STONES = 45,
	CONST_ME_SMALLPLANTS = 46,
	CONST_ME_CARNIPHILA = 47,
	CONST_ME_PURPLEENERGY = 48,
	CONST_ME_YELLOWENERGY = 49,
	CONST_ME_HOLYAREA = 50,
	CONST_ME_BIGPLANTS = 51,
	CONST_ME_CAKE = 52,
	CONST_ME_GIANTICE = 53,
	CONST_ME_WATERSPLASH = 54,
	CONST_ME_PLANTATTACK = 55,
	CONST_ME_TUTORIALARROW = 56,
	CONST_ME_TUTORIALSQUARE = 57,
	CONST_ME_MIRRORHORIZONTAL = 58,
	CONST_ME_MIRRORVERTICAL = 59,
	CONST_ME_SKULLHORIZONTAL = 60,
	CONST_ME_SKULLVERTICAL = 61,
	CONST_ME_ASSASSIN = 62,
	CONST_ME_STEPSHORIZONTAL = 63,
	CONST_ME_BLOODYSTEPS = 64,
	CONST_ME_STEPSVERTICAL = 65,
	CONST_ME_YALAHARIGHOST = 66,
	CONST_ME_BATS = 67,
	CONST_ME_SMOKE = 68,
	CONST_ME_INSECTS = 69,
	CONST_ME_DRAGONHEAD = 70,
	//New Effect Include
	CONST_ME_ORCSHAMAN = 71,
	CONST_ME_ORCSHAMAN_FIRE = 72,
	CONST_ME_THUNDER = 73,
	CONST_ME_FERUMBRAS = 74,
	CONST_ME_CONFETTI_HORIZONTAL = 75,
	CONST_ME_CONFETTI_VERTICAL = 76,
	// 77-157 are empty
	CONST_ME_BLACKSMOKE = 158,
	// 159-166 are empty
	CONST_ME_REDSMOKE = 167,
	CONST_ME_YELLOWSMOKE = 168,
	CONST_ME_GREENSMOKE = 169,
	CONST_ME_PURPLESMOKE = 170,
	CONST_ME_LIGHTNING = 171,
	CONST_ME_RAGIAZ_BONE_CAPSULE = 172,
	CONST_ME_CRITICAL_HIT = 173,
	// 174 is empty
	CONST_ME_PLUNGING_FISH = 175,
	CONST_ME_BLUE_ENERGY_SPARK = 176,
	CONST_ME_ORANGE_ENERGY_SPARK = 177,
	CONST_ME_GREEN_ENERGY_SPARK = 178,
	CONST_ME_PINK_ENERGY_SPARK = 179,
	CONST_ME_WHITE_ENERGY_SPARK = 180,
	CONST_ME_YELLOW_ENERGY_SPARK = 181,
	CONST_ME_MAGIC_POWDER = 182,
	// 183 is empty
	CONST_ME_PIXIE_EXPLOSION = 184,
	CONST_ME_PIXIE_COMING = 185,
	CONST_ME_PIXIE_GOING = 186,
	// 187 is empty
	CONST_ME_STORM = 188,
	CONST_ME_STONE_STORM = 189,
	// 190 is empty
	CONST_ME_BLUE_GHOST = 191,
	// 192 is empty
	CONST_ME_PINK_VORTEX = 193,
	CONST_ME_TREASURE_MAP = 194,
	CONST_ME_PINK_BEAM = 195,
	CONST_ME_GREEN_FIREWORKS = 196,
	CONST_ME_ORANGE_FIREWORKS = 197,
	CONST_ME_PINK_FIREWORKS = 198,
	CONST_ME_BLUE_FIREWORKS = 199,
	CONST_ME_SUPREME_CUBE = 201,
	CONST_ME_BLACK_BLOOD = 202,
	CONST_ME_PRISMATIC_SPARK = 203,
	CONST_ME_THAIAN = 204,
	CONST_ME_THAIAN_GHOST = 205,
	CONST_ME_GHOST_SMOKE = 206,
	// 207 is empty
	CONST_ME_WATER_BLOCK_FLOATING = 208,
	CONST_ME_WATER_BLOCK = 209,
	CONST_ME_ROOTS = 210,
	// 211-212 is empty
	CONST_ME_GHOSTLY_SCRATCH = 213,
	CONST_ME_GHOSTLY_BITE = 214,
	CONST_ME_BIG_SCRATCH = 215,
	CONST_ME_SLASH = 216,
	CONST_ME_BITE = 217,
	// 218 empty or debug
	CONST_ME_CHIVALRIOUS_CHALLENGE = 219,
	CONST_ME_DIVINE_DAZZLE = 220,
	CONST_ME_ELECTRICALSPARK = 221,
	CONST_ME_PURPLETELEPORT = 222,
	CONST_ME_REDTELEPORT = 223,
	CONST_ME_ORANGETELEPORT = 224,
	CONST_ME_GREYTELEPORT = 225,
	CONST_ME_LIGHTBLUETELEPORT = 226,
	// 227-229 are empty
	CONST_ME_FATAL = 230,
	CONST_ME_DODGE = 231,
	CONST_ME_HOURGLASS = 232,
	CONST_ME_DAZZLING = 233,
	// 233-234 are empty
	CONST_ME_FERUMBRAS_1 = 235,
	CONST_ME_GAZHARAGOTH = 236,
	CONST_ME_MAD_MAGE = 237,
	CONST_ME_HORESTIS = 238,
	CONST_ME_DEVOVORGA = 239,
	CONST_ME_FERUMBRAS_2 = 240,
	CONST_ME_WHITE_SMOKE = 241,
	CONST_ME_WHITE_SMOKES = 242,
	CONST_ME_WATER_DROP = 243,
	CONST_ME_AVATAR_APPEAR = 244,
	CONST_ME_DIVINE_GRENADE = 245,
	CONST_ME_DIVINE_EMPOWERMENT = 246,
	CONST_ME_WATER_FLOATING_THRASH = 247,
	// 248 are empty
	CONST_ME_AGONY = 249,
	// 250-251 are empty
	CONST_ME_LOOT_HIGHLIGHT = 252
};

enum ShootType_t : uint8_t {
	CONST_ANI_NONE,

	CONST_ANI_SPEAR = 1,
	CONST_ANI_BOLT = 2,
	CONST_ANI_ARROW = 3,
	CONST_ANI_FIRE = 4,
	CONST_ANI_ENERGY = 5,
	CONST_ANI_POISONARROW = 6,
	CONST_ANI_BURSTARROW = 7,
	CONST_ANI_THROWINGSTAR = 8,
	CONST_ANI_THROWINGKNIFE = 9,
	CONST_ANI_SMALLSTONE = 10,
	CONST_ANI_DEATH = 11,
	CONST_ANI_LARGEROCK = 12,
	CONST_ANI_SNOWBALL = 13,
	CONST_ANI_POWERBOLT = 14,
	CONST_ANI_POISON = 15,
	CONST_ANI_INFERNALBOLT = 16,
	CONST_ANI_HUNTINGSPEAR = 17,
	CONST_ANI_ENCHANTEDSPEAR = 18,
	CONST_ANI_REDSTAR = 19,
	CONST_ANI_GREENSTAR = 20,
	CONST_ANI_ROYALSPEAR = 21,
	CONST_ANI_SNIPERARROW = 22,
	CONST_ANI_ONYXARROW = 23,
	CONST_ANI_PIERCINGBOLT = 24,
	CONST_ANI_WHIRLWINDSWORD = 25,
	CONST_ANI_WHIRLWINDAXE = 26,
	CONST_ANI_WHIRLWINDCLUB = 27,
	CONST_ANI_ETHEREALSPEAR = 28,
	CONST_ANI_ICE = 29,
	CONST_ANI_EARTH = 30,
	CONST_ANI_HOLY = 31,
	CONST_ANI_SUDDENDEATH = 32,
	CONST_ANI_FLASHARROW = 33,
	CONST_ANI_FLAMMINGARROW = 34,
	CONST_ANI_SHIVERARROW = 35,
	CONST_ANI_ENERGYBALL = 36,
	CONST_ANI_SMALLICE = 37,
	CONST_ANI_SMALLHOLY = 38,
	CONST_ANI_SMALLEARTH = 39,
	CONST_ANI_EARTHARROW = 40,
	CONST_ANI_EXPLOSION = 41,
	CONST_ANI_CAKE = 42,
	//New Distance Include
	CONST_ANI_TARSALARROW = 44,
	CONST_ANI_VORTEXBOLT = 45,
	CONST_ANI_PRISMATICBOLT = 48,
	CONST_ANI_CRYSTALLINEARROW = 49,
	CONST_ANI_DRILLBOLT = 50,
	CONST_ANI_ENVENOMEDARROW = 51,
	CONST_ANI_GLOOTHSPEAR = 53,
	CONST_ANI_SIMPLEARROW = 54,
	CONST_ANI_LEAFSTAR = 56,
	CONST_ANI_DIAMONDARROW = 57,
	CONST_ANI_SPECTRALBOLT = 58,
	CONST_ANI_ROYALSTAR = 59,

	// for internal use, don't send to client
	CONST_ANI_WEAPONTYPE = 0xFE, // 254
};

enum SpeakClasses : uint8_t {
	TALKTYPE_SAY = 1,
	TALKTYPE_WHISPER = 2,
	TALKTYPE_YELL = 3,
	TALKTYPE_PRIVATE_PN = 4,
	TALKTYPE_PRIVATE_NP = 5,
	TALKTYPE_PRIVATE = 6,
	TALKTYPE_CHANNEL_Y = 7,
	TALKTYPE_CHANNEL_W = 8,
	TALKTYPE_RVR_CHANNEL = 9,
	TALKTYPE_RVR_ANSWER = 10,
	TALKTYPE_RVR_CONTINUE = 11,
	TALKTYPE_BROADCAST = 12,
	TALKTYPE_CHANNEL_R1 = 13, //red - #c text
	TALKTYPE_PRIVATE_RED = 14, //@name@text
	TALKTYPE_CHANNEL_O = 15, //@name@text
	TALKTYPE_CHANNEL_R2 = 17, //#d
	TALKTYPE_MONSTER_SAY = 19,
	TALKTYPE_MONSTER_YELL = 20,
};

enum MessageClasses : uint8_t {
	MESSAGE_STATUS_CONSOLE_RED = 18, /*Red message in the console*/
	MESSAGE_EVENT_ORANGE = 19, /*Orange message in the console*/
	MESSAGE_STATUS_CONSOLE_ORANGE = 20,  /*Orange message in the console*/
	MESSAGE_STATUS_WARNING = 21, /*Red message in game window and in the console*/
	MESSAGE_EVENT_ADVANCE = 22, /*White message in game window and in the console*/
	MESSAGE_EVENT_DEFAULT = 23, /*White message at the bottom of the game window and in the console*/
	MESSAGE_STATUS_DEFAULT = 24, /*White message at the bottom of the game window and in the console*/
	MESSAGE_INFO_DESCR = 25, /*Green message in game window and in the console*/
	MESSAGE_STATUS_SMALL = 26, /*White message at the bottom of the game window"*/
	MESSAGE_STATUS_CONSOLE_BLUE = 27, /*FIXME Blue message in the console*/
};

enum FluidColors_t : uint8_t {
	FLUID_EMPTY,
	FLUID_BLUE,
	FLUID_RED,
	FLUID_BROWN,
	FLUID_GREEN,
	FLUID_YELLOW,
	FLUID_WHITE,
	FLUID_PURPLE,
	FLUID_BLACK,
};

enum FluidTypes_t : uint8_t {
	FLUID_NONE = FLUID_EMPTY,
	FLUID_WATER = FLUID_BLUE,
	FLUID_BLOOD = FLUID_RED,
	FLUID_BEER = FLUID_BROWN,
	FLUID_SLIME = FLUID_GREEN,
	FLUID_LEMONADE = FLUID_YELLOW,
	FLUID_MILK = FLUID_WHITE,
	FLUID_MANA = FLUID_PURPLE,
	FLUID_INK = FLUID_BLACK,

	FLUID_LIFE = FLUID_RED + 8,
	FLUID_OIL = FLUID_BROWN + 8,
	FLUID_URINE = FLUID_YELLOW + 8,
	FLUID_COCONUTMILK = FLUID_WHITE + 8,
	FLUID_WINE = FLUID_PURPLE + 8,

	FLUID_MUD = FLUID_BROWN + 16,
	FLUID_FRUITJUICE = FLUID_YELLOW + 16,

	FLUID_LAVA = FLUID_RED + 24,
	FLUID_RUM = FLUID_BROWN + 24,
	FLUID_SWAMP = FLUID_GREEN + 24,

	FLUID_TEA = FLUID_BROWN + 32,

	FLUID_MEAD = FLUID_BROWN + 40,
};

const uint8_t reverseFluidMap[] = {
	FLUID_EMPTY,
	FLUID_WATER,
	FLUID_MANA,
	FLUID_BEER,
	FLUID_EMPTY,
	FLUID_BLOOD,
	FLUID_SLIME,
	FLUID_EMPTY,
	FLUID_LEMONADE,
	FLUID_MILK,
	FLUID_INK,
};

const uint8_t clientToServerFluidMap[] = {
	FLUID_EMPTY,
	FLUID_WATER,
	FLUID_MANA,
	FLUID_BEER,
	FLUID_MUD,
	FLUID_BLOOD,
	FLUID_SLIME,
	FLUID_RUM,
	FLUID_LEMONADE,
	FLUID_MILK,
	FLUID_WINE,
	FLUID_LIFE,
	FLUID_URINE,
	FLUID_OIL,
	FLUID_FRUITJUICE,
	FLUID_COCONUTMILK,
	FLUID_TEA,
	FLUID_MEAD,
	FLUID_INK,
};

enum ClientFluidTypes_t : uint8_t {
	CLIENTFLUID_EMPTY = 0,
	CLIENTFLUID_BLUE = 1,
	CLIENTFLUID_PURPLE = 2,
	CLIENTFLUID_BROWN_1 = 3,
	CLIENTFLUID_BROWN_2 = 4,
	CLIENTFLUID_RED = 5,
	CLIENTFLUID_GREEN = 6,
	CLIENTFLUID_BROWN = 7,
	CLIENTFLUID_YELLOW = 8,
	CLIENTFLUID_WHITE = 9,
	CLIENTFLUID_BLACK = 18,
};

const uint8_t fluidMap[] = {
	CLIENTFLUID_EMPTY,
	CLIENTFLUID_BLUE,
	CLIENTFLUID_RED,
	CLIENTFLUID_BROWN_1,
	CLIENTFLUID_GREEN,
	CLIENTFLUID_YELLOW,
	CLIENTFLUID_WHITE,
	CLIENTFLUID_PURPLE,
	CLIENTFLUID_BLACK,
};

enum SquareColor_t : uint8_t {
	SQ_COLOR_BLACK = 0,
};

enum TextColor_t : uint8_t {
	TEXTCOLOR_BLACK = 0,
	TEXTCOLOR_BLUE = 5,
	TEXTCOLOR_GREEN = 18,
	TEXTCOLOR_LIGHTGREEN = 66,
	TEXTCOLOR_DARKBROWN = 78,
	TEXTCOLOR_DARKGREY = 86,
	TEXTCOLOR_LIGHTBLUE = 89,
	TEXTCOLOR_MAYABLUE = 95,
	TEXTCOLOR_DARKRED = 108,
	TEXTCOLOR_DARKPURPLE = 112,
	TEXTCOLOR_BROWN = 120,
	TEXTCOLOR_GREY = 129,
	TEXTCOLOR_TEAL = 143,
	TEXTCOLOR_DARKPINK = 152,
	TEXTCOLOR_PURPLE = 154,
	TEXTCOLOR_DARKORANGE = 156,
	TEXTCOLOR_RED = 180,
	TEXTCOLOR_PINK = 190,
	TEXTCOLOR_ORANGE = 192,
	TEXTCOLOR_DARKYELLOW = 205,
	TEXTCOLOR_YELLOW = 210,
	TEXTCOLOR_WHITE = 215,
	TEXTCOLOR_NONE = 255,
};

enum Icons_t {
	ICON_POISON = 1 << 0,
	ICON_BURN = 1 << 1,
	ICON_ENERGY =  1 << 2,
	ICON_DRUNK = 1 << 3,
	ICON_MANASHIELD = 1 << 4,
	ICON_PARALYZE = 1 << 5,
	ICON_HASTE = 1 << 6,
	ICON_SWORDS = 1 << 7,
	ICON_DROWNING = 1 << 8,
	ICON_FREEZING = 1 << 9,
	ICON_DAZZLED = 1 << 10,
	ICON_CURSED = 1 << 11,
	ICON_PARTY_BUFF = 1 << 12,
	ICON_REDSWORDS = 1 << 13,
	ICON_PIGEON = 1 << 14,
};

enum WeaponType_t : uint8_t {
	WEAPON_NONE,
	WEAPON_SWORD,
	WEAPON_CLUB,
	WEAPON_AXE,
	WEAPON_SHIELD,
	WEAPON_DISTANCE,
	WEAPON_WAND,
	WEAPON_AMMO,
	WEAPON_QUIVER,
};

enum Ammo_t : uint8_t {
	AMMO_NONE,
	AMMO_BOLT,
	AMMO_ARROW,
	AMMO_SPEAR,
	AMMO_THROWINGSTAR,
	AMMO_THROWINGKNIFE,
	AMMO_STONE,
	AMMO_SNOWBALL,
};

enum WeaponAction_t : uint8_t {
	WEAPONACTION_NONE,
	WEAPONACTION_REMOVECOUNT,
	WEAPONACTION_REMOVECHARGE,
	WEAPONACTION_MOVE,
};

enum WieldInfo_t {
	WIELDINFO_NONE = 0 << 0,
	WIELDINFO_LEVEL = 1 << 0,
	WIELDINFO_MAGLV = 1 << 1,
	WIELDINFO_VOCREQ = 1 << 2,
	WIELDINFO_PREMIUM = 1 << 3,
};

enum Skulls_t : uint8_t {
	SKULL_NONE = 0,
	SKULL_YELLOW = 1,
	SKULL_GREEN = 2,
	SKULL_WHITE = 3,
	SKULL_RED = 4,
	SKULL_BLACK = 5
};

enum PartyShields_t : uint8_t {
	SHIELD_NONE = 0,
	SHIELD_WHITEYELLOW = 1,
	SHIELD_WHITEBLUE = 2,
	SHIELD_BLUE = 3,
	SHIELD_YELLOW = 4,
	SHIELD_BLUE_SHAREDEXP = 5,
	SHIELD_YELLOW_SHAREDEXP = 6,
	SHIELD_BLUE_NOSHAREDEXP_BLINK = 7,
	SHIELD_YELLOW_NOSHAREDEXP_BLINK = 8,
	SHIELD_BLUE_NOSHAREDEXP = 9,
	SHIELD_YELLOW_NOSHAREDEXP = 10,
};

enum GuildEmblems_t : uint8_t {
	GUILDEMBLEM_NONE = 0,
	GUILDEMBLEM_ALLY = 1,
	GUILDEMBLEM_ENEMY = 2,
	GUILDEMBLEM_NEUTRAL = 3
};

enum item_t : uint16_t {
	ITEM_FIREFIELD_PVP_FULL = 2118,
	ITEM_FIREFIELD_PVP_MEDIUM = 2119,
	ITEM_FIREFIELD_PVP_SMALL = 2120,
	ITEM_FIREFIELD_PERSISTENT_FULL = 2123,
	ITEM_FIREFIELD_PERSISTENT_MEDIUM = 2124,
	ITEM_FIREFIELD_PERSISTENT_SMALL = 2125,
	ITEM_FIREFIELD_NOPVP = 21465,

	ITEM_POISONFIELD_PVP = 1490,
	ITEM_POISONFIELD_PERSISTENT = 1496,
	ITEM_POISONFIELD_NOPVP = 1503,

	ITEM_ENERGYFIELD_PVP = 2122,
	ITEM_ENERGYFIELD_PERSISTENT = 2126,
	ITEM_ENERGYFIELD_NOPVP = 2135,

	ITEM_MAGICWALL = 2129,
	ITEM_MAGICWALL_PERSISTENT = 2128,
	ITEM_MAGICWALL_SAFE = 10181,

	ITEM_WILDGROWTH = 2130,
	ITEM_WILDGROWTH_PERSISTENT = 3635,
	ITEM_WILDGROWTH_SAFE = 10182,

	ITEM_BAG = 2853,
	ITEM_BACKPACK = 21411,

	ITEM_GOLD_COIN = 3031,
	ITEM_PLATINUM_COIN = 3035,
	ITEM_CRYSTAL_COIN = 3043,
	ITEM_INGOT_DIAMOND = 40716,
	ITEM_INGOT_PLATINUM = 40717,

	ITEM_DEPOT = 3502,
	ITEM_LOCKER = 3497,
	ITEM_INBOX = 12902,
	ITEM_MARKET = 12903,
	ITEM_LOOT_POUCH = 40850,
	ITEM_SUPPLY_STASH = 28750,
	
	// move to separate enum class?
	
	ITEM_DEPOT_BOX_I = 22797,
	ITEM_DEPOT_BOX_II = 22798,
	ITEM_DEPOT_BOX_III = 22799,
	ITEM_DEPOT_BOX_IV = 22800,
	ITEM_DEPOT_BOX_V = 22801,
	ITEM_DEPOT_BOX_VI = 22802,
	ITEM_DEPOT_BOX_VII = 22803,
	ITEM_DEPOT_BOX_VIII = 22804,
	ITEM_DEPOT_BOX_IX = 22805,
	ITEM_DEPOT_BOX_X = 22806,
	ITEM_DEPOT_BOX_XI = 22807,
	ITEM_DEPOT_BOX_XII = 22808,
	ITEM_DEPOT_BOX_XIII = 22809,
	ITEM_DEPOT_BOX_XIV = 22810,
	ITEM_DEPOT_BOX_XV = 22811,
	ITEM_DEPOT_BOX_XVI = 22812,
	ITEM_DEPOT_BOX_XVII = 22813,
	ITEM_DEPOT_BOX_XVIII = 31915,
	ITEM_DEPOT_BOX_XIX = 39723,
	ITEM_DEPOT_BOX_XX = 39724,
	
	ITEM_REWARD_CONTAINER = 19202, // Bag of Loot
	ITEM_REWARD_CHEST = 19250, // Chest of Reward Boss

	ITEM_MALE_CORPSE = 4240,
	ITEM_FEMALE_CORPSE = 4247,

	ITEM_FULLSPLASH = 2886,
	ITEM_SMALLSPLASH = 2889,

	ITEM_PARCEL = 3503,
	ITEM_LETTER = 3505,
	ITEM_LETTER_STAMPED = 3506,
	ITEM_LABEL = 3507,

	ITEM_AMULETOFLOSS = 3057,

	ITEM_DOCUMENT_RO = 2834, //read-only
};

enum PlayerFlags : uint64_t {
	PlayerFlag_CannotUseCombat = 1 << 0,
	PlayerFlag_CannotAttackPlayer = 1 << 1,
	PlayerFlag_CannotAttackMonster = 1 << 2,
	PlayerFlag_CannotBeAttacked = 1 << 3,
	PlayerFlag_CanConvinceAll = 1 << 4,
	PlayerFlag_CanSummonAll = 1 << 5,
	PlayerFlag_CanIllusionAll = 1 << 6,
	PlayerFlag_CanSenseInvisibility = 1 << 7,
	PlayerFlag_IgnoredByMonsters = 1 << 8,
	PlayerFlag_NotGainInFight = 1 << 9,
	PlayerFlag_HasInfiniteMana = 1 << 10,
	PlayerFlag_HasInfiniteSoul = 1 << 11,
	PlayerFlag_HasNoExhaustion = 1 << 12,
	PlayerFlag_CannotUseSpells = 1 << 13,
	PlayerFlag_CannotPickupItem = 1 << 14,
	PlayerFlag_CanAlwaysLogin = 1 << 15,
	PlayerFlag_CanBroadcast = 1 << 16,
	PlayerFlag_CanEditHouses = 1 << 17,
	PlayerFlag_CannotBeBanned = 1 << 18,
	PlayerFlag_CannotBePushed = 1 << 19,
	PlayerFlag_HasInfiniteCapacity = 1 << 20,
	PlayerFlag_CanPushAllCreatures = 1 << 21,
	PlayerFlag_CanTalkRedPrivate = 1 << 22,
	PlayerFlag_CanTalkRedChannel = 1 << 23,
	PlayerFlag_TalkOrangeHelpChannel = 1 << 24,
	PlayerFlag_NotGainExperience = 1 << 25,
	PlayerFlag_NotGainMana = 1 << 26,
	PlayerFlag_NotGainHealth = 1 << 27,
	PlayerFlag_NotGainSkill = 1 << 28,
	PlayerFlag_SetMaxSpeed = 1 << 29,
	PlayerFlag_SpecialVIP = 1 << 30,
	PlayerFlag_NotGenerateLoot = static_cast<uint64_t>(1) << 31,
	PlayerFlag_CanTalkRedChannelAnonymous = static_cast<uint64_t>(1) << 32,
	PlayerFlag_IgnoreProtectionZone = static_cast<uint64_t>(1) << 33,
	PlayerFlag_IgnoreSpellCheck = static_cast<uint64_t>(1) << 34,
	PlayerFlag_IgnoreWeaponCheck = static_cast<uint64_t>(1) << 35,
	PlayerFlag_CannotBeMuted = static_cast<uint64_t>(1) << 36,
	PlayerFlag_IsAlwaysPremium = static_cast<uint64_t>(1) << 37,
	PlayerFlag_IgnoreYellCheck = static_cast<uint64_t>(1) << 38,
	PlayerFlag_IgnoreSendPrivateCheck = static_cast<uint64_t>(1) << 39,
	PlayerFlag_CanMoveAllThings = static_cast<uint64_t>(1) << 40,
};

enum ReloadTypes_t : uint8_t  {
	RELOAD_TYPE_ALL,
	RELOAD_TYPE_ACTIONS,
	RELOAD_TYPE_CHAT,
	RELOAD_TYPE_CONFIG,
	RELOAD_TYPE_CREATURESCRIPTS,
	RELOAD_TYPE_EVENTS,
	RELOAD_TYPE_GLOBAL,
	RELOAD_TYPE_GLOBALEVENTS,
	RELOAD_TYPE_ITEMS,
	RELOAD_TYPE_MOUNTS,
	RELOAD_TYPE_MONSTERS,
	RELOAD_TYPE_MOVEMENTS,
	RELOAD_TYPE_NPCS,
	RELOAD_TYPE_QUESTS,
	RELOAD_TYPE_SCRIPTS,
	RELOAD_TYPE_SPELLS,
	RELOAD_TYPE_TALKACTIONS,
	RELOAD_TYPE_WEAPONS,
};

// OTCv8 features (from src/client/const.h)
enum GameFeature {
	GameProtocolChecksum = 1,
	GameAccountNames = 2,
	GameChallengeOnLogin = 3,
	GamePenalityOnDeath = 4,
	GameNameOnNpcTrade = 5,
	GameDoubleFreeCapacity = 6,
	GameDoubleExperience = 7,
	GameTotalCapacity = 8,
	GameSkillsBase = 9,
	GamePlayerRegenerationTime = 10,
	GameChannelPlayerList = 11,
	GamePlayerMounts = 12,
	GameEnvironmentEffect = 13,
	GameCreatureEmblems = 14,
	GameItemAnimationPhase = 15,
	GameMagicEffectU16 = 16,
	GamePlayerMarket = 17,
	GameSpritesU32 = 18,
	GameTileAddThingWithStackpos = 19,
	GameOfflineTrainingTime = 20,
	GamePurseSlot = 21,
	GameFormatCreatureName = 22,
	GameSpellList = 23,
	GameClientPing = 24,
	GameExtendedClientPing = 25,
	GameDoubleHealth = 28,
	GameDoubleSkills = 29,
	GameChangeMapAwareRange = 30,
	GameMapMovePosition = 31,
	GameAttackSeq = 32,
	GameBlueNpcNameColor = 33,
	GameDiagonalAnimatedText = 34,
	GameLoginPending = 35,
	GameNewSpeedLaw = 36,
	GameForceFirstAutoWalkStep = 37,
	GameMinimapRemove = 38,
	GameDoubleShopSellAmount = 39,
	GameContainerPagination = 40,
	GameThingMarks = 41,
	GameLooktypeU16 = 42,
	GamePlayerStamina = 43,
	GamePlayerAddons = 44,
	GameMessageStatements = 45,
	GameMessageLevel = 46,
	GameNewFluids = 47,
	GamePlayerStateU16 = 48,
	GameNewOutfitProtocol = 49,
	GamePVPMode = 50,
	GameWritableDate = 51,
	GameAdditionalVipInfo = 52,
	GameBaseSkillU16 = 53,
	GameCreatureIcons = 54,
	GameHideNpcNames = 55,
	GameSpritesAlphaChannel = 56,
	GamePremiumExpiration = 57,
	GameBrowseField = 58,
	GameEnhancedAnimations = 59,
	GameOGLInformation = 60,
	GameMessageSizeCheck = 61,
	GamePreviewState = 62,
	GameLoginPacketEncryption = 63,
	GameClientVersion = 64,
	GameContentRevision = 65,
	GameExperienceBonus = 66,
	GameAuthenticator = 67,
	GameUnjustifiedPoints = 68,
	GameSessionKey = 69,
	GameDeathType = 70,
	GameIdleAnimations = 71,
	GameKeepUnawareTiles = 72,
	GameIngameStore = 73,
	GameIngameStoreHighlights = 74,
	GameIngameStoreServiceType = 75,
	GameAdditionalSkills = 76,
	GameDistanceEffectU16 = 77,
	GamePrey = 78,
	GameDoubleMagicLevel = 79,

	GameExtendedOpcode = 80,
	GameMinimapLimitedToSingleFloor = 81,
	GameSendWorldName = 82,

	GameDoubleLevel = 83,
	GameDoubleSoul = 84,
	GameDoublePlayerGoodsMoney = 85,
	GameCreatureWalkthrough = 86,
	GameDoubleTradeMoney = 87,
	GameSequencedPackets = 88,
	GameTibia12Protocol = 89,

	// 90-99 otclientv8 features
	GameNewWalking = 90,
	GameSlowerManualWalking = 91,

	GameItemTooltip = 93,

	GameBot = 95,
	GameBiggerMapCache = 96,
	GameForceLight = 97,
	GameNoDebug = 98,
	GameBotProtection = 99,

	// Custom features for customer
	GameFasterAnimations = 101,
	GameCenteredOutfits = 102,
	GameSendIdentifiers = 103,
	GameWingsAndAura = 104,
	GamePlayerStateU32 = 105,
	GameOutfitShaders = 106,

	// advanced features
	GamePacketSizeU32 = 110,
	GamePacketCompression = 111,

	LastGameFeature = 120
};

static constexpr int32_t CHANNEL_GUILD = 0x00;
static constexpr int32_t CHANNEL_PARTY = 0x01;
static constexpr int32_t CHANNEL_PRIVATE = 0xFFFF;
static constexpr int32_t CHANNEL_CAST = 0xFF;

//Reserved player storage key ranges;
//[10000000 - 20000000];
static constexpr int32_t PSTRG_RESERVED_RANGE_START = 10000000;
static constexpr int32_t PSTRG_RESERVED_RANGE_SIZE = 10000000;

#define IS_IN_KEYRANGE(key, range) (key >= PSTRG_##range##_START && ((key - PSTRG_##range##_START) <= PSTRG_##range##_SIZE))

#endif
