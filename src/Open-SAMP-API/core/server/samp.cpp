#include "samp.hpp"
#include <core/common/windows.hpp>
#include <core/misc/pattern.hpp>
#include <core/misc/module.hpp>

DWORD g_dwModuleLength = 0;
DWORD g_dwModuleBase = 0;

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
			(BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\xA1\x00\x00\x00\x00\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x18\x01\x00\x00",
			"xxxxxxxxx????xx????xxxxxxxxxxxxx"
		);
		dwAddr = addr;
	}
	else
	{
		static auto addr = core::misc::find_pattern(
			g_dwModuleBase,
			g_dwModuleLength,
			(BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x18\x01\x00\x00\x53\x56\x8B\xB4\x24",
			"xxxxxxxxx????xxxxxxxxxxxxxxxxxxx"
		);
		dwAddr = addr;
	}

	if (dwAddr == 0)
		return false;

	((void(__stdcall *)(const char *)) dwAddr)(msg);
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

	((void(__stdcall *)(const char *, int, int)) addr)(text, iTime, iStyle);
	return true;
}

bool core::server::samp::add_chat_message(const char *text)
{
	static auto addr = core::misc::find_pattern(
		g_dwModuleBase,
		g_dwModuleLength,
		(BYTE *)"\xA1\x00\x00\x00\x00\x56\x68\x00\x00\x00\x00\x50\x8B\xF1\xE8\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x83\xC4\x08\x85\xC9\x74\x07",
		"x????xx????xxxx????xx????xxxxxxx"
	);

	if (addr == 0)
		return false;

	DWORD dwCallAddr = *(DWORD *)(addr + 0xF) + addr + 0xF + 0x4;
	DWORD dwInfo = *(DWORD *)(addr + 0x1);

	((void(__stdcall *)(DWORD, const char *))dwCallAddr) (*(DWORD *)dwInfo, text);
	return true;
}