#pragma once

#include <qwr/pfc_helpers_cfg.h>

#include <mutex>

namespace qwr::fb2k
{

template <typename T, typename InnerT, typename = void>
class Config
{
public:
    using value_type = typename InnerT;

    template <typename ArgT>
    Config( const GUID& guid, const ArgT& defaultValue ) requires std::is_convertible_v<ArgT, InnerT>
        : config_( guid, defaultValue )
        , defaultValue_( defaultValue )
    {
    }
    ~Config() = default;

    Config( const Config& ) = delete;

    template <typename ArgT>
    Config& operator=( const ArgT& value ) requires std::is_convertible_v<ArgT, InnerT>
    {
        config_ = value;
        return *this;
    }

    operator InnerT() const
    {
        return GetValue();
    }

    const InnerT GetValue() const
    {
        return config_;
    }

    const InnerT& GetDefaultValue() const
    {
        return defaultValue_;
    }

    void Reset()
    {
        config_ = defaultValue_;
    }

private:
    T config_;
    const InnerT defaultValue_;
};

template <typename T, typename EnumType>
requires std::is_enum_v<EnumType>
class Config<T, EnumType>
{
    using UnderlyingT = std::underlying_type_t<EnumType>;

public:
    using value_type = typename EnumType;

    Config( const GUID& guid, const EnumType& defaultValue )
        : config_( guid, static_cast<UnderlyingT>( defaultValue ) )
        , defaultValue_( static_cast<UnderlyingT>( defaultValue ) )
    {
    }
    ~Config() = default;

    Config( const Config& ) = delete;

    template <typename ArgT>
    Config& operator=( const ArgT& value ) requires std::is_convertible_v<ArgT, EnumType>
    {
        config_ = static_cast<UnderlyingT>( value );
        return *this;
    }

    operator EnumType() const
    {
        return GetValue();
    }

    const EnumType GetValue() const
    {
        return static_cast<EnumType>( static_cast<UnderlyingT>( config_ ) );
    }

    const EnumType GetDefaultValue() const
    {
        return static_cast<EnumType>( defaultValue_ );
    }

    void Reset()
    {
        config_ = defaultValue_;
    }

private:
    T config_;
    const UnderlyingT defaultValue_;
};

using ConfigString = Config<qwr::pfc_x::cfg_std_string, std::string>;
using ConfigBool = Config<cfg_var_legacy::cfg_bool, bool>;
using ConfigUint8 = Config<cfg_var_legacy::cfg_int_t<uint8_t>, uint8_t>;
using ConfigUint32 = Config<cfg_var_legacy::cfg_int_t<uint32_t>, uint32_t>;
template <typename T>
using ConfigUint8Enum = Config<cfg_var_legacy::cfg_int_t<uint8_t>, T>;

template <typename T, typename InnerT>
class Config_MT
{
public:
    using value_type = typename Config<T, InnerT>::value_type;

    template <typename ArgT>
    Config_MT( const GUID& guid, const ArgT& defaultValue ) requires std::is_convertible_v<ArgT, InnerT>
        : config_( guid, defaultValue )
    {
    }
    ~Config_MT() = default;

    Config_MT( const Config_MT& ) = delete;

    template <typename ArgT>
    Config_MT& operator=( const ArgT& value ) requires std::is_convertible_v<ArgT, InnerT>
    {
        std::lock_guard lg( mutex_ );
        config_ = value;
        return *this;
    }

    operator InnerT() const
    {
        std::mutex mutex_;
        return config_;
    }

    const InnerT GetValue() const
    {
        return config_.GetValue();
    }

    const InnerT GetDefaultValue() const
    {
        return config_.GetDefaultValue();
    }

    void Reset()
    {
        std::mutex mutex_;
        config_.Reset();
    }

private:
    std::mutex mutex_;
    Config<T, InnerT> config_;
};

using ConfigString_MT = Config_MT<qwr::pfc_x::cfg_std_string, std::string>;
using ConfigBool_MT = Config_MT<cfg_var_legacy::cfg_bool, bool>;
using ConfigUint8_MT = Config_MT<cfg_var_legacy::cfg_int_t<uint8_t>, uint8_t>;
using ConfigUint32_MT = Config_MT<cfg_var_legacy::cfg_int_t<uint32_t>, uint32_t>;
template <typename T>
using ConfigUint8Enum_MT = Config_MT<cfg_var_legacy::cfg_int_t<uint8_t>, T>;

} // namespace qwr::fb2k
