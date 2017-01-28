#include "WeaponFunctions.hpp"
#include <Shared/PipeMessages.hpp>
#include "PlayerFunctions.hpp"
#include "MemoryFunctions.hpp"
#include <memory>

const char* weapNameArray[] = { "Fist", "Brass Knuckles", "Golf Club", "Nightstick", "Knife", // 0-4
"Baseball Bat", "Shovel", "Pool Cue", "Katana", "Chainsaw", // 5 - 9
"Purple Dildo", "Dildo", "Vibrator", "Silver Vibrator", "Flowers", // 10 - 14
"Cane", "Grenade", "Tear Gas", "Molotov Cocktail", "", // 15 - 19
"", "", "9mm", "Silenced 9mm", "Desert Eagle", // 20 - 24
"Shotgun", "Sawnoff Shotgun", "Combat Shotgun", "Micro SMG/Uzi", "MP5", // 25 - 29
"AK-47", "M4", "Tec-9", "Country Rifle", "Sniper Rifle",// 30 - 24
"RPG", "Heatseeker RPG", "Flamethrower", "Minigun", "Satchel Charge",// 35 - 39
"Detonator", "Spraycan", "Fire Extinguisher", "Camera", "Night Vision Googles",// 40 - 44
"Thermal Googles", "Parachute",// 45 - 46
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
 
std::shared_ptr<PedWeaponSlot> GetPlayerWeaponSlotStruct(int slot)
{
	auto pws = std::make_shared<PedWeaponSlot>();
	auto cped = Client::PlayerFunctions::GetPlayerCPed();
	if (cped == NULL)
		return nullptr;

	if (Client::MemoryFunctions::ReadMemory(cped + 0x5A0 + (slot * 0x1C), sizeof(PedWeaponSlot), pws.get()) == 0)
		return nullptr;
	return pws;
	
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponID()
{
	DWORD cped = PlayerFunctions::GetPlayerCPed();
	if (cped == NULL)
		return -1;

	int weaponType = GetPlayerWeaponType();
	if (weaponType == -1)
		return -1;

	int weapon = 0;
	if (MemoryFunctions::ReadMemory(cped + 0x5A0 + (weaponType * 0x1C), 4, &weapon) != 4)
		return -1;

	return weapon;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponType()
{
	DWORD cped = PlayerFunctions::GetPlayerCPed();
	if (cped == NULL)
		return -1;

	int weaponType = 0;
	if (MemoryFunctions::ReadMemory(cped + 0x718, 1, &weaponType) != 1)
		return -1;

	return weaponType;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponSlot()
{
	int dwWeaponSlot = 0;
	const int cped = PlayerFunctions::GetPlayerCPed();
	if (cped == NULL)
		return -1;

	if (MemoryFunctions::ReadMemory(cped + 0x718, 1, &dwWeaponSlot) != 1)
		return -1;

	return dwWeaponSlot;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponName(int dwWeapSlot, char* &_szWeapName, int max_len)
{
	auto pws = GetPlayerWeaponSlotStruct(dwWeapSlot);
	if (pws == nullptr)
		return 0;

	if (pws->type < 0 || pws->type >= ARRAYSIZE(weapNameArray))
		return 0;

	const char *ptr = weapNameArray[pws->type];
	strcpy_s(_szWeapName, max_len, ptr);
	return 1;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponClip(int dwWeapSlot)
{
	auto pws = GetPlayerWeaponSlotStruct(dwWeapSlot);
	if (pws == nullptr)
		return -1;

	for (int i = 0; i < ARRAYSIZE(weaponIdNoClip); i++)
		if (weaponIdNoClip[i] == pws->type)
			return 0;

	return pws->ammoInClip;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponTotalClip(int dwWeapSlot)
{
	auto pws = GetPlayerWeaponSlotStruct(dwWeapSlot);
	if (pws == nullptr)
		return -1;

	for (int i = 0; i < ARRAYSIZE(weaponIdNoClip); i++)
		if (weaponIdNoClip[i] == pws->type)
			return 0;

	return pws->ammoRemaining;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponState()
{
	auto slot = GetPlayerWeaponSlot();
	if (slot == -1)
		return -1;

	auto pws = GetPlayerWeaponSlotStruct(slot);
	if (pws == nullptr)
		return -1;

	return pws->state;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponAmmo(int weaponType)
{
	DWORD pedPtr = PlayerFunctions::GetPlayerCPed();
	if (pedPtr == NULL)
		return -1;

	int ammo = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x5A0 + (weaponType * 0x1C) + 0x0C, 4, &ammo) != 4)
		return -1;

	return ammo;
}

EXPORT int Client::WeaponFunctions::GetPlayerWeaponAmmoInClip(int weaponType)
{
	DWORD pedPtr = PlayerFunctions::GetPlayerCPed();
	if (pedPtr == NULL)
		return -1;

	int ammo = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x5A0 + (weaponType * 0x1C) + 0x08, 4, &ammo) != 4)
		return -1;

	return ammo;
}
