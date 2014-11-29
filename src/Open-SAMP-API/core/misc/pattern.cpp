#include "pattern.hpp"

bool compare_data(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;

	return (*szMask) == NULL;
}

DWORD core::misc::find_pattern(DWORD dwStart, DWORD dwLen, BYTE *bMask, char *szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (::compare_data((BYTE*)(dwStart + i), bMask, szMask))
			return (DWORD)(dwStart + i);

	return 0;
}
