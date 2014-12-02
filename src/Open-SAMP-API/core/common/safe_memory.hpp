#pragma once
#include "windows.hpp"
#include <boost/optional.hpp>

namespace core
{
	namespace common
	{
		namespace internal
		{
			int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep);

			template<typename T>
			T read_memory(uintptr_t addr, bool& success)
			{
				__try
				{
					auto val = *(T *)(addr);
					success = true;
					return val;
				}
				__except (filter(GetExceptionCode(), GetExceptionInformation()))
				{
					success = false;
				}
			}
		}

		template<typename T>
		boost::optional<T> read_memory(uintptr_t addr)
		{
			bool success = false;
			auto t = internal::read_memory<T>(addr, success);
			
			return success ? boost::optional<T>(t) : boost::optional<T>();
		}
	}
}