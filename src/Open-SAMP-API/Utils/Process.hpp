#pragma once
#include <string>

namespace Utils
{
	namespace Process
	{
		unsigned long pidByProcessName(const std::string&);
		unsigned long pidByWindowName(const std::string&);
	}
}
