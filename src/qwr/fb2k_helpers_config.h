#pragma once

#include <qwr/ui_option.h>

#include <mutex>

namespace qwr
{

template <typename T, typename InnerT>
class Config_MT
{
public:
    template <typename ArgT, class = typename std::enable_if_t<std::is_convertible_v<ArgT, InnerT>>>
    Config_MT( const GUID& guid, const ArgT& defaultValue )
        : config_( guid, defaultValue )
        , defaultValue_( defaultValue )
    {
    }
    ~Config_MT() = default;

    Config_MT( const Config_MT& ) = delete;

    template <typename ArgT, class = typename std::enable_if_t<std::is_convertible_v<ArgT, InnerT>>>
    Config_MT& operator=( const ArgT& value )
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

    const InnerT& GetDefaultValue() const
    {
        return defaultValue_;
    }

    void Reset()
    {
        std::mutex mutex_;
        config_ = defaultValue_;
    }

private:
    std::mutex mutex_;
    T config_;
    const InnerT defaultValue_;
};

using ConfigString8_MT = Config_MT<cfg_string, pfc::string8_fast>;
using ConfigBool_MT = Config_MT<cfg_bool, bool>;
using ConfigUint8_MT = Config_MT<cfg_int_t<uint8_t>, uint8_t>;

namespace ui
{

template <typename T, typename InnerT>
class UiOption<Config_MT<T, InnerT>>
    : public IUiOption
{
public:
    using config_type = Config_MT<T, InnerT>;
    using value_type = typename InnerT;

public:
    UiOption( config_type& config )
        : config_( config )
        , curValue_( static_cast<value_type>( config )  )
    {
    }

    UiOption( const UiOption& ) = delete;

    UiOption& operator=( const value_type& value )
    {
        SetValue( value );
        return *this;
    }

    operator value_type() const
    {
        return GetCurrentValue();
    }

    value_type GetSavedValue() const
    {
        return static_cast<value_type>( config_ );
    }

    const value_type& GetCurrentValue() const
    {
        return curValue_;
    }

    void SetValue( const value_type& value )
    {
        curValue_ = value;
        hasChanged_ = ( config_ != value );
    }

    // > IOptionWrap

    bool HasChanged() const override
    {
        return hasChanged_;
    }

    void Apply() override
    {
        if ( hasChanged_ )
        {
            config_ = curValue_;
            hasChanged_ = false;
        }
    }

    void Revert() override
    {
        if ( hasChanged_ )
        {
            curValue_ = config_;
            hasChanged_ = false;
        }
    }

    void ResetToDefault() override
    {
        SetValue( config_.GetDefaultValue());
    }

private:
    config_type& config_;
    value_type curValue_{};
    bool hasChanged_ = false;
};

} // namespace ui

} // namespace qwr
