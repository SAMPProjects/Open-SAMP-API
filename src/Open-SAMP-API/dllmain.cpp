#include <core/common/windows.hpp>
#include <core/server/server.hpp>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReasonForCall, LPVOID)
{
	DisableThreadLibraryCalls((HMODULE)hInstance);

	if (core::server::is_server())
	{

	}

	return TRUE;
}