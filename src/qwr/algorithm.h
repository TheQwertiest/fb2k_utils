#pragma once

#include <optional>

namespace qwr
{

template <typename T, typename K>
auto FindAsPointer( T& map, const K& key )
{
    auto it = map.find( key );
    return ( it != map.end() ? &it->second : nullptr );
}

template <typename T, typename K>
auto FindAsOptional( T& map, const K& key )
{
    std::optional<typename std::remove_cvref_t<T>::mapped_type> ret;
    if ( auto it = map.find( key );
         it != map.end() )
    {
        ret = it->second;
    }
    return ret;
}

template <typename T, typename K, typename D>
auto FindOrDefault( T& map, const K& key, D&& defaultValue )
{
    using ValueT = typename std::remove_cvref_t<T>::mapped_type;

    auto it = map.find( key );
    return ( it != map.end() ? it->second : ValueT{std::forward<D>(defaultValue)} );
}

} // namespace qwr
