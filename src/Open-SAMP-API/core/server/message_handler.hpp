#pragma once
#include "samp.hpp"
#include <core/common/paket_id.hpp>
#include <json_spirit/json_spirit.h>
#include <boost/algorithm/string/predicate.hpp>

namespace core
{
	namespace server
	{
		template<class ClientPtr, class Message>
		struct message_handler
		{
			static void on_command(ClientPtr cl, core::common::paket_id id, json_spirit::Array args)
			{
				using namespace json_spirit;
				using core::common::paket_id;

				if (id == paket_id::ping)
				{
					MessageBoxA(0, "Ping", "Ping", 0);
				}
				else if (id == paket_id::send_chat)
				{
					samp::send_chat(args.at(0).get_str().c_str());
				}

				else if (id == paket_id::show_game_text)
				{

				}

				else if (id == paket_id::add_chat_message)
				{

				}
			}

			static void on_message(ClientPtr cl, Message msg)
			{
				using namespace json_spirit;
				using core::common::paket_id;

				auto message = msg->get_payload();

				// Decompose data
				Value val;
				if (!read(message, val))
					return;

				if (val.type() != obj_type)
					return;

				Object mainObject = val.get_obj();
				paket_id id;
				Array arguments;

				for (const auto& key : mainObject)
				{
					if (boost::iequals(key.name_, "id"))
						id = (paket_id)key.value_.get_int();

					if (boost::iequals(key.name_, "arguments"))
						arguments = key.value_.get_array();
				}

				on_command(cl, id, arguments);
			}
		};
	}
}