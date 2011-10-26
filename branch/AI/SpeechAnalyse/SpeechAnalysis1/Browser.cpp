#include "StdAfx.h"
#include "Browser.h"

using namespace AI;
using namespace AI::BROWSER;

Browser::Browser(std::string mot)
{
	//strcpy(this->mot, mot.c_str());
	
	//Par defaut, le constructeur définira les regle de parsing et le site visé

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
