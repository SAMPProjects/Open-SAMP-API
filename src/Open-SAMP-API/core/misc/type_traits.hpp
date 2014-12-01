#pragma once

namespace core
{
	namespace misc
	{
		template<typename T, typename U>
		struct is_same;

		template<typename T>
		struct is_same < T, T >
		{
			typedef T type;
		};
	}
}