#pragma once
#include <core/misc/ctor.hpp>
#include <core/common/safe_call.hpp>
#include <core/common/websocket.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
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
			DISABLE_CPY_MOV_CTOR(server)

			typedef common::websocket::server Server;
			typedef common::websocket::message_ptr Message;
			typedef common::websocket::connection_ptr ConnectionPtr;
			typedef common::websocket::connection_hdl ConnectionHDL;

			typedef typename ClientManager::ClientType Client;
			typedef typename ClientManager::ClientTypePtr ClientPtr;

			Server server_;
			boost::thread io_thread_;

		public:
			server()
			{
				server_.init_asio();

				server_.set_access_channels(websocketpp::log::alevel::none);
				server_.set_error_channels(websocketpp::log::alevel::none);

				server_.set_open_handler(boost::bind(&server<MessageHandler, ClientManager>::open_handler, this, _1));
				server_.set_close_handler(boost::bind(&server<MessageHandler, ClientManager>::close_handler, this, _1));
				server_.set_message_handler(boost::bind(&server<MessageHandler, ClientManager>::message_handler, this, _1, _2));

				server_.listen(25567);
				server_.start_accept();
				io_thread_ = boost::thread(boost::bind(&Server::run, &server_));
			}

		private:
			void open_handler(ConnectionHDL con)
			{
				core::common::call_safe_inline([&]()
				{
					create_connection<ConnectionPtr>(server_.get_con_from_hdl(con));
				});
			}

			void close_handler(ConnectionHDL con)
			{
				core::common::call_safe_inline([&]()
				{
					destroy_connection<ConnectionPtr>(server_.get_con_from_hdl(con));
				});
			}

			void message_handler(ConnectionHDL con, Message msg)
			{
				core::common::call_safe_inline([&]()
				{
					if (auto client = get_connection<ConnectionPtr>(server_.get_con_from_hdl(con)))
						MessageHandler<ClientPtr, Message>::on_message(client, msg);
				});
			}
		};
	}
}