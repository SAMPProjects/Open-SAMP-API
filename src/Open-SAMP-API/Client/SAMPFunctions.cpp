#include "SAMPFunctions.hpp"
#include <Shared/PipeMessages.hpp>

EXPORT int Client::SAMPFunctions::SendChat(const char *msg)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::SendChat << std::string(msg);

	if (Utils::PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

EXPORT int Client::SAMPFunctions::ShowGameText(const char *msg, int time, int style)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::ShowGameText << std::string(msg) << time << style;

	if (Utils::PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

EXPORT int Client::SAMPFunctions::AddChatMessage(const char *msg)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::AddChatMessage << std::string(msg);

	if (Utils::PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

