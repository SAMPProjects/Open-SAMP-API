#pragma once
#include <cstdint>

#define EXPORT extern "C" __declspec(dllexport)

enum class eCallback : int
{
	on_connect,
	on_disconnect,
	on_fail
};

EXPORT void RegisterCallback(eCallback id, uint32_t address);
EXPORT void UnregisterCallback(eCallback id);