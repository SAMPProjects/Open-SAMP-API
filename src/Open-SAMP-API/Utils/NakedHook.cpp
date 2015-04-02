#include "NakedHook.hpp"


Utils::NakedHook::NakedHook::~NakedHook()
{
	if (applied())
		remove();

	delete[] m_pOrigData;
}

void Utils::NakedHook::NakedHook::init(BYTE* pTarget, DWORD dwTo, SIZE_T Len)
{
	m_pTarget = pTarget;
	m_To = dwTo;
	m_Len = Len;
	m_pOrigData = new UCHAR[Len];
}

BOOL Utils::NakedHook::NakedHook::remove()
{
	if (!applied())
		return FALSE;

	DWORD dwProtect;
	if (VirtualProtect((void *) m_pTarget, m_Len, PAGE_EXECUTE_READWRITE, &dwProtect)){

		memcpy(m_pTarget, m_pOrigData, m_Len);

		VirtualProtect((void *) m_pTarget, m_Len, dwProtect, NULL);
		FlushInstructionCache(GetCurrentProcess(), m_pTarget, m_Len);

		m_IsApplied = FALSE;
	}

	return applied();
}

BOOL Utils::NakedHook::NakedHook::apply()
{
	if (applied())
		return FALSE;

	DWORD dwProtect;
	if (VirtualProtect((void *) m_pTarget, m_Len, PAGE_EXECUTE_READWRITE, &dwProtect)){
		memcpy(m_pOrigData, m_pTarget, m_Len);

		DWORD jmp = m_To - (DWORD) m_pTarget - 0x5;
		m_pTarget[0] = 0xE9;
		memcpy((void *) (BYTE *) (m_pTarget + 1), &jmp, 4);

		VirtualProtect((void *) m_pTarget, m_Len, dwProtect, NULL);
		FlushInstructionCache(GetCurrentProcess(), m_pTarget, m_Len);

		m_IsApplied = TRUE;
		return TRUE;
	}

	m_IsApplied = FALSE;
	return FALSE;
}