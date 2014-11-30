#pragma once

namespace core
{
	namespace common
	{
		enum class paket_id : int
		{
			// Pinging
			ping = 0,

			// SA:MP-Commands
			send_chat,
			show_game_text,
			add_chat_message
		};
	}
}