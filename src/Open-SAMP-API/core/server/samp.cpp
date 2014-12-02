#include "samp.hpp"
#include <core/common/windows.hpp>
#include <core/common/safe_memory.hpp>
#include <core/misc/pattern.hpp>
#include <core/misc/module.hpp>
#include <exception>
#include <stdio.h>

DWORD g_dwModuleLength = 0;
DWORD g_dwModuleBase = 0;

#define CHECK_OFFSET(X, RET, TYPE) \
	if (auto val = core::common::read_memory<TYPE>(X)) { if (*val == 0) return RET; } else return RET; 

void core::server::samp::init_samp()
{
	g_dwModuleBase = core::misc::get_module_base("samp.dll");
	g_dwModuleLength = core::misc::get_module_length((HMODULE)g_dwModuleBase);

	if (g_dwModuleBase == 0 || g_dwModuleLength == 0)
		throw std::exception("Error while initializing SA:MP");
}

bool core::server::samp::send_chat(const char *msg)
{
	if (msg == nullptr)
		return false;

	DWORD dwAddr = 0;
	if (msg[0] == '/')
	{
		static auto addr = core::misc::find_pattern(
			g_dwModuleBase, 
			g_dwModuleLength, 
			(BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\xA1\x00\x00\x00\x00\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x85\xC0",
			"xx????xxx????xx????xxx????xx????xx"
		);

		dwAddr = addr;
	}
	else
	{
		static auto addr = core::misc::find_pattern(
			g_dwModuleBase,
			g_dwModuleLength,
			(BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x53\x56\x8B\xB4\x24\x00\x00\x00\x00\x8B\xC6",
			"xx????xxx????xxxx????xx????xxxxx????xx"
		);

		dwAddr = addr;
	}

	if (dwAddr == 0)
		return false;

	__asm push msg
	__asm call dwAddr
	return true;
}

bool core::server::samp::show_game_text(const char *text, int iTime, int iStyle)
{
	static auto addr = core::misc::find_pattern(
		g_dwModuleBase,
		g_dwModuleLength,
		(BYTE *)"\x55\x8B\xEC\x81\x7D\x10\xC8\x00\x00\x00\x7F\x36\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x4D\x08\x8B\x15\x00\x00\x00\x00\x83",
		"xxxxxxxxxxxxx????x????xxxxx????x"
	);

	if (addr == 0)
		return false;

	__asm push iStyle
	__asm push iTime
	__asm push text
	__asm call addr
	return true;
}

bool core::server::samp::add_chat_message(const char *text)
{
	static auto addr = core::misc::find_pattern(
		g_dwModuleBase,
		g_dwModuleLength,
		(BYTE *)"\x8B\x15\x00\x00\x00\x00\x68\x00\x00\x00\x00\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x5F\x5E",
		"xx????x????xx????xxxxx"
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