#include "VehicleFunctions.hpp"
#include "MemoryFunctions.hpp"
#include "PlayerFunctions.hpp"
#include "GTAStructs.hpp"
#include <Shared/PipeMessages.hpp>

EXPORT unsigned int Client::VehicleFunctions::GetVehiclePointer()
{
	unsigned int ptr = 0;
	if (MemoryFunctions::ReadMemory(0xBA18FC, 4, &ptr) != 4)
		return 0;

	return ptr;
}

EXPORT int Client::VehicleFunctions::GetVehicleSpeed(float factor)
{
	DWORD ptr = GetVehiclePointer();
	if (ptr == NULL)
		return -1;

	float x = 0.0, y = 0.0, z = 0.0;
	if (MemoryFunctions::ReadMemory(ptr + 0x44, 4, &x) != 4)
		return -1;

	if (MemoryFunctions::ReadMemory(ptr + 0x48, 4, &y) != 4)
		return -1;

	if (MemoryFunctions::ReadMemory(ptr + 0x4C, 4, &z) != 4)
		return -1;

	float speed = sqrt((x*x) + (y*y) + (z*z)) * (float)100.0 * factor;
	return (int)speed;
}

EXPORT float Client::VehicleFunctions::GetVehicleHealth()
{
	DWORD ptr = GetVehiclePointer();
	if (ptr == NULL)
		return -1.0f;

	float health = 0.0f;
	if (MemoryFunctions::ReadMemory(ptr + 0x4C0, 4, &health) != 4)
		return -1.0f;

	return health;
}

EXPORT int Client::VehicleFunctions::GetVehicleModelId()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwVehicleId = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x22, 2, (char *)&dwVehicleId);
	return dwVehicleId;
}

EXPORT int Client::VehicleFunctions::GetVehicleModelName(char* &name, int max_len)
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	strcpy_s(name, max_len, GTAStructs::vehicles[GetVehicleModelId() - 400].c_str());
	return 1;
}

EXPORT int Client::VehicleFunctions::GetVehicleModelNameById(int vehicleID, char* &name, int max_len)
{
	strcpy_s(name, max_len, GTAStructs::vehicles[vehicleID - 400].c_str());
	return 1;
}

EXPORT int Client::VehicleFunctions::GetVehicleType()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return -1;

	int dwVehicleType = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x590, 1, (char *)&dwVehicleType);
	return dwVehicleType;
}

EXPORT int Client::VehicleFunctions::GetVehicleFreeSeats(int &seatFL, int &seatFR, int &seatRL, int &seatRR)
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	seatFL = IsVehicleSeatUsed(1);
	seatFR = IsVehicleSeatUsed(2);
	seatRL = IsVehicleSeatUsed(3);
	seatRR = IsVehicleSeatUsed(4);
	return 1;
}

EXPORT INT Client::VehicleFunctions::GetVehicleFirstColor()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return -1;

	int dwColor = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x434, 1, (char *)&dwColor);
	return dwColor;
}

EXPORT INT Client::VehicleFunctions::GetVehicleSecondColor()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return -1;

	int dwColor = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x435, 1, (char *)&dwColor);
	return dwColor;
}

EXPORT int Client::VehicleFunctions::GetVehicleColor(int &color1, int &color2)
{
	color1 = -1;
	color2 = -1;

	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	color1 = GetVehicleFirstColor();
	color2 = GetVehicleSecondColor();
	return 1;
}

EXPORT int Client::VehicleFunctions::IsVehicleSeatUsed(int seat)
{
	DWORD dwVehiclePtr = GetVehiclePointer();
	if (!dwVehiclePtr)
		return 0;

	DWORD dwSeatPointer;
	seat = seat - 1;
	if (seat >= 0 && seat <= 8)
		MemoryFunctions::ReadMemory(dwVehiclePtr + 0x460 + seat * 4, 4, (char *)&dwSeatPointer);
	else
		return 0;

	if (dwSeatPointer)
		return 1;

	return 0;
}

EXPORT int Client::VehicleFunctions::IsVehicleLocked()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwDoorLockState = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x4F8, 4, (char *)&dwDoorLockState);
	
	return (dwDoorLockState >> 1) & 1;
}

EXPORT int Client::VehicleFunctions::IsVehicleHornEnabled()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwHornState = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x514, 1, (char *)&dwHornState);
	return dwHornState;
}

EXPORT int Client::VehicleFunctions::IsVehicleSirenEnabled()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwSirenState = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x42D, 1, (char *)&dwSirenState);

	return (dwSirenState >> 7) & 1;
}

EXPORT int Client::VehicleFunctions::IsVehicleAlternateSirenEnabled()
{
	return IsVehicleHornEnabled() && IsVehicleSirenEnabled();
}

EXPORT int Client::VehicleFunctions::IsVehicleEngineEnabled()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwEngineState = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x428, 1, (char *)&dwEngineState);

	return (dwEngineState >> 4) & 1;
}

EXPORT int Client::VehicleFunctions::IsVehicleLightEnabled()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	int dwLightState = 0;
	MemoryFunctions::ReadMemory(GetVehiclePointer() + 0x4A8, 1, (char *)&dwLightState);

	return !((dwLightState >> 3) & 1);
}

EXPORT int Client::VehicleFunctions::IsVehicleCar()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	if (GetVehicleType() != 0)
		return 0;

	for (int i = 0; i < ARRAYSIZE(GTAStructs::planeIDs); i++)
		if (GetVehicleModelId() == GTAStructs::planeIDs[i])
			return 0;

	return 1;
}

EXPORT int Client::VehicleFunctions::IsVehiclePlane()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	if (GetVehicleType() != 0)
		return 0;

	for (int i = 0; i < ARRAYSIZE(GTAStructs::planeIDs); i++)
		if (GetVehicleModelId() == GTAStructs::planeIDs[i])
			return 1;

	return 0;
}

EXPORT int Client::VehicleFunctions::IsVehicleBoat()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	if (GetVehicleType() != 5)
		return 0;

	return GetVehicleType() == 5;
}

EXPORT int Client::VehicleFunctions::IsVehicleTrain()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	return GetVehicleType() == 6;
}

EXPORT int Client::VehicleFunctions::IsVehicleBike()
{
	if (!PlayerFunctions::IsPlayerInAnyVehicle())
		return 0;

	return GetVehicleType() == 9;
}