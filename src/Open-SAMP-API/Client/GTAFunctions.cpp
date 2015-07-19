#include "GTAFunctions.hpp"
#include "MemoryFunctions.hpp"

EXPORT bool Client::GTAFunctions::IsMenuOpen()
{
	BYTE bOpen;
	MemoryFunctions::ReadMemory(0xB6B964, 1, (char *)&bOpen);
	return bOpen != 0;
}
