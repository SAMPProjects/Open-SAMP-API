#pragma once
#include "connection.hpp"
#include <core/misc/ctor.hpp>
#include <memory>
#include <vector>

namespace core
{
	namespace server
	{
		struct connection_manager
		{
			DISABLE_CPY_MOV_CTOR(connection_manager)

			typedef connection ClientType;
			typedef std::shared_ptr<ClientType> ClientTypePtr;

		protected:
			connection_manager() { }
			virtual ~connection_manager() { }

			template<class ConnectionPtr>
			void create_connection(ConnectionPtr client_ptr)
			{
				clients_.insert(std::make_shared<ClientType>(client_ptr));
			}

			template<class ConnectionPtr>
			void destroy_connection(ConnectionPtr client_ptr)
			{
				auto ptr = get_connection<ConnectionPtr>(client_ptr);
				if (!ptr)
					return;

				clients_.erase(ptr);
			}

			template<class ConnectionPtr>
			ClientTypePtr get_connection(ConnectionPtr client_ptr)
			{
				for (const auto& i : clients_)
				{
					if (!i)
						continue;

					if (i->socket() == client_ptr)
						return i;
				}

				return nullptr;
			}

		private:
			std::set<ClientTypePtr> clients_;
		};
	}
}