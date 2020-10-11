#pragma once

#include <qwr/fb2k_config.h>
#include <qwr/ui_option.h>
#include <qwr/type_traits.h>

namespace qwr
{

namespace ui
{

template <typename T>
class UiOption<T,
               std::enable_if_t<
                   ( qwr::isSpecializationOfV<T, fb2k::Config> || qwr::isSpecializationOfV < T, fb2k::Config_MT> ) && !std::is_enum_v<typename T::value_type>>>
    : public IUiOption
{
public:
    using config_type = typename T;
    using value_type = typename T::value_type;

public:
    UiOption( config_type& config )
        : config_( config )
        , curValue_( static_cast<value_type>( config ) )
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
        hasChanged_ = ( static_cast<value_type>( config_) != value );
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
        SetValue( config_.GetDefaultValue() );
    }

private:
    config_type& config_;
    value_type curValue_{};
    bool hasChanged_ = false;
};

template <typename T>
class UiOption<T,
               std::enable_if_t<
                   (qwr::isSpecializationOfV<T, fb2k::Config> || qwr::isSpecializationOfV<T, fb2k::Config_MT>)&&std::is_enum_v<typename T::value_type>>>
    : public IUiOption
{
public:
    using config_type = typename T;
    using enum_type = typename T::value_type;
    using value_type = std::underlying_type_t<typename enum_type>;

public:
    UiOption( config_type& config )
        : config_( config )
        , curValue_( static_cast<value_type>( static_cast<enum_type>( config ) ) )
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
        hasChanged_ = ( static_cast<value_type>(static_cast<enum_type>( config_ )) != value );
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
            config_ = static_cast<enum_type>(curValue_);
            hasChanged_ = false;
        }
    }

    void Revert() override
    {
        if ( hasChanged_ )
        {
            curValue_ = static_cast<value_type>(static_cast<enum_type>( config_ ));
            hasChanged_ = false;
        }
    }

    void ResetToDefault() override
    {
        SetValue( static_cast<value_type>( config_.GetDefaultValue()) );
    }

private:
    config_type& config_;
    value_type curValue_{};
    bool hasChanged_ = false;
};

} // namespace ui

} // namespace qwr
