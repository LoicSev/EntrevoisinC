#include "CProfileFenetre.h"
#include "EntreVoisinCApp.h"
extern CEntreVoisinCApp* theApp;
LRESULT CProfileFenetre::virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		m_StaticNom.Create(GetInstance(), WS_CHILD, hWnd, 20, 20, 100, 30);
		m_StaticNom.SetText(L"Nom");
		ShowWindow(m_StaticNom.GethWnd(), SW_SHOW);

		m_EditNom.Create(GetInstance(), WS_CHILD|WS_BORDER|WS_VISIBLE, hWnd, 140, 20, 100, 30);


		m_BackButton.Create(GetInstance(), WS_CHILD | WS_VISIBLE, hWnd, 300, 600, 40, 40);
		m_BackButton.SetText(L"<");

		m_FavButton.Create(GetInstance(), WS_CHILD | WS_VISIBLE, hWnd, 250, 650, 100, 40);
		m_FavButton.SetText(L"Favoris");

		break;

	case WM_COMMAND:
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
			case BN_CLICKED:
			{
				if ((HWND)lParam == m_BackButton.GethWnd())
				{
					ShowWindow(theApp->m_ProfileFenetre.GethWnd(), SW_HIDE);
					ShowWindow(theApp->m_ListFenetre.GethWnd(), SW_SHOW);
					break;
				}
				else if ((HWND)lParam == m_FavButton.GethWnd())
				{
					auto sz = m_EditNom.GetText();
					for (auto it = theApp->m_ListVoisin.begin(); it != theApp->m_ListVoisin.end(); it++)
					{
						auto pVoisin = *it;
						if (pVoisin->GetNom() == sz)
						{
							pVoisin->bookmarkIt();
							MessageBox(hWnd, L"Vous l'avez mis en favoris", L"Favoris", MB_OK);
						}
					}
				}
			}
		}
	}
	default:
		break;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void CProfileFenetre::FillField(CVoisin* pVoisin)
{
	m_EditNom.SetText(pVoisin->GetNom());
}
