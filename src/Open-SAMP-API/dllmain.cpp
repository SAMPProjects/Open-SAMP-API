#include <core/common/windows.h>

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReasonForCall, LPVOID)
{
	DisableThreadLibraryCalls((HMODULE)hInstance);
	return TRUE;
}