#pragma once
#include "Client.hpp"

EXPORT int SendChat(const char *msg);
EXPORT int ShowGameText(const char *msg, int time, int style);
EXPORT int AddChatMessage(const char *msg);
