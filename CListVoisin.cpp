#include "EntreVoisinCApp.h"
#include "CListVoisin.h"
#include "Voisin.h"
#include "CListFavorite.h"

extern CEntreVoisinCApp* theApp;

LRESULT CListVoisin::virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE :
		{
			RECT r;
			GetWindowRect(hWnd, &r);
			m_ListBox.Create(GetInstance(), WS_CHILD | WS_BORDER | LBS_NOTIFY | LBS_SORT | WS_VSCROLL | LBS_HASSTRINGS, hWnd, 0, 30, r.right - r.left, r.bottom - r.top);
			ShowWindow(m_ListBox.GethWnd(), SW_SHOW);
			list<CVoisin*>::iterator it;
			for (it = theApp->m_ListVoisin.begin(); it!= theApp->m_ListVoisin.end(); it++)
			{
				auto pVoisin = *it;
				m_ListBox.AddString(pVoisin->GetNom());

                m_MainListButton.Create(GetInstance(), WS_CHILD | WS_VISIBLE, hWnd, 0, 0, 200, 30);
                m_MainListButton.SetText(L"Liste");

                m_MainFavoriteButton.Create(GetInstance(), WS_CHILD | WS_VISIBLE, hWnd, 200, 0, 200, 30);
                m_MainFavoriteButton.SetText(L"Favoris");
			}
			break;

		}
		case WM_COMMAND:
        {
            {
                WORD wmId, wmEvent;
                if (!lParam)
                {
                    wmId = LOWORD(wParam);
                    wmEvent = HIWORD(wParam);
                }
                else
                {
                    wmId = HIWORD(wParam);
                    wmEvent = LOWORD(wParam);
                }

                switch (wmId)
                {
                    case LBN_SELCHANGE:
                    {
                    auto iCur = m_ListBox.GetCurSel();
                    auto sz = m_ListBox.GetText(iCur);
                        for (auto it = theApp->m_ListVoisin.begin(); it != theApp->m_ListVoisin.end(); it++)
                        {
                            auto pVoisin = *it;
                            if (pVoisin->GetNom() == sz)
                            {
                            ShowWindow(GethWnd(), SW_HIDE);
                            theApp->m_ProfileFenetre.FillField(pVoisin);
                            ShowWindow(theApp->m_ProfileFenetre.GethWnd(), SW_SHOW);
                            }
                        }
                    break;
                    }
                }
            }
        }
        break;

        case BN_CLICKED:
        {
            if ((HWND)lParam == m_MainListButton.GethWnd())
            {
                MessageBox(hWnd, L"Welcome", L"", MB_OK);
            }
            else if ((HWND)lParam == m_MainFavoriteButton.GethWnd())
            {
                ShowWindow(theApp->m_ListFenetre.GethWnd(), SW_HIDE);
                ShowWindow(theApp->m_FavoriteFenetre.GethWnd(), SW_SHOW);
                MessageBox(hWnd, L"Ca marche", L"Favoris", MB_OK);
            }
            
        }
        break;

        default:
        break;
        
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
