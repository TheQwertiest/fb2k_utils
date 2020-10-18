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

    operator InnerT() const
    {
        return GetValue();
    }

    InnerT GetValue() const
    {
        if constexpr ( std::is_same_v<InnerT, std::string> )
        {
            pfc::string8_fast value;
            config_.get( value );
            return value.c_str();
        }
        else
        {
            return config_.get();
        }
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

    operator InnerT() const
    {
        std::mutex mutex_;
        return config_;
    }

    InnerT GetValue() const
    {
        std::mutex mutex_;
        return config_.GetValue();
    }

private:
    mutable std::mutex mutex_;
    mutable AdvConfig<T, InnerT> config_;
};

using AdvConfigString_MT = AdvConfig<advconfig_string_factory_MT, std::string>;
using AdvConfigBool_MT = AdvConfig_MT<advconfig_checkbox_factory, bool>;

} // namespace qwr::fb2k
