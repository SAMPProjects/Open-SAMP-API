#pragma once
#define _WEBSOCKETPP_CPP11_THREAD_
#define _WEBSOCKETPP_CPP11_FUNCTIONAL_
#define _WEBSOCKETPP_CPP11_SYSTEM_ERROR_
#define _WEBSOCKETPP_CPP11_RANDOM_DEVICE_
#define _WEBSOCKETPP_CPP11_MEMORY_

#include <core/common/safe_call.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <vector>
#include <memory>

namespace core
{
	namespace server
	{
		bool is_server();

		template
		<
			template<class, class> class MessageHandler, 
			class ClientManager
		>
		class server : public ClientManager
		{
			typedef websocketpp::server<websocketpp::config::asio> Server;
			typedef Server::message_ptr Message;
			typedef websocketpp::connection_hdl Connection;

			typedef typename ClientManager::ClientType Client;
			typedef typename ClientManager::ClientTypePtr ClientPtr;

			typedef std::vector<ClientPtr> Clients;
			typedef server<MessageHandler, ClientManager> server_t;

			Server server_;
			Clients clients_;
			boost::thread io_thread_;

		public:
			server()
			{
				server_.init_asio();

				server_.set_access_channels(websocketpp::log::alevel::none);
				server_.set_error_channels(websocketpp::log::alevel::none);

				server_.set_open_handler(boost::bind(&server_t::open_handler, this, _1));
				server_.set_close_handler(boost::bind(&server_t::close_handler, this, _1));
				server_.set_message_handler(boost::bind(&server_t::message_handler, this, _1, _2));

				server_.listen(25567);
				server_.start_accept();
				io_thread_ = boost::thread(boost::bind(&Server::run, &server_));
			}

		private:
			void open_handler(Connection con)
			{
				core::common::call_safe_inline([&]()
				{
					create_connection<Connection>(con);
				});
			}

			void close_handler(Connection con)
			{
				core::common::call_safe_inline([&]()
				{
					destroy_connection<Connection>(con);
				});
			}

			void message_handler(Connection con, Message msg)
			{
				core::common::call_safe_inline([&]()
				{
					if (auto client = get_connection<Connection>(con))
						MessageHandler<ClientPtr, Message>::on_message(client, msg);
				});
			}
		};
	}
}