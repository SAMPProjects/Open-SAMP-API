#pragma once
#include "server.hpp"

namespace core
{
	namespace server
	{
		class connection
		{
			typedef websocketpp::server<websocketpp::config::asio>::connection_ptr ConnectionPtr;
			ConnectionPtr socket_;

		public:

			connection(ConnectionPtr socket) : socket_(socket)
			{

			}

			ConnectionPtr socket()
			{
				return socket_;
			}
		};
	}
}