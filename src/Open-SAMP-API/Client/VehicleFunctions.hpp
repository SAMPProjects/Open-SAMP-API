#pragma once
#include "Client.hpp"

namespace Client
{
	namespace VehicleFunctions
	{
		EXPORT unsigned int GetVehiclePointer();
		EXPORT int GetVehicleSpeed(float factor);
		EXPORT float GetVehicleHealth();
		EXPORT short GetVehicleTypeId();
	}
}