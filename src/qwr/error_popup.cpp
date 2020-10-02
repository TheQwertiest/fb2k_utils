#include <stdafx.h>

#include "error_popup.h"

#include <qwr/delayed_executor.h>

namespace qwr
{

void ReportErrorWithPopup( const std::string& title, const std::string& errorText )
{
    assert( core_api::assert_main_thread() );

    FB2K_console_formatter() << title << ":\n" << errorText;
    qwr::DelayedExecutor::GetInstance().AddTask( [errorText, title] {
        popup_message::g_show( errorText.c_str(), title.c_str() );
    } );
    MessageBeep( MB_ICONASTERISK );
}

void ReportErrorWithPopupInMainThread( const std::string& title, const std::string& errorText )
{
    ::fb2k::inMainThread2( [title, errorText] {
        ReportErrorWithPopup( title, errorText );
    } );
}

} // namespace qwr
