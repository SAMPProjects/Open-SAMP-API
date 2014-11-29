#pragma once
#include <core/common/windows.hpp>

namespace core
{
	namespace misc
	{
		DWORD find_pattern(DWORD dwStart, DWORD dwLen, BYTE *bMask, char *szMask);
	}
}