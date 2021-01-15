#pragma once
#include "CListBox.h"
#include "Cbutton.h"

class CListVoisin : public CFenetre
{
private:
	CListBox m_ListBox;
	Cbutton m_MainListButton;
	Cbutton m_MainFavoriteButton;

	LRESULT virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

};