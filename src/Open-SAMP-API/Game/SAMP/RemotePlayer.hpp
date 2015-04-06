#pragma once
#include <Utils/Windows.hpp>
#include <string>

namespace Game
{
	namespace SAMP
	{
		namespace RemotePlayer
		{
			namespace Internal
			{
				void init(DWORD dwModuleBase, DWORD dwModuleLen);
			}

			bool updatePlayerData();
			const char *playerNameByID(unsigned short id);
		}
	}
}