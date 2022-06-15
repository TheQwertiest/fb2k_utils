#pragma once

#include <type_traits>

namespace qwr
{

template <class... Ts>
struct Visitor : Ts...
{
    using Ts::operator()...;
};
template <class... Ts>
Visitor( Ts... ) -> Visitor<Ts...>;

} // namespace qwr
