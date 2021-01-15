#pragma once
#include "CListBox.h"
#include "CFenetre.h"

class CListFavorite : public CFenetre
{
private:
	CListBox m_ListBoxFavorite;

	LRESULT virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

};