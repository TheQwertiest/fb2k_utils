#pragma once

namespace qwr::error
{

_Post_satisfies_( SUCCEEDED( hr ) ) void CheckHR( HRESULT hr, qwr::u8string_view functionName );

_Post_satisfies_( checkValue ) void CheckWinApi( bool checkValue, qwr::u8string_view functionName );

/// @details This overload is needed for SAL: it can't understand that `(bool)ptr == true` is the same as  `ptr != null`
void CheckWinApi( _Post_notnull_ void* checkValue, qwr::u8string_view functionName );

_Post_satisfies_( SUCCEEDED( hr ) ) void CheckWin32( int hr, qwr::u8string_view functionName );

} // namespace qwr::error
