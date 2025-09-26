module;

#include <type_traits>

export module aspire.core.concepts;

export namespace aspire::core
{
	template <typename T>
	concept TypeEnum = std::is_enum_v<T>;
}
