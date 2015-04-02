#pragma once
#include "windows.h"

namespace Utils
{
	namespace NakedHook
	{
		class NakedHook
		{
			UCHAR*	m_pOrigData;
			BYTE*	m_pTarget;
			DWORD	m_To;
			SIZE_T	m_Len;
			BOOL	m_IsApplied;

		public:
			~NakedHook();

			void init(BYTE* pTarget, DWORD dwTo, SIZE_T Len);

			BOOL remove();
			BOOL apply();

			BOOL  applied() const { return m_IsApplied; }
			DWORD jmp() const { return (DWORD)m_pTarget + m_Len; }
		};
	}
}
