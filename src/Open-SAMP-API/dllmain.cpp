#include <core/common/windows.hpp>
#include <core/server/server.hpp>
#include <core/common/string.hpp>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReasonForCall, LPVOID)
{
	DisableThreadLibraryCalls((HMODULE)hInstance);

	if (dwReasonForCall != DLL_PROCESS_ATTACH)
		return TRUE;

	if (core::server::is_server())
	{
		try
		{

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

	return TRUE;
}