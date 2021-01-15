#include "EntreVoisinCApp.h"
#include "CListFavorite.h"
#include "Voisin.h"
extern CEntreVoisinCApp* theApp;

LRESULT CListFavorite::virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
        RECT r;
        GetWindowRect(hWnd, &r);
        m_ListBoxFavorite.Create(GetInstance(), WS_CHILD | WS_BORDER | LBS_NOTIFY | LBS_SORT | WS_VSCROLL | LBS_HASSTRINGS, hWnd, 0, 0, r.right - r.left, r.bottom - r.top);
        ShowWindow(m_ListBoxFavorite.GethWnd(), SW_SHOW);
        }
        break;

        case WM_COMMAND:
        {

        }
        break;

        default:
        break;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);

}
