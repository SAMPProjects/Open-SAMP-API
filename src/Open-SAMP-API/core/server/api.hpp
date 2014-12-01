#pragma once
#include <core/misc/ctor.hpp>
#include "connection.hpp"
#include "server.hpp"
#include "message_handler.hpp"
#include "connection_manager.hpp"

namespace core
{
	namespace server
	{
		class api
		{
			DISABLE_CPY_MOV_CTOR(api)

			// private constructor
			api();
			server<message_handler, connection_manager> server_;
		public:
			static api& singleton();
		};
	}
}