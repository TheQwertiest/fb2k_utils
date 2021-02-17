#pragma once

#include <string>
#include <string_view>

namespace qwr::unicode
{

std::wstring ToWide( const char* ) = delete;
std::wstring ToWide_FromAcp( const char* ) = delete;
qwr::u8string ToU8( const wchar_t* ) = delete;
qwr::u8string ToU8_FromAcpToWide( const wchar_t* ) = delete;

std::wstring ToWide( qwr::u8string_view src );
std::wstring ToWide( const pfc::string_base& src );
std::wstring ToWide_FromAcp( std::string_view src );
qwr::u8string ToU8( std::wstring_view src );
// @remark Performs double conversion (CP_ACP > Wide > CP_UTF8), use with care
qwr::u8string ToU8_FromAcpToWide( std::string_view src );

} // namespace qwr::unicode
