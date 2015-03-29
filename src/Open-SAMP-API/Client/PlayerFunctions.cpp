#include "PlayerFunctions.hpp"
#include "MemoryFunctions.hpp"
#include "VehicleFunctions.hpp"
#include <Shared/PipeMessages.hpp>

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

EXPORT int Client::PlayerFunctions::IsPlayerInAnyVehicle()
{
	return (int)(VehicleFunctions::GetVehiclePointer() != 0);
}

