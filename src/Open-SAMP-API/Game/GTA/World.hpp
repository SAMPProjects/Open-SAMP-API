#pragma once

namespace Game 
{
	namespace GTA
	{
		bool ScreenToWorld(float screenX, float screenY, float &worldX, float &worldY, float &worldZ);
		bool WorldToScreen(float x, float y, float z, float &screenX, float &screenY);
	}
}