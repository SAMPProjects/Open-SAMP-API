#pragma once
#include <cstdint>
#include <core/client/callbacks.hpp>

#define EXPORT extern "C" __declspec(dllexport)


enum class eLoadAPIIntoRemoteProcessResult : int
{
	success,
	invalid_api_module,
	gta_not_found,
	pid_error,
	invalid_gta_handle,
	remote_allocation_failed,
	write_process_memory_failed,
	get_proc_address_failed,
	create_remote_thread_failed
};

EXPORT eLoadAPIIntoRemoteProcessResult LoadAPIIntoRemoteProcess();


EXPORT void RegisterCallback(core::client::callbacks::type id, uint32_t address);
EXPORT void UnregisterCallback(core::client::callbacks::type id);