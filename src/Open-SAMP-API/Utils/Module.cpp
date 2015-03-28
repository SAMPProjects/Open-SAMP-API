#include "module.hpp"
#include <Psapi.h>


DWORD Utils::Module::moduleBase(LPCTSTR file)
{
	return (DWORD)GetModuleHandle(file);
}

DWORD Utils::Module::moduleLength(HMODULE hModule)
{
	MODULEINFO info;
	GetModuleInformation(GetCurrentProcess(), hModule, &info, sizeof(info));
	return info.SizeOfImage;
}

