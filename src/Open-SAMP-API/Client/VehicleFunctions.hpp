#pragma once
#include "Client.hpp"

namespace Client
{
	namespace VehicleFunctions
	{
		EXPORT unsigned int GetVehiclePointer();
		
		EXPORT int GetVehicleSpeed(float factor);
		EXPORT float GetVehicleHealth();
		EXPORT int GetVehicleModelId();
		EXPORT int GetVehicleModelName(char* &name, int max_len);
		EXPORT int GetVehicleModelNameById(int vehicleID, char* &name, int max_len);
		EXPORT int GetVehicleType();
		EXPORT int GetVehicleFreeSeats(int &seatFL, int &seatFR, int &seatRL, int &seatRR);
		EXPORT int GetVehicleFirstColor();
		EXPORT int GetVehicleSecondColor();
		EXPORT int GetVehicleColor(int &color1, int &color2);
		
		EXPORT int IsVehicleSeatUsed(int seat);
		EXPORT int IsVehicleLocked();
		EXPORT int IsVehicleHornEnabled();
		EXPORT int IsVehicleSirenEnabled();
		EXPORT int IsVehicleAlternateSirenEnabled();
		EXPORT int IsVehicleEngineEnabled();
		EXPORT int IsVehicleLightEnabled();
		EXPORT int IsVehicleCar();
		EXPORT int IsVehiclePlane();
		EXPORT int IsVehicleBoat();
		EXPORT int IsVehicleTrain();
		EXPORT int IsVehicleBike();
	}
}