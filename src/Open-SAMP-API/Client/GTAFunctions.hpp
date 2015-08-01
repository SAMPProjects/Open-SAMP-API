#pragma once
#include "Client.hpp"

namespace Client
{
	namespace GTAFunctions
	{
		EXPORT bool IsMenuOpen();
		EXPORT bool WorldToScreen(float x, float y, float z, float& screenX, float& screenY);
	}
}
