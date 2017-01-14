#pragma comment(lib, "../../../../bin/Open-SAMP-API.lib")

#include "../../../../include/C++/SAMP_API.h"
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class TextOverlay
{
	int _id = -1;
public:
	~TextOverlay()
	{
		destroy();
	}

	bool create()
	{
		if (_id != -1)
			return false;

		return (_id = TextCreate("Arial", 20, false, false, 400, 400, 0xFFFFFFFF, "Hello world with {FF333333}umlauts!\n{FF00FF}ÄäÖö{333333}Üü", true, true)) != -1;
	}

	bool destroy()
	{
		if (_id == -1)
			return false;

		bool bRes = TextDestroy(_id) == 1;
		_id = -1;

		return bRes;
	}

	operator int()
	{
		return _id;
	}
};

int main()
{
	TextOverlay overlay;

	SetParam("use_window", "1");
	SetParam("window", "GTA:SA:MP");

	for (;; Sleep(50)) 
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			SendChat("Hello with umlauts: äöü");
			SendChat("/Hello");
		}

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			ShowGameText("Hello world", 2000, 3);
		}

		if (GetAsyncKeyState(VK_NUMPAD3))
		{
			AddChatMessage("Hello world");
			AddChatMessage("{ff0000}Hello {00ff00}world");
		}

		if (GetAsyncKeyState(VK_NUMPAD4))
		{
			overlay.create();
		}

		if (GetAsyncKeyState(VK_NUMPAD5))
		{
			overlay.destroy();
		}

		if (GetAsyncKeyState(VK_F12))
			break;
	}

	std::cin.get();
}