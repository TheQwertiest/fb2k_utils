#pragma once

#include <type_traits>

namespace qwr
{

template <typename, template <typename...> class>
inline constexpr bool isSpecializationOfV = false;

template <template <typename...> class T, typename... Args>
inline constexpr bool isSpecializationOfV<T<Args...>, T> = true;

} // namespace qwr::internal
