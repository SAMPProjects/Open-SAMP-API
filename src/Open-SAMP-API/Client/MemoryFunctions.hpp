#pragma once
#include "Client.hpp"

namespace Client
{
	namespace MemoryFunctions
	{
		EXPORT int ReadMemoryRef(unsigned int address, unsigned int len, char *&ptr);
		EXPORT int ReadMemory(unsigned int address, unsigned int len, void *ptr);
	}
}