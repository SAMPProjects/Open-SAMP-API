#pragma once
#include "Client.hpp"

namespace Client
{
	namespace SAMPFunctions
	{
		int ReadGTACmdArgument(const char * option, char *& str, int max_len);
		EXPORT int GetServerIP(char *&ip, int max_len);
		EXPORT int GetServerPort();
		EXPORT int SendChat(const char *msg);
		EXPORT int ShowGameText(const char *msg, int time, int style);
		EXPORT int AddChatMessage(const char *msg);
		EXPORT int ShowDialog(int id, int style, const char *caption, const char *text, const char *button, const char *button2);
		EXPORT int GetPlayerNameByID(int id, char *&playername, int max_len);
		EXPORT int GetPlayerIDByName(const char *name);
		EXPORT int GetPlayerName(char *&playername, int max_len);
		EXPORT int GetPlayerId();
		EXPORT int IsChatOpen();
		EXPORT int IsDialogOpen();
	}
}
