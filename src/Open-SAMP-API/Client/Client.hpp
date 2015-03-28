#pragma once

#include <Utils/Windows.hpp>
#include <Utils/PipeClient.hpp>
#include <Utils/Serializer.hpp>

#define EXPORT extern "C" __declspec(dllexport)

#define SERVER_CHECK(retn)	\
if (!IsServerAvailable())	\
{							\
	if (!Init())			\
		return retn;		\
	else					\
		Sleep(250);			\
}							\

#define SERIALIZER_RET(T) { T retVal; serializerOut >> retVal; return retVal; }

bool IsServerAvailable();

EXPORT int  Init();
EXPORT void	SetParam(char *_szParamName, char *_szParamValue);