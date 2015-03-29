#pragma once
#include "Client.hpp"

namespace Client
{
	namespace SAMPFunctions
	{
		EXPORT int SendChat(const char *msg);
		EXPORT int ShowGameText(const char *msg, int time, int style);
		EXPORT int AddChatMessage(const char *msg);
	}
}
