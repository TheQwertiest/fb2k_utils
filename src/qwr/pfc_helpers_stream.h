#pragma once

#include <string>
#include <string_view>

namespace qwr::pfc_x
{

qwr::u8string ReadString( stream_reader& stream, abort_callback& abort );
qwr::u8string ReadRawString( stream_reader& stream, abort_callback& abort );
void WriteString( stream_writer& stream, const qwr::u8string& val, abort_callback& abort );
void WriteStringRaw( stream_writer& stream, const qwr::u8string& val, abort_callback& abort );

} // namespace qwr::pfc_x

// `operator>>` and `operator<<` overloads for various fb2k SDK streams

FB2K_STREAM_READER_OVERLOAD( std::string )
{
    value = qwr::pfc_x::ReadString( stream.m_stream, stream.m_abort );
    return stream;
}

FB2K_STREAM_WRITER_OVERLOAD( std::string )
{
    qwr::pfc_x::WriteString( stream.m_stream, value, stream.m_abort );
    return stream;
}

pfc::string_base& operator<<( pfc::string_base& in, qwr::u8string_view arg );
pfc::string_base& operator<<( pfc::string_base& in, std::wstring_view arg );
