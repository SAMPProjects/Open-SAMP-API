#pragma once
#include "Client.hpp"

namespace Client
{
	namespace SAMPFunctions
	{
		EXPORT int SendChat(const char *msg);
		EXPORT int ShowGameText(const char *msg, int time, int style);
		EXPORT int AddChatMessage(const char *msg);
		EXPORT int GetPlayerNameByID(int id, char *&playername, int max_len);
		EXPORT int GetPlayerIDByName(const char *name);
	}
}
