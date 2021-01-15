#include "EntreVoisinCApp.h"
extern HINSTANCE hInst;

CEntreVoisinCApp::CEntreVoisinCApp(HINSTANCE hInst, HWND hWnd)
{

	m_hInstance = hInst;
	m_hWnd = hWnd;
	CVoisin * pVoisin = new CVoisin(L"Dudul",L"Jean",L"Rue dushmol",L"www:\\gibi64.com", false);
	m_ListVoisin.push_back(pVoisin);
	pVoisin = new CVoisin(L"Totor", L"Jean", L"Rue machin", L"www:\\gibi64.com", false);
	m_ListVoisin.push_back(pVoisin);
	pVoisin = new CVoisin(L"lolo", L"Jean", L"Rue machin", L"www:\\gibi64.com",false);
	m_ListVoisin.push_back(pVoisin);


}
HINSTANCE GetInstance()
{
	return hInst;
}

