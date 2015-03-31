#pragma once
#include "Client.hpp"

namespace Client
{
	namespace PlayerFunctions
	{
		EXPORT int GetPlayerHealth();
		EXPORT int GetPlayerArmor();
		EXPORT int IsPlayerInAnyVehicle();
		EXPORT int IsPlayerInInterior();
		EXPORT int GetPlayerX(float &posX);
		EXPORT int GetPlayerY(float &posY);
		EXPORT int GetPlayerZ(float &posZ);
		EXPORT int GetPlayerPosition(float &posX, float &posY, float &posZ);
		EXPORT int IsPlayerInRange2D(float posX, float posY, float radius);
		EXPORT int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);
	}
}