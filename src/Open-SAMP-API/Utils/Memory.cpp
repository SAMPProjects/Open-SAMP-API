#include "Memory.hpp"

int Utils::Memory::Internal::filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{
	return code == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
}