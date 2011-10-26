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
					{nettoie la mémoire}
				*/
				~Browser();

				/*
					fonction rechercheEtAjout
					=> {
						S_OK si le mot a été trouvé, et ajouté à la Database 
						E_OUTOFMEMORY si problème de mémoire,
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