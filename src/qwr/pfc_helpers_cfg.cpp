#include <stdafx.h>

#include "pfc_helpers_cfg.h"

namespace qwr::pfc_x
{

cfg_std_string::cfg_std_string( const GUID& p_guid, qwr::u8string_view p_defaultval )
    : cfg_var( p_guid )
    , value_( p_defaultval.data(), p_defaultval.size() )
{
}

cfg_std_string& cfg_std_string::operator=( const cfg_std_string& p_val )
{
    value_ = p_val.value_;
    return *this;
}
cfg_std_string& cfg_std_string::operator=( qwr::u8string_view p_val )
{
    value_ = qwr::u8string( p_val.data(), p_val.size() );
    return *this;
}

cfg_std_string::operator const qwr::u8string&() const
{
    return value_;
}

void cfg_std_string::get_data_raw( stream_writer* p_stream, abort_callback& p_abort )
{
    WriteStringRaw( *p_stream, value_, p_abort );
}
void cfg_std_string::set_data_raw( stream_reader* p_stream, t_size p_sizehint, abort_callback& p_abort )
{
    value_ = ReadRawString( *p_stream, p_abort );
}

bool operator!=( const cfg_std_string& left, qwr::u8string_view right )
{
    return static_cast<qwr::u8string>( left ) != right;
}

bool operator!=( qwr::u8string_view left, const cfg_std_string& right )
{
    return right != left;
}

bool operator==( const cfg_std_string& left, qwr::u8string_view right )
{
    return static_cast<qwr::u8string>( left ) == right;
}

bool operator==( qwr::u8string_view left, const cfg_std_string& right )
{
    return right == left;
}

} // namespace qwr::pfc_x
