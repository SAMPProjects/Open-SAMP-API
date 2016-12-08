#include "PlayerFunctions.hpp"
#include "MemoryFunctions.hpp"
#include "VehicleFunctions.hpp"
#include "GTAStructs.hpp"
#include <Shared/PipeMessages.hpp>


EXPORT int Client::PlayerFunctions::GetPlayerCPed()
{
	DWORD pedPtr = 0;
	MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr);
	return pedPtr;
}

EXPORT int Client::PlayerFunctions::GetPlayerHealth()
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return -1;

	float health = 0.0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x540, 4, &health) != 4)
		return -1;

	return (int)health;
}

EXPORT int Client::PlayerFunctions::GetPlayerArmor()
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return -1;

	float armor = 0.0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x548, 4, &armor) != 4)
		return -1;

	return (int)armor;
}

EXPORT int Client::PlayerFunctions::GetPlayerMoney()
{
	DWORD money = 0;
	if (MemoryFunctions::ReadMemory(0xB7CE50, 4, &money) != 4)
		return -1;

	return (int)money;
}

EXPORT int Client::PlayerFunctions::GetPlayerSkinID()
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return -1;

	int skin = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x22, 2, &skin) != 2)
		return -1;

	return (int)skin;
}

EXPORT int Client::PlayerFunctions::IsPlayerInAnyVehicle()
{
	return (int)(VehicleFunctions::GetVehiclePointer() != 0);
}

EXPORT int Client::PlayerFunctions::IsPlayerDriver()
{
	DWORD dwVehiclePtr = VehicleFunctions::GetVehiclePointer();
	if (!dwVehiclePtr)
		return 0;

	DWORD dwPlayerPtr = PlayerFunctions::GetPlayerCPed();
	DWORD dwDriverPtr = 0;

	MemoryFunctions::ReadMemory(dwVehiclePtr + 0x460, 4, &dwDriverPtr);
	if (dwPlayerPtr == dwDriverPtr)
		return 1;

	return 0;
}

EXPORT int Client::PlayerFunctions::IsPlayerPassenger()
{
	if (!IsPlayerInAnyVehicle())
		return 0;

	return !IsPlayerDriver();
}

EXPORT int Client::PlayerFunctions::IsPlayerInInterior()
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return 0;

	int interior;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x2F, 1, &interior) != 1)
		return 0;

	return (int)(interior != 0);
}

EXPORT int Client::PlayerFunctions::GetPlayerX(float &posX)
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return 0;

	DWORD matrixPtr = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x14, 4, &matrixPtr) != 4)
		return 0;

	DWORD positionPtr = 0;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x30, 4, &positionPtr) != 4)
		return 0;

	float position = 0.0f;
	if (MemoryFunctions::ReadMemory(positionPtr, 4, &position) != 4)
		return 0;

	posX = position;
	return 1;
}

EXPORT int Client::PlayerFunctions::GetPlayerY(float &posY)
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return 0;

	DWORD matrixPtr = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x14, 4, &matrixPtr) != 4)
		return 0;

	DWORD positionPtr = 0;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x34, 4, &positionPtr) != 4)
		return 0;

	float position = 0.0f;
	if (MemoryFunctions::ReadMemory(positionPtr, 4, &position) != 4)
		return 0;

	posY = position;
	return 1;
}

EXPORT int Client::PlayerFunctions::GetPlayerZ(float &posZ)
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return 0;

	DWORD matrixPtr = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x14, 4, &matrixPtr) != 4)
		return 0;

	DWORD positionPtr = 0;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x38, 4, &positionPtr) != 4)
		return 0;

	float position = 0.0f;
	if (MemoryFunctions::ReadMemory(positionPtr, 4, &position) != 4)
		return 0;

	posZ = position;
	return 1;
}

EXPORT int Client::PlayerFunctions::GetPlayerPosition(float &posX, float &posY, float &posZ)
{
	DWORD pedPtr = 0;
	if (MemoryFunctions::ReadMemory(0xB6F5F0, 4, &pedPtr) != 4)
		return 0;

	DWORD matrixPtr = 0;
	if (MemoryFunctions::ReadMemory(pedPtr + 0x14, 4, &matrixPtr) != 4)
		return 0;

	DWORD positionPtr = 0;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x34, 4, &positionPtr) != 4)
		return 0;


	float positionX = 0.0f;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x30, 4, &positionX) != 4)
		return 0;

	float positionY = 0.0f;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x34, 4, &positionY) != 4)
		return 0;

	float positionZ = 0.0f;
	if (MemoryFunctions::ReadMemory(matrixPtr + 0x38, 4, &positionZ) != 4)
		return 0;

	posX = positionX;
	posY = positionY;
	posZ = positionZ;
	return 1;
}

EXPORT int Client::PlayerFunctions::IsPlayerInRange2D(float posX, float posY, float radius)
{
	float x, y = 0;
	if (!GetPlayerX(x) || !GetPlayerY(y))
		return 0;

	x -= posX;
	y -= posY;

	if ((x < radius) && (x > -radius) && (y < radius) && (y > -radius))
		return 1;

	return 0;
}

EXPORT int Client::PlayerFunctions::IsPlayerInRange3D(float posX, float posY, float posZ, float radius)
{
	float x, y, z = 0.0f;
	if (!GetPlayerPosition(x, y, z))
		return 0;

	x -= posX;
	y -= posY;
	z -= posZ;

	if ((x < radius) && (x > -radius) && (y < radius) && (y > -radius) && (z < radius) && (z > -radius))
		return 1;

	return 0;
}

EXPORT int Client::PlayerFunctions::GetCityName(char* &cityName, int max_len)
{
	float x, y, z = 0.0f;
	if (!GetPlayerPosition(x, y, z))
		return 0;

	for (int i = 0; i < ARRAYSIZE(GTAStructs::cities); i++)
	{
		const GTAStructs::City& cCity = GTAStructs::cities[i];
		if (x > cCity.minX && y > cCity.minY && z > cCity.minZ && x < cCity.maxX && y < cCity.maxY && z < cCity.maxZ)
		{
			strcpy_s(cityName, max_len, cCity.name.c_str());
			return 1;
		}
	}

	return 0;
}

EXPORT int Client::PlayerFunctions::GetZoneName(char* &zoneName, int max_len)
{
	float x, y, z = 0.0f;
	if (!GetPlayerPosition(x, y, z))
		return 0;

	for (int i = 0; i < ARRAYSIZE(GTAStructs::zones); i++)
	{
		const GTAStructs::Zone& cZone = GTAStructs::zones[i];
		if (x > cZone.minX && y > cZone.minY && z > cZone.minZ && x < cZone.maxX && y < cZone.maxY && z < cZone.maxZ)
		{
			strcpy_s(zoneName, max_len, cZone.name.c_str());
			return 1;
		}
	}

	return 0;
}
