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

		struct stDialog
		{
			char		szUnknown[0x28];
			__int32		iDialogOpen;
			__int32		iType;
			__int32		iId;
		};

		void initSAMP();
		void exitSAMP();

		bool sendChat(const char *msg);
		bool showGameText(const char *text, int iTime, int iStyle);
		bool addChatMessage(const char *text);
		bool showDialog(int id, int style, const char *caption, const char *text, const char *button, const char *button2, int isServerDialog);
		bool isChatOpen();
		bool isDialogOpen();
	}
}
