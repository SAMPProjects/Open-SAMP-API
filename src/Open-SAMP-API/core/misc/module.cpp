#include "module.hpp"
#include <Psapi.h>


DWORD core::misc::get_module_base(LPCTSTR file)
{
	return (DWORD)GetModuleHandle(file);
}

DWORD core::misc::get_module_length(HMODULE hModule)
{
	MODULEINFO info;
	GetModuleInformation(GetCurrentProcess(), hModule, &info, sizeof(info));
	return info.SizeOfImage;
}

