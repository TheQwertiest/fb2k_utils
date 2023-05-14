#pragma once

#include <optional>

namespace qwr
{

template <typename T, typename V>
auto FindAsPointer( T& map, const V& value )
{
    auto it = map.find( value );
    return ( it != map.end() ? &it->second : nullptr );
}

template <typename T, typename V>
auto FindAsOptional( T& map, const V& value )
{
    std::optional<typename std::remove_cvref_t<T>::mapped_type> ret;
    if ( auto it = map.find( value );
         it != map.end() )
    {
        ret = it->second;
    }
    return ret;
}

} // namespace qwr
