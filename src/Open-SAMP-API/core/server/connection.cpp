#include "connection.hpp"
#include <core/common/safe_call.hpp>

core::server::connection::connection(core::server::connection::ConnectionPtr socket) : socket_(socket)
{

}

core::server::connection::ConnectionPtr core::server::connection::socket()
{
	return socket_;
}

bool core::server::connection::send(const std::string& msg)
{
	bool error = false;
	bool b = common::call_safe_inline([&](){
		error = (bool) socket_->send(msg);
	});

	return b & error;
}
