#pragma once
#include <core/common/windows.hpp>

namespace core
{
	namespace misc
	{
		DWORD get_module_base(LPCTSTR file);
		DWORD get_module_length(HMODULE hModule);
	}
}