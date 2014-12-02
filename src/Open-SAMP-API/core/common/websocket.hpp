#pragma once
#define _WEBSOCKETPP_CPP11_THREAD_
#define _WEBSOCKETPP_CPP11_FUNCTIONAL_
#define _WEBSOCKETPP_CPP11_SYSTEM_ERROR_
#define _WEBSOCKETPP_CPP11_RANDOM_DEVICE_
#define _WEBSOCKETPP_CPP11_MEMORY_
#define _WEBSOCKETPP_DELETED_FUNCTIONS_

#include <core/misc/type_traits.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <websocketpp/client.hpp>

namespace core
{
	namespace common
	{
		namespace websocket
		{
			typedef websocketpp::server<websocketpp::config::asio> server;
			typedef websocketpp::client<websocketpp::config::asio> client;

			typedef misc::is_same<server::message_ptr, client::message_ptr>::type message_ptr;
			typedef misc::is_same<server::connection_ptr, client::connection_ptr>::type connection_ptr;

			typedef websocketpp::connection_hdl connection_hdl;
		}
	}
}
