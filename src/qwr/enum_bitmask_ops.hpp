#pragma once

#include <qwr/utility.h>

template <typename T>
constexpr bool qwr_enable_bitmask_ops( T )
{
    return false;
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T operator|( T lhs, T rhs )
{
    return static_cast<T>( qwr::to_underlying( lhs ) | qwr::to_underlying( rhs ) );
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T operator&( T lhs, T rhs )
{
    return static_cast<T>( qwr::to_underlying( lhs ) & qwr::to_underlying( rhs ) );
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T operator^( T lhs, T rhs )
{
    return static_cast<T>( qwr::to_underlying( lhs ) ^ qwr::to_underlying( rhs ) );
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T operator~( T lhs )
{
    return static_cast<T>( ~qwr::to_underlying( lhs ) );
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T& operator|=( T& lhs, T rhs )
{
    lhs = static_cast<T>( qwr::to_underlying( lhs ) | qwr::to_underlying( rhs ) );
    return lhs;
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T& operator&=( T& lhs, T rhs )
{
    lhs = static_cast<T>( qwr::to_underlying( lhs ) & qwr::to_underlying( rhs ) );
    return lhs;
}

template <typename T>
    requires( qwr_enable_bitmask_ops( T() ) )
T& operator^=( T& lhs, T rhs )
{
    lhs = static_cast<T>( qwr::to_underlying( lhs ) ^ qwr::to_underlying( rhs ) );
    return lhs;
}

#define QWR_ENABLE_BIT_OPS( T )                \
    constexpr bool qwr_enable_bitmask_ops( T ) \
    {                                          \
        return true;                           \
    }
