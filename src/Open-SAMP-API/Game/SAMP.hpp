#pragma once

namespace Game
{
	namespace SAMP
	{
		void initSAMP();

		bool sendChat(const char *msg);
		bool showGameText(const char *text, int iTime, int iStyle);
		bool addChatMessage(const char *text);
	}
}
