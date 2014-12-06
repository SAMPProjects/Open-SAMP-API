#include "dllmain.hpp"
#include <core/common/windows.hpp>
#include <core/server/server.hpp>
#include <core/server/api.hpp>
#include <core/client/client.hpp>
#include <string>

HMODULE g_mainHandle = 0;

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReasonForCall, LPVOID)
{
	g_mainHandle = (HMODULE)hInstance;
	DisableThreadLibraryCalls(g_mainHandle);

	if (dwReasonForCall != DLL_PROCESS_ATTACH)
		return TRUE;

	if (core::server::is_server())
	{
		try
		{
			core::server::api::singleton();
		}
		catch (const std::exception& e)
		{
			auto error = std::string("An error occured while initializing the API\n\"") + std::string(e.what()) + std::string("\"");
			MessageBoxA(0, error.c_str(), "Error", MB_ICONERROR | MB_OK);
		}
		catch (...)
		{
			MessageBoxA(0, "An unknown error occured while initializing the API", "Error", MB_ICONERROR | MB_OK);
		}
	}
	else
	{
		core::client::client::singleton();
	}
	return TRUE;
}

HMODULE dllmain::get_main_handle()
{
	return g_mainHandle;
}
