#include "exports.hpp"
#include <dllmain.hpp>
#include <core/client/client.hpp>
#include <core/common/windows.hpp>
#include <boost/scope_exit.hpp>

EXPORT eLoadAPIIntoRemoteProcessResult LoadAPIIntoRemoteProcess()
{
	HANDLE hHandle = INVALID_HANDLE_VALUE;
	HANDLE hThread = INVALID_HANDLE_VALUE;
	LPVOID pAddr = NULL;
	char szDllPath[MAX_PATH + 1] = { 0 };

	BOOST_SCOPE_EXIT_ALL(&)
	{
		if (hThread != INVALID_HANDLE_VALUE)
		{
			WaitForSingleObject(hThread, INFINITE);
			CloseHandle(hThread);
		}

		if (pAddr != NULL)
			VirtualFreeEx(hHandle, pAddr, strlen(szDllPath) + 1, MEM_RELEASE);

		if (hHandle != INVALID_HANDLE_VALUE)
			CloseHandle(hHandle);
	};

	if (!GetModuleFileNameA(dllmain::get_main_handle(), szDllPath, MAX_PATH))
		return eLoadAPIIntoRemoteProcessResult::invalid_api_module;

	HWND hGTAHwnd;
	if (!(hGTAHwnd = FindWindowA(0, "GTA:SA:MP")))
		return eLoadAPIIntoRemoteProcessResult::gta_not_found;

	DWORD dwPID = 0;
	GetWindowThreadProcessId(hGTAHwnd, &dwPID);
	if (dwPID == 0)
		return eLoadAPIIntoRemoteProcessResult::pid_error;

	if ((hHandle = OpenProcess((STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF), FALSE, dwPID)) == INVALID_HANDLE_VALUE)
		return eLoadAPIIntoRemoteProcessResult::invalid_gta_handle;

	if (!(pAddr = VirtualAllocEx(hHandle, NULL, strlen(szDllPath) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)))
		return eLoadAPIIntoRemoteProcessResult::remote_allocation_failed;

	if (!WriteProcessMemory(hHandle, pAddr, szDllPath, strlen(szDllPath) + 1, NULL))
		return eLoadAPIIntoRemoteProcessResult::write_process_memory_failed;

	LPTHREAD_START_ROUTINE pFunc = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
	if (pFunc == NULL)
		return eLoadAPIIntoRemoteProcessResult::get_proc_address_failed;

	if (!(hThread = CreateRemoteThread(hHandle, NULL, NULL, pFunc, pAddr, 0, NULL)))
		return eLoadAPIIntoRemoteProcessResult::create_remote_thread_failed;

	return eLoadAPIIntoRemoteProcessResult::success;
}

EXPORT bool RegisterCallback(core::client::callbacks::type id, uint32_t address, bool is_cdecl)
{
	return core::client::client::singleton().callbacks().set_callback_for_id(id, address, is_cdecl);
}

EXPORT bool UnregisterCallback(core::client::callbacks::type id)
{
	return core::client::client::singleton().callbacks().unset_callback_for_id(id);
}

