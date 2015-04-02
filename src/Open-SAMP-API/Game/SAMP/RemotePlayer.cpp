#include "RemotePlayer.hpp"
#include "PatternTable.hpp"
#include <Utils/NakedHook.hpp>
#include <Utils/Pattern.hpp>
#include <boost/algorithm/string.hpp>

DWORD g_dwPlayerNameByIDFunction = 0;
DWORD g_dwPlayerNamebyIDJMP = 0;
DWORD g_dwPlayerDataOffset = 0;
Utils::NakedHook::NakedHook g_playerNameByIDHook;

void __declspec(naked) playerNameByIDNakedHandler()
{
	__asm pushad
	__asm pushfd

	__asm mov g_dwPlayerDataOffset, ecx

	// Remove the hook if the offset has been fetched successfully
	if (g_dwPlayerDataOffset)
		g_playerNameByIDHook.remove();

	__asm popfd
	__asm popad

	__asm mov ax, [esp + 4h]
	__asm jmp[g_dwPlayerNamebyIDJMP]
}

void Game::SAMP::RemotePlayer::Internal::init(DWORD dwModuleBase, DWORD dwModuleLen)
{
	DWORD dwPattern = Utils::Pattern::findPattern(dwModuleBase, dwModuleLen, SAMP::PatternTable::GetPlayerNameByID::byteMask, SAMP::PatternTable::GetPlayerNameByID::useMask);
	g_dwPlayerNameByIDFunction = *(DWORD *)(dwPattern + 0x5) + dwPattern + 0x5 + 0x4; // Calculate real address

	g_playerNameByIDHook.init((PBYTE)g_dwPlayerNameByIDFunction, (DWORD)playerNameByIDNakedHandler, 5);
	g_dwPlayerNamebyIDJMP = g_playerNameByIDHook.jmp();

	g_playerNameByIDHook.apply();
}

const char *Game::SAMP::RemotePlayer::playerNameByID(unsigned short id)
{
	if (g_dwPlayerDataOffset == 0 || g_dwPlayerNameByIDFunction == 0)
		return nullptr;

	char *ptr_ = nullptr;
	__asm
	{
		mov ecx, g_dwPlayerDataOffset
		push id
		call g_dwPlayerNameByIDFunction
		mov ptr_, eax
	}

	return ptr_;
}

