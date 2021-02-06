#include <stdafx.h>

#include "error_popup.h"

#include <qwr/delayed_executor.h>

namespace qwr
{

void ReportErrorWithPopup( const std::string& title, const std::string& errorText )
{
    const auto report = [title, errorText] {
        assert( core_api::assert_main_thread() );

        FB2K_console_formatter() << title << ":\n"
                                 << errorText << "\n";
        qwr::DelayedExecutor::GetInstance().AddTask( [errorText, title] {
            popup_message::g_show( errorText.c_str(), title.c_str() );
        } );

        MessageBeep( MB_ICONASTERISK );
    };

    if ( core_api::is_main_thread() )
    {
        report();
    }
    else
    {
        ::fb2k::inMainThread2( report );
    }
}

} // namespace qwr
