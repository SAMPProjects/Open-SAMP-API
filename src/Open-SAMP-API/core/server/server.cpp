#include "server.hpp"
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/compare.hpp>

bool core::server::is_server()
{
	TCHAR buf[MAX_PATH + 1] = { 0 };
	GetModuleFileName(0, buf, MAX_PATH);

	return GetModuleHandle("samp.dll") && boost::algorithm::ifind_first(buf, "gta");
}