#include <stdafx.h>

#include "ui_centered_message_box.h"

#include <qwr/final_action.h>

namespace
{

LRESULT CALLBACK GetMsgProc( int nCode, WPARAM wParam, LPARAM lParam )
{
    if ( nCode == HCBT_CREATEWND )
    {
        auto pCbt = reinterpret_cast<LPCBT_CREATEWND>( lParam );
        if ( pCbt->lpcs->lpszClass == ( LPWSTR )(ATOM)32770 ) // #32770 = dialog box class
        {
            RECT rcParent{};
            GetWindowRect( pCbt->lpcs->hwndParent, &rcParent );
            pCbt->lpcs->x = rcParent.left + ( ( rcParent.right - rcParent.left ) - pCbt->lpcs->cx ) / 2;
            pCbt->lpcs->y = rcParent.top + ( ( rcParent.bottom - rcParent.top ) - pCbt->lpcs->cy ) / 2;
        }
    }

    return CallNextHookEx( nullptr, nCode, wParam, lParam );
}

} // namespace

namespace qwr::ui
{

int MessageBoxCentered( HWND hWnd, LPCTSTR lpText, LPCTSTR lpCaption, UINT uType )
{
    auto hHook = SetWindowsHookEx( WH_CBT, GetMsgProc, nullptr, GetCurrentThreadId() );
    const auto autoHook = qwr::final_action( [hHook] {
        UnhookWindowsHookEx( hHook );
    } );

    return MessageBox( hWnd, lpText, lpCaption, uType );
}

} // namespace qwr::ui
