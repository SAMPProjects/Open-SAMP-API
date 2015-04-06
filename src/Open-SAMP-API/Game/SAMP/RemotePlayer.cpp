#include "RemotePlayer.hpp"
#include "PatternTable.hpp"
#include <Utils/NakedHook.hpp>
#include <Utils/Pattern.hpp>
#include <boost/algorithm/string.hpp>

// updatePlayerData
DWORD g_dwUpdatePlayerDataFunctionPtr = 0;
DWORD g_dwUpdatePlayerDataObjectPtr = 0;

// getPlayerNameByID
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
	// updatePlayerData
	{
		DWORD dwPattern = Utils::Pattern::findPattern(dwModuleBase, dwModuleLen, PatternTable::UpdatePlayerData::byteMask, PatternTable::UpdatePlayerData::useMask);
		if (dwPattern)
		{
			g_dwUpdatePlayerDataObjectPtr = *(DWORD *)(dwPattern + 0x2);
			g_dwUpdatePlayerDataFunctionPtr = *(DWORD *)(dwPattern + 0x7) + dwPattern + 0x7 + 0x4;
		}
	}

	// getPlayerNameByID
	{
		DWORD dwPattern = Utils::Pattern::findPattern(dwModuleBase, dwModuleLen, PatternTable::GetPlayerNameByID::byteMask, PatternTable::GetPlayerNameByID::useMask);
		if (dwPattern)
		{
			g_dwPlayerNameByIDFunction = *(DWORD *)(dwPattern + 0x5) + dwPattern + 0x5 + 0x4; // Calculate real address

			g_playerNameByIDHook.init((PBYTE)g_dwPlayerNameByIDFunction, (DWORD)playerNameByIDNakedHandler, 5);
			g_dwPlayerNamebyIDJMP = g_playerNameByIDHook.jmp();

			g_playerNameByIDHook.apply();
		}
	}
}

bool Game::SAMP::RemotePlayer::updatePlayerData()
{
	if (g_dwUpdatePlayerDataFunctionPtr == 0 || g_dwUpdatePlayerDataObjectPtr == 0)
		return false;

	__asm
	{
		mov eax, g_dwUpdatePlayerDataObjectPtr
		mov ecx, [eax]
		call g_dwUpdatePlayerDataFunctionPtr
	}

	return true;
}

const char *Game::SAMP::RemotePlayer::playerNameByID(unsigned short id)
{
	if (g_dwPlayerDataOffset == 0 || g_dwPlayerNameByIDFunction == 0)
		return nullptr;

	updatePlayerData();

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

