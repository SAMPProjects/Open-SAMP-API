#pragma once

namespace core
{
	namespace server
	{
		template<class ClientPtr, class Message>
		struct message_handler
		{
			static void on_message(ClientPtr cl, Message msg)
			{

			}
		};
	}
}