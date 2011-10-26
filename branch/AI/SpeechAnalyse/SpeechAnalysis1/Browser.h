#pragma once

#include "Database.h"
#include "HTTPGET.h"
namespace AI
{

	namespace BROWSER
	{
			/*
				classe Browser
				Permet de rechercher les informations d'un mot a partir d'un dictionnaire en ligne
			*/

			class Browser
			{
			public:
				/*
					constructeur de Browser
					{initialise les variables}
				*/
				Browser(std::string mot);

				/*
					destructeur de Browser
					{nettoie la m�moire}
				*/
				~Browser();

				/*
					fonction rechercheEtAjout
					=> {
						S_OK si le mot a �t� trouv�, et ajout� � la Database 
						E_OUTOFMEMORY si probl�me de m�moire,
						E_FAIL sinon 
						}
				*/
				HRESULT rechercheEtAjout();
			private:


			private:

				Database* DB;

				DBWORD word;
				DBVERB verb;
				//...
			};
	}
}