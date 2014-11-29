#include "../safe_memory.hpp"

int core::common::internal::filter(unsigned int code, struct _EXCEPTION_POINTERS *ep)
{
	return code == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
}