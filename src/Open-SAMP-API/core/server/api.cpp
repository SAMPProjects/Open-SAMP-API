#include "api.hpp"

core::server::api::api()
{
}

core::server::api& core::server::api::singleton()
{
	static core::server::api api;
	return api;
}