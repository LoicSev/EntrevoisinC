#pragma once
#include <string>

class CVoisin
{
private:
	wstring m_Nom;
	wstring m_Prenom;
	wstring m_Adresse;
	wstring m_Url;
	bool m_IsFavorite;

public:
	CVoisin(wstring Nom, wstring Prenom, wstring Adresse, wstring Url, bool Favorite)
	{
		m_Nom = Nom;
		m_Prenom = Prenom;
		m_Adresse = Adresse;
		m_Url = Url;
		m_IsFavorite = Favorite;
	
	}
	wstring GetNom()
	{
		return m_Nom;
	}

	void bookmarkIt()
	{
		m_IsFavorite = true;
	}
};
