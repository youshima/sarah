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
				Browser();

				/*
					destructeur de Browser
					{nettoie la m�moire}
				*/
				~Browser();

				/*
					fonction find
					=> {
							retourne la structure DBWORD avec les infos du mot word
					   }
				*/
				DBWORD findW(STR word);

				/*
					fonction find
					=> {
							retourne la structure DBVERB avec les infos du mot verb
					   }
				*/
				DBVERB findV(STR verb);

				/*
					fonction getType
					=> {
							retourne le type TYPE du mot word
					   }
				*/
				TYPE getType(STR word);
			private:
				/*
					fonction http_get
					{Envoie une requete HTTP de type GET � l'url donn�e sur la page donn�e}
					=> {
							retourne la r�ponse du serveur
					   }
				*/
				STR httpGet(STR url_path, STR url_server);

				/*
					fonction strrch
					{Cherche une chaine dans une autre chaine}
					=> {
							retourne la position de la chaine recherch�e ou -1 si la chaine n'est pas trouv�e
					   }
				*/
				int strrch (STR string, STR recherche);

				/*
					fonction taille_corps
					{Calcule la taille du corps d'une r�ponse HTTP}
					=> {
							retourne la taille du corps de la r�ponse HTTP
					   }
				*/
				int taille_corps(STR requete);

				STR mot;

				Database db;

				DBWORD word;
				DBVERB verb;

				STR urlPath;
				STR urlServer;
			};
	}
}