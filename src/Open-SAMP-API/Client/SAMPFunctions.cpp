#include "SAMPFunctions.hpp"
#include <Shared/PipeMessages.hpp>

EXPORT int SendChat(const char *msg)
{
	SERVER_CHECK(0)

	Serializer serializerIn, serializerOut;

	serializerIn << PipeMessages::SendChat << std::string(msg);

	if (PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

EXPORT int ShowGameText(const char *msg, int time, int style)
{
	SERVER_CHECK(0)

	Serializer serializerIn, serializerOut;

	serializerIn << PipeMessages::SendChat << std::string(msg) << time << style;

	if (PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

EXPORT int AddChatMessage(const char *msg)
{
	SERVER_CHECK(0)

	Serializer serializerIn, serializerOut;

	serializerIn << PipeMessages::AddChatMessage << std::string(msg);

	if (PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

