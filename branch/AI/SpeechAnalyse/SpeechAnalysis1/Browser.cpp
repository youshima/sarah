#include "StdAfx.h"
#include "Browser.h"

using namespace AI;
using namespace AI::BROWSER;

Browser::Browser(std::string mot)
{
	//strcpy(this->mot, mot.c_str());
	
	//Par defaut, le constructeur d�finira les regle de parsing et le site vis�

	DB = new Database();
}

Browser::~Browser()
{
}

HRESULT Browser::rechercheEtAjout()
{
	//Le parseur sera ici.

	//L'ajout du mot dans la Database se fera ici.

	return S_OK;
}
