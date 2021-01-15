#pragma once
#include <CFenetre.h>
#include "CStaticText.h"
#include "CEditBox.h"
#include "CButton.h"
#include "Voisin.h"


class CProfileFenetre :
    public CFenetre
{
private:
    LRESULT virtualFenetreProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    CStaticText m_StaticNom;
    CEditBox m_EditNom;
    Cbutton m_BackButton;
    Cbutton m_FavButton;

public:
    void FillField(CVoisin* pVoisin);

};

