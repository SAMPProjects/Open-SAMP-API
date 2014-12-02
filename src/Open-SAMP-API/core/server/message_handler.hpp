#pragma once
#include "samp.hpp"
#include <core/common/paket_id.hpp>
#include <core/common/json.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <string>
#include <sstream>

namespace core
{
	namespace server
	{
		template<class ClientPtr, class Message>
		struct message_handler
		{
			static common::json::Value on_command(ClientPtr cl, core::common::paket_id id, json_spirit::Array args)
			{
				using namespace common::json;
				using common::paket_id;

				if (id == paket_id::ping)
				{
					int idx = 0;
					std::stringstream ss;
					for (const auto& arg : args)
						ss << "ID: " << idx++ << ", type: " << value_type_to_string(arg.type()) << ", value: " << write(Value(arg)) << std::endl;
					
					return MessageBoxA(0, ss.str().c_str(), "Ping", 0);
				}
				else if (id == paket_id::send_chat)
				{
					return samp::send_chat(args.at(0).get_str().c_str());
				}

				else if (id == paket_id::show_game_text)
				{

				}

				else if (id == paket_id::add_chat_message)
				{

				}

				return{};
			}

			static common::json::Object decompose_data(ClientPtr cl, Message msg)
			{
				using namespace common::json;
				using common::paket_id;

				auto message = msg->get_payload();

				// Decompose data
				Value val;
				if (!read(message, val))
					throw std::exception("Error while reading JSON message");

				if (val.type() != obj_type)
					throw std::exception("JSON type is not an object");

				Object mainObject = val.get_obj();
				paket_id id;
				Array arguments;

				bool idFound = false, argumentsFound = false;
				for (const auto& key : mainObject)
				{
					if (boost::iequals(key.name_, "id")) 
					{
						id = (paket_id)key.value_.get_int();
						idFound = true;
					}
						
					if (boost::iequals(key.name_, "arguments"))
					{
						arguments = key.value_.get_array();
						argumentsFound = true;
					}
				}

				if (!idFound)
					throw std::exception("Key \"id\" in JSON message not found");

				if (!argumentsFound)
					throw std::exception("Key \"arguments\" in JSON message not found");

				Object response;
				response.push_back(Pair("id", (int)id));
				response.push_back(Pair("return", on_command(cl, id, arguments)));
				return response;
			}

			static void on_message(ClientPtr cl, Message msg)
			{
				using namespace common::json;

				std::string sendee;

				try
				{
					sendee = write(decompose_data(cl, msg));
				}
				catch (const std::exception& e)
				{
					Object obj =
					{
						Pair("id", -1),
						Pair("exception", e.what())
					};

					sendee = write(obj);
				}
				catch (...)
				{
					Object obj =
					{
						Pair("id", -1),
						Pair("exception", "unknown exception")
					};

					sendee = write(obj);
				}
				
				cl->send(sendee);
			}
		};
	}
}