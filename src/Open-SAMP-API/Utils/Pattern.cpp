#include "Pattern.hpp"

bool Utils::Pattern::Internal::dataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
	if (*szMask == 'x' && *pData != *bMask)
		return false;
	return (*szMask) == NULL;
}


DWORD Utils::Pattern::findPattern(DWORD addr, DWORD len, const BYTE *bMask, const char *szMask)
{
	for (DWORD i = 0; i < len; i++)
	if (Internal::dataCompare((BYTE*) (addr + i), bMask, szMask))
		return (DWORD) (addr + i);
	return 0;
}