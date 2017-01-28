#pragma once
#include "Client.hpp"

namespace Client
{
	namespace PlayerFunctions
	{
		EXPORT int GetPlayerCPed();
		EXPORT int GetPlayerHealth();
		EXPORT int GetPlayerArmor();
		EXPORT int GetPlayerMoney();
		EXPORT int GetPlayerSkinID();
		EXPORT int GetPlayerInterior();
		EXPORT int IsPlayerInAnyVehicle();
		EXPORT int IsPlayerDriver();
		EXPORT int IsPlayerPassenger();
		EXPORT int IsPlayerInInterior();
		EXPORT int GetPlayerX(float &posX);
		EXPORT int GetPlayerY(float &posY);
		EXPORT int GetPlayerZ(float &posZ);
		EXPORT int GetPlayerPosition(float &posX, float &posY, float &posZ);
		EXPORT int IsPlayerInRange2D(float posX, float posY, float radius);
		EXPORT int IsPlayerInRange3D(float posX, float posY, float posZ, float radius);
		EXPORT int GetCityName(char* &cityName, int max_len);
		EXPORT int GetZoneName(char* &zoneName, int max_len);
	}
}