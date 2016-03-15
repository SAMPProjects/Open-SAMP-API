#include "WeaponFunctions.hpp"
#include <Shared/PipeMessages.hpp>
#include "PlayerFunctions.hpp"
#include "MemoryFunctions.hpp"

const char* weapNameArray[] = { "Faust", "Schlagring", "Golfschläger", "Schlagstock", "Messer", // 0-4
"Baseballschläger", "Schaufel", "Billard cue", "Katana", "Kettensäge", // 5 - 9
"Double Dildo", "Dildo", "Vibrator", "Silberner Vibrator", "Blumen", // 10 - 14
"Gehstock", "Granate", "Tränengas", "Molotov Cocktail", "", // 15 - 19
"", "", "9mm", "Schallgedämpfte 9mm", "Desert Eagle", // 20 - 24
"Schrotflinte", "Abgesägte Schrotflinte", "Gefechtsschrotflinte", "Micro SMG", "MP5", // 25 - 29
"AK-47", "M4", "Tec-9", "Country Rifle", "Sniper Rifle",// 30 - 24
"Panzerfaust", "Automatische Panzerfaust", "Flammenwerfer", "Minigun", "Rucksackladung",// 35 - 39
"Sprengzünder", "Sprühdose", "Feuerlöscher", "Kamera", "Nachtsichtgerät",// 40 - 44
"Wärmebildkamera", "Fallschirm",// 45 - 46
};

const int weaponIdNoClip[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 40, 44, 45, 46 };

struct PedWeaponSlot
{
	unsigned long type;
	unsigned long state;
	unsigned long ammoInClip;
	unsigned long ammoRemaining;
	float unknown;
	double unknown2;
};

PedWeaponSlot GetPlayerWeaponSlotStruct(int slot)
{
	PedWeaponSlot pws;
	Client::MemoryFunctions::ReadMemory(Client::PlayerFunctions::GetPlayerCPed() + 0x5A0 + (slot * 0x1C), sizeof(PedWeaponSlot), &pws);
	return pws;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponSlot()
{
	SERVER_CHECK(0)

	int dwWeaponSlot = 0;
	const int cped = PlayerFunctions::GetPlayerCPed();
	if (cped == 0)
		return 0;

	MemoryFunctions::ReadMemory(cped + 0x718, 1, &dwWeaponSlot);
	return dwWeaponSlot;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponId(int dwWeapSlot)
{
	SERVER_CHECK(0)
	return GetPlayerWeaponSlotStruct(dwWeapSlot).type;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponName(int dwWeapSlot, char* &_szWeapName, int max_len)
{
	SERVER_CHECK(0)
	strcpy_s(_szWeapName, max_len, weapNameArray[GetPlayerWeaponId(dwWeapSlot)]);
	return 1;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponClip(int dwWeapSlot)
{
	SERVER_CHECK(0)
	PedWeaponSlot pws = GetPlayerWeaponSlotStruct(dwWeapSlot);

	for (int i = 0; i < ARRAYSIZE(weaponIdNoClip); i++)
		if (weaponIdNoClip[i] == pws.type)
			return 0;

	return pws.ammoInClip;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponTotalClip(int dwWeapSlot)
{
	SERVER_CHECK(0)
	PedWeaponSlot pws = GetPlayerWeaponSlotStruct(dwWeapSlot);

	for (int i = 0; i < ARRAYSIZE(weaponIdNoClip); i++)
		if (weaponIdNoClip[i] == pws.type)
			return 0;

	return pws.ammoRemaining;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponState()
{
	SERVER_CHECK(0)
	return GetPlayerWeaponSlotStruct(GetPlayerWeaponSlot()).state;
}
