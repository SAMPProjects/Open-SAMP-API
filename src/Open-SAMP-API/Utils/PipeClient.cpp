#include "Windows.hpp"
#include "PipeClient.hpp"
#include "Serializer.hpp"
#include <Shared/Config.hpp>
#include <iostream>

Utils::PipeClient::PipeClient(Serializer& serializerIn, Serializer& serializerOut) :
m_bSuccess(false)
{
	char szData[BUFSIZE] = { 0 };
	char szPipe[MAX_PATH + 1] = { 0 };
	DWORD dwReaded;

	sprintf_s(szPipe, "\\\\.\\pipe\\%s", Shared::Config::pipeName);

	if (CallNamedPipe(szPipe, (LPVOID)serializerIn.data(), serializerIn.numberOfBytesUsed(), szData, sizeof(szData), &dwReaded, TIME_OUT))
	{
		serializerOut.setData(szData, sizeof(szData));
		m_bSuccess = true;
	}
}

bool Utils::PipeClient::success() const
{
	return m_bSuccess;
}