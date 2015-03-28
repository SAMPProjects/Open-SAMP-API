#pragma once
#include "Windows.hpp"
#include <boost/optional.hpp>

namespace Utils
{
	namespace Memory
	{
		namespace Internal
		{
			int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep);

			template<typename T>
			T readMemory(uintptr_t addr, bool& success)
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

				return T();
			}
		}

		template<typename T>
		boost::optional<T> readMemory(uintptr_t addr)
		{
			bool success = false;
			auto t = Internal::readMemory<T>(addr, success);
			
			return success ? boost::optional<T>(t) : boost::optional<T>();
		}
	}
}