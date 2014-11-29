#pragma once
#include <boost/optional.hpp>
#include <type_traits>

namespace core
{
	namespace common
	{
		template
		<
			typename Pred, 
			typename ...Args,
			typename RetType = boost::optional<std::result_of<Pred(Args...)>::type>
		>
		RetType call_safe(Pred f, Args&&... params)
		{
			try {
				return f(params...);
			}
			catch (...){
				return nullptr;
			}
		}

		template<typename Pred>
		inline bool call_safe_inline(Pred f)
		{
			try{
				f();
			}
			catch (...){
				return false;
			}

			return true;
		}
	}
}
