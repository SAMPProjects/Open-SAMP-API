#pragma once

namespace core
{
	namespace server
	{
		namespace samp
		{
			void init_samp();

			bool send_chat(const char *msg);
			bool show_game_text(const char *text, int iTime, int iStyle);
			bool add_chat_message(const char *text);
		}
	}
}
