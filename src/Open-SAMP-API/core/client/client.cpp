#include "client.hpp"
#include <core/common/safe_call.hpp>
#include <boost/bind.hpp>
#include <string>

core::client::client& core::client::client::singleton()
{
	static client cl;
	return cl;
}

bool core::client::client::connect()
{
	if (connected_)
		return false;

	return core::common::call_safe_inline([&]()
	{
		std::error_code ec;
		auto ptr = client_.get_connection(std::string("ws://localhost:24456"), ec);

		connection_ = ptr->get_handle();
		client_.connect(ptr);

		io_thread_ = boost::thread(boost::bind(&Client::run, &client_));
	});
}

bool core::client::client::disconnect()
{
	if (!connected_)
		return false;

	return core::common::call_safe_inline([&]()
	{
		client_.stop();
		if (io_thread_.joinable())
			io_thread_.join();

		connected_ = false;
	});
}

bool core::client::client::is_connected() const
{
	return connected_;
}

core::client::client::client()
{
	client_.set_access_channels(websocketpp::log::alevel::none);
	client_.set_error_channels(websocketpp::log::alevel::none);

	client_.set_open_handler(boost::bind(&client::open_handler, this));
	client_.set_fail_handler(boost::bind(&client::fail_close_handler, this));
	client_.set_close_handler(boost::bind(&client::fail_close_handler, this));
	client_.set_message_handler(boost::bind(&client::message_handler, this, _2));

	client_.init_asio();

	connect();
}

void core::client::client::open_handler()
{
	connected_ = true;
}

void core::client::client::fail_close_handler()
{
	connected_ = false;
}

void core::client::client::message_handler(Message msg)
{

}