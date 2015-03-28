#pragma once
#include "Windows.hpp"

namespace Utils
{
	namespace Module
	{
		DWORD moduleBase(LPCTSTR file);
		DWORD moduleLength(HMODULE hModule);
	}
}