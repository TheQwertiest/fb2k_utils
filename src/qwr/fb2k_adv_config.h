#pragma once

#include <mutex>
#include <string>

namespace qwr::fb2k
{

template <typename T, typename InnerT, typename = void>
class AdvConfig
{
public:
    using value_type = typename InnerT;

    template <typename... Args>
    AdvConfig( Args&&... args )
        : config_( std::forward<Args>( args )... )
    {
    }
    ~AdvConfig() = default;

    AdvConfig( const AdvConfig& ) = delete;

    operator value_type() const
    {
        return GetValue();
    }

    value_type GetValue() const
    {
        if constexpr ( std::is_same_v<value_type, std::string> )
        {
            pfc::string8_fast value;
            config_.get( value );
            return value.c_str();
        }
        else
        {
            return static_cast<value_type>( config_.get() );
        }
    }

    template <typename ArgT, std::enable_if_t<std::is_convertible_v<ArgT, value_type>, int> = 0>
    AdvConfig& operator=( const ArgT& value )
    {
        config_ = value;
        return *this;
    }

private:
    mutable T config_;
};

using AdvConfigString = AdvConfig<advconfig_string_factory, std::string>;
using AdvConfigBool = AdvConfig<advconfig_checkbox_factory, bool>;

template <typename T, typename InnerT>
class AdvConfig_MT
{
public:
    using value_type = typename AdvConfig<T, InnerT>::value_type;

    template <typename... Args>
    AdvConfig_MT( Args&&... args )
        : config_( std::forward<Args>( args )... )
    {
    }
    ~AdvConfig_MT() = default;

    AdvConfig_MT( const AdvConfig_MT& ) = delete;

    operator value_type() const
    {
        std::mutex mutex_;
        return config_;
    }

    value_type GetValue() const
    {
        std::mutex mutex_;
        return config_.GetValue();
    }

    template <typename ArgT, std::enable_if_t<std::is_convertible_v<ArgT, value_type>, int> = 0>
    AdvConfig_MT& operator=( const ArgT& value )
    {
        std::mutex mutex_;
        config_ = value;
        return *this;
    }

private:
    mutable std::mutex mutex_;
    mutable AdvConfig<T, value_type> config_;
};

using AdvConfigString_MT = AdvConfig<advconfig_string_factory_MT, std::string>;
using AdvConfigBool_MT = AdvConfig_MT<advconfig_checkbox_factory, bool>;
using AdvConfigUint8_MT = AdvConfig_MT<advconfig_integer_factory, uint8_t>;
using AdvConfigUint32_MT = AdvConfig_MT<advconfig_integer_factory, uint32_t>;

} // namespace qwr::fb2k
