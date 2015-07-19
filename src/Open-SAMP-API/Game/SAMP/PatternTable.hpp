#pragma once
#include <Utils/Windows.hpp>

namespace Game
{
	namespace SAMP
	{
		namespace PatternTable
		{
			namespace SendChat
			{
				namespace Command
				{
					static const BYTE *byteMask = (const BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\xA1\x00\x00\x00\x00\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x85\xC0";
					static const char *useMask = "xx????xxx????xx????xxx????xx????xx";
				}
				
				namespace Chat
				{
					static const BYTE *byteMask = (const BYTE *)"\x64\xA1\x00\x00\x00\x00\x6A\xFF\x68\x00\x00\x00\x00\x50\x64\x89\x25\x00\x00\x00\x00\x81\xEC\x00\x00\x00\x00\x53\x56\x8B\xB4\x24\x00\x00\x00\x00\x8B\xC6";
					static const char *useMask = "xx????xxx????xxxx????xx????xxxxx????xx";
				}
			}

			namespace GameText
			{
				static const BYTE *byteMask = (const BYTE *)"\x55\x8B\xEC\x81\x7D\x10\xC8\x00\x00\x00\x7F\x36\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x4D\x08\x8B\x15\x00\x00\x00\x00\x83";
				static const char *useMask = "xxxxxxxxxxxxx????x????xxxxx????x";
			}

			namespace AddChatMessage
			{
				static const BYTE *byteMask = (const BYTE *)"\x8B\x15\x00\x00\x00\x00\x68\x00\x00\x00\x00\x52\xE8\x00\x00\x00\x00\x83\xC4\x08\x5F\x5E";
				static const char *useMask = "xx????x????xx????xxxxx";
			}

			namespace GetPlayerNameByID
			{
				// X86 ASM-Code
				// push    edi
				// push    edi
				// mov     ecx, ebx
				// call    sub_10011ED0 <-- -> GetPlayerNameByID
				// push    eax

				// HEX-Code
				// 57
				// 57
				// 8B CB
				// E8 00 00 00 00
				// 50

				static const BYTE *byteMask = (const BYTE *)"\x57\x57\x8B\xCB\xE8\x00\x00\x00\x00\x50";
				static const char *useMask = "xxxxx????x";
			}

			namespace UpdatePlayerData
			{
				// From 0.3z R2
				// X86 ASM-Code
				// .text:10067FFE mov ecx, dword_10212AB8 <-- -> UpdatePlayerData object pointer
				// .text:10068004 call sub_10007C50 <-- -> UpdatePlayerData


				// HEX-Code
				// 8B 0D B8 2A 21 10
				// E8 47 FC F9 FF

				static const BYTE *byteMask = (const BYTE *)"\x8B\x0D\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x8B\x7E\x18";
				static const char *useMask = "xx????x????xx????xxx";
			}

			namespace Input
			{
				static const BYTE *byteMask = (const BYTE *)"\x8B\x0D\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x8B\x0D\x00\x00\x00\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\xE8";
				static const char *useMask = "xx????x????x????xx????x????x????x";
			}

			namespace ShowDialog
			{
				static const BYTE *byteMask = (const BYTE *)"\x8B\x0D\x00\x00\x00\x00\x8B\x41\x28\x85\xC0\x75\x1F\x6A\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x68\x00\x00\x00\x00\x68\x00";
				static const char *useMask = "xx????xxxxxxxxxx????x????x????x?";
			}
		}
	}
}
