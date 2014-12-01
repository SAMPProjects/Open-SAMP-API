#pragma once
#include <core/misc/ctor.hpp>
#include "server.hpp"

namespace core
{
	namespace server
	{
		class connection
		{
			DISABLE_CPY_MOV_CTOR(connection);

			typedef websocketpp::server<websocketpp::config::asio>::connection_ptr ConnectionPtr;
			ConnectionPtr socket_;

		public:
			
			explicit connection(ConnectionPtr socket) : socket_(socket)
			{

			}
			ConnectionPtr socket()
			{
				return socket_;
			}
		};
	}
}