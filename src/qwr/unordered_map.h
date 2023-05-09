#pragma once

#include <unordered_map>
#include <string>

namespace qwr
{

    namespace impl
{

struct StringHash
{
    using hash_type = std::hash<std::string_view>;
    using is_transparent = void;

    std::size_t operator()( const char* str ) const
    {
        return hash_type{}( str );
    }
    std::size_t operator()( std::string_view str ) const
    {
        return hash_type{}( str );
    }
    std::size_t operator()( const std::string& str ) const
    {
        return hash_type{}( str );
    }
};

} // namespace impl

template <typename K, typename V>
using UnorderedStrMap = std::unordered_map<K, V, qwr::impl::StringHash, std::equal_to<>>;

} // namespace qwr
