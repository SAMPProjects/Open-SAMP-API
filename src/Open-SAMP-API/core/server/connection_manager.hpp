#pragma once
#include "connection.hpp"
#include <memory>
#include <vector>

namespace core
{
	namespace server
	{
		struct connection_manager
		{
			typedef connection ClientType;
			typedef std::shared_ptr<ClientType> ClientTypePtr;

		protected:
			virtual ~connection_manager() { }

			template<class T>
			void create_connection(T cl)
			{

			}

			template<class T>
			void destroy_connection(T cl)
			{

			}

			template<class T>
			ClientTypePtr get_connection(T cl)
			{
				return nullptr;
			}
		};
	}
}