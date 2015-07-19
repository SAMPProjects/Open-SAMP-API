#pragma once

#include <stdint.h>

namespace Game
{
	namespace SAMP
	{
		struct stInputBox
		{
			void		*pUnknown;
			uint8_t		bChatboxOpen;
		};

		struct stInputInfo
		{
			void		*pUnknown[2];
			stInputBox	*pInputBox;
		};

		void initSAMP();
		void exitSAMP();

		bool sendChat(const char *msg);
		bool showGameText(const char *text, int iTime, int iStyle);
		bool addChatMessage(const char *text);
		bool isChatOpen();
	}
}
