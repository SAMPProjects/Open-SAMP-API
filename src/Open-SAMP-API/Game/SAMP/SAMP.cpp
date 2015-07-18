#include "SAMP.hpp"
#include "PatternTable.hpp"
#include "RemotePlayer.hpp"
#include <Utils/Windows.hpp>
#include <Utils/Memory.hpp>
#include <Utils/Pattern.hpp>
#include <Utils/Module.hpp>
#include <exception>
#include <stdio.h>


#define CHECK_OFFSET(X, RET, TYPE) \
	if (auto val = Utils::Memory::readMemory<TYPE>(X)) { if (*val == 0) return RET; } else return RET;

DWORD g_dwModuleLength = 0;
DWORD g_dwModuleBase = 0;

void Game::SAMP::initSAMP()
{
	g_dwModuleBase = Utils::Module::moduleBase("samp.dll");
	g_dwModuleLength = Utils::Module::moduleLength((HMODULE)g_dwModuleBase);

	if (g_dwModuleBase == 0 || g_dwModuleLength == 0)
		throw std::exception("Error while initializing SA:MP");

	RemotePlayer::Internal::init(g_dwModuleBase, g_dwModuleLength);
}

void Game::SAMP::exitSAMP()
{

}

bool Game::SAMP::sendChat(const char *msg)
{
	if (msg == nullptr)
		return false;

	DWORD dwAddr = 0;
	if (msg[0] == '/')
	{
		static auto addr = Utils::Pattern::findPattern(
			g_dwModuleBase, 
			g_dwModuleLength, 
			Game::SAMP::PatternTable::SendChat::Command::byteMask,
			Game::SAMP::PatternTable::SendChat::Command::useMask
		);

		dwAddr = addr;
	}
	else
	{
		static auto addr = Utils::Pattern::findPattern(
			g_dwModuleBase,
			g_dwModuleLength,
			Game::SAMP::PatternTable::SendChat::Chat::byteMask,
			Game::SAMP::PatternTable::SendChat::Chat::useMask
		);

		dwAddr = addr;
	}

	if (dwAddr == 0)
		return false;

	__asm push msg
	__asm call dwAddr
	return true;
}

bool Game::SAMP::showGameText(const char *text, int iTime, int iStyle)
{
	static auto addr = Utils::Pattern::findPattern(
		g_dwModuleBase,
		g_dwModuleLength,
		Game::SAMP::PatternTable::GameText::byteMask,
		Game::SAMP::PatternTable::GameText::useMask
	);

	if (addr == 0)
		return false;

	__asm push iStyle
	__asm push iTime
	__asm push text
	__asm call addr
	return true;
}

bool Game::SAMP::addChatMessage(const char *text)
{
	static auto addr = Utils::Pattern::findPattern(
		g_dwModuleBase,
		g_dwModuleLength,
		Game::SAMP::PatternTable::AddChatMessage::byteMask,
		Game::SAMP::PatternTable::AddChatMessage::useMask
	);

	if (addr == 0)
		return false;

	DWORD dwCallAddr = *(DWORD *)(addr + 0xD) + addr + 0xD + 0x4;
	DWORD dwInfo = *(DWORD *)(addr + 0x2);

	CHECK_OFFSET(dwInfo, false, DWORD)

	__asm mov edx, dword ptr[dwInfo]
	__asm mov eax, [edx]
	__asm push text
	__asm push eax
	__asm call dwCallAddr
	__asm add esp, 8
	return true;
}

const char *Game::SAMP::getLicensePlate()
{
	// TODO: Find general pattern

	static auto addr = g_dwModuleBase + 0x13C54C;

	if (addr == 0)
		return nullptr;

	DWORD dwAddr = *(DWORD *)(addr) + 0x9b;

	if (dwAddr == 0)
		return nullptr;
	
	char *chLcPlate = new char[20];
	if (ReadProcessMemory(GetCurrentProcess(), (LPCVOID)dwAddr, chLcPlate, 20, NULL) == FALSE)
		return nullptr;

	return chLcPlate;
}