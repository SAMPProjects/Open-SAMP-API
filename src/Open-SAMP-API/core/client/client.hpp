#pragma once
#include "callbacks.hpp"
#include <core/common/websocket.hpp>
#include <core/misc/ctor.hpp>
#include <boost/thread.hpp>

namespace core
{
	namespace client
	{
		class client
		{
			typedef core::common::websocket::client Client;
			typedef core::common::websocket::message_ptr Message;
			typedef core::common::websocket::connection_hdl ConnectionHDL;

			Client client_;
			ConnectionHDL connection_;
			boost::thread io_thread_;
			bool connected_ = false;
			callbacks::callbacks callbacks_;

		public:
			DISABLE_CPY_MOV_CTOR(client)
			
			static client& singleton();
			callbacks::callbacks& callbacks();

			bool connect();
			bool disconnect();
			bool is_connected() const;

		private:
			client();

			void open_handler();
			void fail_close_handler();
			void message_handler(Message msg);
		};
	}
}
