#include "api.hpp"
#include "samp.hpp"

core::server::api::api()
{
	core::server::samp::init_samp();
}

core::server::api& core::server::api::singleton()
{
	static core::server::api api;
	return api;
}