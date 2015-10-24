#include "Game.hpp"
#include "Messagehandler.hpp"
#include "SAMP/SAMP.hpp"
#include "SAMP/RemotePlayer.hpp"
#include "Rendering/Renderer.hpp"
#include <Utils/Windows.hpp>
#include <Utils/Hook.hpp>
#include <Utils/Pattern.hpp>
#include <Utils/PipeServer.hpp>
#include <Utils/D3DX9/d3dx9.h>
#include <thread>

#define BIND(T) PaketHandler[Shared::PipeMessages::T] = std::bind(Game::MessageHandler::T, std::placeholders::_1, std::placeholders::_2);

Utils::Hook::Hook<Utils::Hook::CallConvention::stdcall_t, HRESULT, LPDIRECT3DDEVICE9, CONST RECT *, CONST RECT *, HWND, CONST RGNDATA *> g_presentHook;
Utils::Hook::Hook<Utils::Hook::CallConvention::stdcall_t, HRESULT, LPDIRECT3DDEVICE9, D3DPRESENT_PARAMETERS *> g_resetHook;

bool g_bEnabled = false;

extern "C" __declspec(dllexport) void enable()
{
	g_bEnabled = true;
}

void initGame()
{
	// initialize DirectX stuff
	{
		HMODULE hMod = NULL;

		while ((hMod = GetModuleHandle("d3d9.dll")) == NULL || g_bEnabled == false)
			Sleep(200);

		DWORD *vtbl = 0;
		DWORD dwDevice = Utils::Pattern::findPattern((DWORD)hMod, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
		memcpy(&vtbl, (void *)(dwDevice + 0x2), 4);

		g_presentHook.apply(vtbl[17], [](LPDIRECT3DDEVICE9 dev, CONST RECT * a1, CONST RECT * a2, HWND a3, CONST RGNDATA *a4) -> HRESULT
		{
			__asm pushad
			Game::Rendering::Renderer::sharedRenderer().draw(dev);
			__asm popad

			return g_presentHook.callOrig(dev, a1, a2, a3, a4);
		});

		g_resetHook.apply(vtbl[16], [](LPDIRECT3DDEVICE9 dev, D3DPRESENT_PARAMETERS *pp) -> HRESULT
		{
			__asm pushad
			Game::Rendering::Renderer::sharedRenderer().reset(dev);
			__asm popad

			return g_resetHook.callOrig(dev, pp);
		});
	}
	
	// initialize SAMP
	{
		while (GetModuleHandleA("samp.dll") == NULL)
			Sleep(50);

		Game::SAMP::initSAMP();
	}
	
	// initialize RPC
	typedef std::map<Shared::PipeMessages, std::function<void(Utils::Serializer&, Utils::Serializer&)> > MessagePaketHandler;
	MessagePaketHandler PaketHandler;
	{
		BIND(TextCreate);
		BIND(TextDestroy);
		BIND(TextSetShadow);
		BIND(TextSetShown);
		BIND(TextSetColor);
		BIND(TextSetPos);
		BIND(TextSetString);
		BIND(TextUpdate);

		BIND(BoxCreate);
		BIND(BoxDestroy);
		BIND(BoxSetShown);
		BIND(BoxSetBorder);
		BIND(BoxSetBorderColor);
		BIND(BoxSetColor);
		BIND(BoxSetHeight);
		BIND(BoxSetPos);
		BIND(BoxSetWidth);

		BIND(LineCreate);
		BIND(LineDestroy);
		BIND(LineSetShown);
		BIND(LineSetColor);
		BIND(LineSetWidth);
		BIND(LineSetPos);

		BIND(ImageCreate);
		BIND(ImageDestroy);
		BIND(ImageSetShown);
		BIND(ImageSetAlign);
		BIND(ImageSetPos);
		BIND(ImageSetRotation);

		BIND(DestroyAllVisual);
		BIND(ShowAllVisual);
		BIND(HideAllVisual);

		BIND(GetFrameRate);
		BIND(GetScreenSpecs);

		BIND(SetCalculationRatio);
		BIND(SetOverlayPriority);
		BIND(SetOverlayCalculationEnabled);

        BIND(GetGTACommandLine);

		BIND(SendChat);
		BIND(ShowGameText);
		BIND(AddChatMessage);
		BIND(GetPlayerNameByID);
		BIND(IsChatOpen);
		BIND(IsDialogOpen);

		BIND(ReadMemory);

		BIND(WorldToScreen);

		new Utils::PipeServer([&](Utils::Serializer& serializerIn, Utils::Serializer& serializerOut)
		{
			SERIALIZATION_READ(serializerIn, Shared::PipeMessages, eMessage);

			try
			{
				auto it = PaketHandler.find(eMessage);
				if (it == PaketHandler.end())
					return;

				if (!PaketHandler[eMessage])
					return;

				PaketHandler[eMessage](serializerIn, serializerOut);
			}
			catch (...)
			{
			}
		});
	}

	while (true){
		Sleep(100);
	}
}
