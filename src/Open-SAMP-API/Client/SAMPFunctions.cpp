#include "SAMPFunctions.hpp"
#include "GTAFunctions.hpp"
#include <Shared/PipeMessages.hpp>
#include <boost/algorithm/string.hpp>

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

EXPORT int Client::SAMPFunctions::GetPlayerNameByID(int id, char *&playername, int max_len)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::GetPlayerNameByID << id;

	if (Utils::PipeClient(serializerIn, serializerOut).success())
	{
		std::string out;
		serializerOut >> out;

		if (!out.length())
			return 0;

		strcpy_s(playername, max_len, out.c_str());
		return 1;
	}

	return 0;
}

EXPORT int Client::SAMPFunctions::GetPlayerIDByName(const char *name)
{
	for (int i = 0; i < 1004; i++)
	{
		char szBuffer[32] = { 0 };
		char *ptr = szBuffer;

		if (GetPlayerNameByID(i, ptr, sizeof(szBuffer) - 1))
			if (boost::iequals(std::string(szBuffer), std::string(name)))
				return i;
	}

	return -1;
}

EXPORT int Client::SAMPFunctions::GetPlayerName(char *&playername, int max_len)
{
	char *szCommandLine = new char[512];
	ZeroMemory(szCommandLine, 512);

	GTAFunctions::GetGTACommandLine(szCommandLine, 512);

	char *context = NULL;
	char *token = strtok_s(szCommandLine, " ", &context);

	while (token != NULL) {
		token = strtok_s(NULL, " ", &context);
		if (strcmp(token, "-n") == 0)
			break;
	}

	if (token != NULL)
	{
		token = strtok_s(NULL, " ", &context);
		strcpy_s(playername, max_len, token);
	}

	delete[] szCommandLine;
	return token != NULL;
}

EXPORT int Client::SAMPFunctions::GetPlayerId()
{
	char *szName = new char[25];
	ZeroMemory(szName, 25);

	GetPlayerName(szName, 25);

	int iID = GetPlayerIDByName(szName);

	delete[] szName;

	return iID;
}

EXPORT int Client::SAMPFunctions::IsChatOpen()
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::IsChatOpen;

	if (Utils::PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}

EXPORT int Client::SAMPFunctions::IsDialogOpen()
{
	SERVER_CHECK(0)

		Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::IsDialogOpen;

	if (Utils::PipeClient(serializerIn, serializerOut).success())
		SERIALIZER_RET(int);

	return 0;
}
