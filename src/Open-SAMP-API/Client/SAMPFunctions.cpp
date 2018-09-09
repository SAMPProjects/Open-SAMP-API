#include "SAMPFunctions.hpp"
#include "GTAFunctions.hpp"
#include <Shared/PipeMessages.hpp>
#include <boost/algorithm/string.hpp>

int Client::SAMPFunctions::ReadGTACmdArgument(char *option, char *&str, int max_len) {
	char *szCommandLine = new char[512];
	ZeroMemory(szCommandLine, 512);

	if (GTAFunctions::GetGTACommandLine(szCommandLine, 512) == 0)
		return 0;

	// The gta_sa.exe process of SAMP looks something like this:
	// PATH/TO/gta_sa.exe -n NAME -h IP -p PORT
	// In here, we attempt to read any attributes that were passed in there
	char *context = NULL;
	char *token = strtok_s(szCommandLine, " ", &context);

	while (token != NULL) {
		token = strtok_s(NULL, " ", &context);
		if (strcmp(token, option) == 0)
			break;
	}

	if (token != NULL)
	{
		token = strtok_s(NULL, " ", &context);
		strcpy_s(str, max_len, token);
	}

	delete[] szCommandLine;
	return token != NULL;
}

EXPORT int Client::SAMPFunctions::GetServerIP(char *&ip, int max_len)
{
	return ReadGTACmdArgument("-h", ip, max_len);
}

EXPORT int Client::SAMPFunctions::GetServerPort()
{
	char *portStr = new char[5];
	ZeroMemory(portStr, 5);
	if (ReadGTACmdArgument("-p", portStr, 5)) {
		errno = 0;
		int port = strtol(portStr, NULL, 10);
		if (errno != 0)
			return -1;
		return port;
	}
	
	return -1;
}

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

EXPORT int Client::SAMPFunctions::ShowDialog(int id, int style, const char * caption, const char * text, const char * button, const char * button2)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::ShowDialog << id << style << std::string(caption) << std::string(text) << std::string(button) << std::string(button2);

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
	return ReadGTACmdArgument("-n", playername, max_len);
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
