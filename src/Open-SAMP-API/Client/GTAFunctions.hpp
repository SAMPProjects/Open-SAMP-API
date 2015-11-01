#pragma once
#include "Client.hpp"

namespace Client
{
	namespace GTAFunctions
	{
        EXPORT int GetGTACommandLine(char* &line, int max_len);
		EXPORT bool IsMenuOpen();
		EXPORT bool ScreenToWorld(float x, float y, float &worldX, float &worldY, float &worldZ);
		EXPORT bool WorldToScreen(float x, float y, float z, float& screenX, float& screenY);
	}
}
