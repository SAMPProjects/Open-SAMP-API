#include "MemoryFunctions.hpp"
#include <Shared/PipeMessages.hpp>

EXPORT int Client::MemoryFunctions::ReadMemoryRef(unsigned int address, unsigned int len, char *&ptr)
{
	return ReadMemory(address, len, ptr);
}

EXPORT int Client::MemoryFunctions::ReadMemory(unsigned int address, unsigned int len, void *ptr)
{
	SERVER_CHECK(0)

	Utils::Serializer serializerIn, serializerOut;

	serializerIn << Shared::PipeMessages::ReadMemory << address << len;

	if (Utils::PipeClient(serializerIn, serializerOut).success())
	{
		std::string ret;
		serializerOut >> ret;

		if (ret.size() != len)
			return 0;

		memcpy_s(ptr, len, ret.c_str(), len);
		return ret.size();
	}
		
	return 0;
}

