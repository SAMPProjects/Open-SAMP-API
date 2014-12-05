#pragma once
#include <boost/any.hpp>
#include <cstdint>
#include <functional>
#include <map>

namespace core
{
	namespace client
	{
		namespace callbacks
		{
			namespace internal
			{
				template<typename Ret, typename ...Args>
				struct stdcall_type
				{
					typedef Ret(__stdcall *type)(Args...);
				};

				template<typename Ret, typename ...Args>
				struct cdecl_type
				{
					typedef Ret(__cdecl *type)(Args...);
				};

				template
				<
					template <class, class...> class convention_policy,
					typename Ret,
					typename ...Args
				>
				struct convention_type;

				template
				<
					template <class, class...> class convention_policy,
					typename Ret,
					typename ...Args
				>
				struct convention_type < convention_policy, Ret(Args...) >
				{
					typedef typename convention_policy<Ret, Args...>::type type;
				};

				template<typename Ret, typename ...Args>
				struct dynamic_convention;

				template<typename Ret, typename ...Args>
				struct dynamic_convention < Ret(Args...) >
				{
					template<typename T>
					inline std::function<Ret(Args...)> operator()(T f, bool is_cdecl)
					{
						if (is_cdecl)
							return (convention_type<cdecl_type, Ret(Args...)>::type) f;
						return (convention_type<stdcall_type, Ret(Args...)>::type) f;
					}
				};
			}

			enum class type : int
			{
				on_connect,
				on_disconnect,
				on_fail
			};

			class callbacks
			{
			public:
				typedef std::map<type, boost::any> map_type;

				bool set_callback_for_id(type id, uint32_t func, bool is_cdecl);
				bool unset_callback_for_id(type id);

			private:
				map_type callbacks_;
			};
		}
	}
}