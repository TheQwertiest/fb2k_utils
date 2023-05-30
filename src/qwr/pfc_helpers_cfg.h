#pragma once

#include <string_view>

namespace qwr::pfc_x
{

class cfg_std_string : public cfg_var_legacy::cfg_var
{
public:
    cfg_std_string( const GUID& p_guid, qwr::u8string_view p_defaultval );

    cfg_std_string& operator=( const cfg_std_string& p_val );
    cfg_std_string& operator=( qwr::u8string_view p_val );

    operator const qwr::u8string&() const;

protected:
    // cfg_var
    void get_data_raw( stream_writer* p_stream, abort_callback& p_abort ) override;
    void set_data_raw( stream_reader* p_stream, t_size p_sizehint, abort_callback& p_abort ) override;

private:
    qwr::u8string value_;
};

bool operator!=( const cfg_std_string& left, qwr::u8string_view right );
bool operator!=( qwr::u8string_view left, const cfg_std_string& right );
bool operator==( const cfg_std_string& left, qwr::u8string_view right );
bool operator==( qwr::u8string_view left, const cfg_std_string& right );

} // namespace qwr::pfc_x
