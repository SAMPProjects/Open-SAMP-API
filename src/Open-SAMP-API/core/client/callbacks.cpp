#include "callbacks.hpp"
#include <core/common/safe_call.hpp>

bool core::client::callbacks::callbacks::set_callback_for_id(core::client::callbacks::type id, uint32_t func, bool is_cdecl)
{
	bool success = true;

	return common::call_safe_inline([&]()
	{
		switch (id)
		{
		case type::on_connect:
			callbacks_[id] = internal::dynamic_convention<void(void)>()(func, is_cdecl);
			break;
		case type::on_disconnect:
			callbacks_[id] = internal::dynamic_convention<void(void)>()(func, is_cdecl);
			break;
		case type::on_fail:
			callbacks_[id] = internal::dynamic_convention<void(void)>()(func, is_cdecl);
			break;

		default:
			success = false;
			break;
		}
	}) && success;
}

bool core::client::callbacks::callbacks::unset_callback_for_id(core::client::callbacks::type id)
{
	return callbacks_.erase(id);
}
