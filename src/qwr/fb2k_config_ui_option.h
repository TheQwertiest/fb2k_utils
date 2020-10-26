#pragma once

#include <qwr/fb2k_config.h>
#include <qwr/type_traits.h>
#include <qwr/ui_option.h>

#include <unordered_map>

namespace qwr
{

namespace ui
{

template <typename T>
class UiOption<T,
               std::enable_if_t<
                   (qwr::is_specialization_of_v<T, fb2k::Config> || qwr::is_specialization_of_v<T, fb2k::Config_MT>)&&!std::is_enum_v<typename T::value_type>>>
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

    template <typename U = T,
              std::enable_if_t<
                  std::is_convertible_v<typename U::value_type, int> && !std::is_same_v<typename U::value_type, int>, int> = 0>
    UiOption& operator=( int value )
    {
        SetValue( static_cast<value_type>( value ) );
        return *this;
    }

    operator value_type() const
    {
        return GetCurrentValue();
    }

    template <typename U = T,
              std::enable_if_t<
                  std::is_convertible_v<typename U::value_type, int> && !std::is_same_v<typename U::value_type, int>, int> = 0>
    explicit operator int() const
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
        hasChanged_ = ( static_cast<value_type>( config_ ) != value );
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
                   (qwr::is_specialization_of_v<T, fb2k::Config> || qwr::is_specialization_of_v<T, fb2k::Config_MT>)&&std::is_enum_v<typename T::value_type>>>
    : public IUiOption
{
public:
    using config_type = typename T;
    using enum_type = typename T::value_type;
    using value_type = int;

public:
    UiOption( config_type& config, const std::unordered_map<enum_type, int>& enum_to_id )
        : config_( config )
        , curValue_( enum_to_id.at( static_cast<enum_type>( config ) ) )
        , enum_to_id_( enum_to_id )
    {
        for ( const auto [e, i]: enum_to_id_ )
        {
            id_to_enum_.try_emplace( i, e );
        }
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

    const enum_type& GetCurrentEnum() const
    {
        return id_to_enum_.at( curValue_ );
    }

    void SetValue( const value_type& value )
    {
        curValue_ = value;
        hasChanged_ = ( static_cast<enum_type>( config_ ) != id_to_enum_.at( value ) );
    }

    void SetValue( const enum_type& value )
    {
        SetValue( enum_to_id_.at( value ) );
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
            config_ = id_to_enum_.at( curValue_ );
            hasChanged_ = false;
        }
    }

    void Revert() override
    {
        if ( hasChanged_ )
        {
            curValue_ = enum_to_id_.at( static_cast<enum_type>( config_ ) );
            hasChanged_ = false;
        }
    }

    void ResetToDefault() override
    {
        SetValue( static_cast<value_type>( config_.GetDefaultValue() ) );
    }

private:
    config_type& config_;
    value_type curValue_{};
    bool hasChanged_ = false;

    std::unordered_map<enum_type, int> enum_to_id_;
    std::unordered_map<int, enum_type> id_to_enum_;
};

} // namespace ui

} // namespace qwr
