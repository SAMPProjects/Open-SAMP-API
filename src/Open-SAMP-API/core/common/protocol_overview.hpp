#pragma once

/*
	Protocol-Overview for the WebSocket-Connection
	Every message must have an id for identification purposes. Without such an id the server will be unable to identify what the client want to do.
	The whole message is JSON encoded so many programs with WebSocket support are able to communicate with the process directly and doesn't rely on serializers like boost.serialization. 

	Request
		This JSON message need a key called "id" and "arguments". The "id"-key specifies what the server should do for instance with "send_chat" or any other operation. The ids can be looked up in core/common/paket_id.hpp.
		The "arguments"-key is an array of values and specifies the arguments for the operation.
	Reply
		Every message contains an id (-1 if invalid or an exception is thrown) and a key called "return" or "exception".
		"return" is the result of the internal function call and "exception" contains the reason for the exception.

	ping
		Request
			{ "id": 0, "arguments": [] }
		Reply
			{ "id": 0, "exception": true / false, return: Depends }

	send_chat
		Request
			{ "id": 1, "arguments": ["chat-message"] }
		Reply
			{ "id": 1, return: Depends }

	show_game_text
		Request
			{ "id": 2, "arguments": ["text", timeAsInt, styleAsInt] }
		Reply
			{ "id": 2, return: Depends }

	add_chat_message
		Request
			{ "id": 3, "arguments": ["text"] }
		Reply
			{ "id": 3, return: Depends }


*/