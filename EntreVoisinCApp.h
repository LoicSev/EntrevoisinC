#pragma once
#include <list>
using namespace std;
#include "Voisin.h"
#include "CListVoisin.h"
#include "CProfileFenetre.h"
#include "CListFavorite.h"
#include <windows.h>



class CEntreVoisinCApp
{
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;

public:
	CEntreVoisinCApp(HINSTANCE hInst, HWND hWnd);

	list <CVoisin*> m_ListVoisin;
	CListVoisin m_ListFenetre;
	CProfileFenetre m_ProfileFenetre;
	CListFavorite m_FavoriteFenetre;

};
HINSTANCE GetInstance();

