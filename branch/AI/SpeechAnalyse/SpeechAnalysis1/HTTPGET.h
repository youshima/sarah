#pragma once


#include "Helpers.h"



namespace AI
{
	namespace BROWSER
	{
			/*
				classe HTTPGET
				Permet de recuperer du contenu HTML sur le web
			*/
			class HTTPGET
			{
				public:
				
					/*
						constructeur de HTTPGET
						{initialise les variables}
					*/
					HTTPGET();
					/*
						destructeur de HTTPGET
						{nettoie la mémoire}
					*/
					~HTTPGET();
					/*
						fonction http_get
						{Envoie une requete HTTP de type GET à l'url donnée sur la page donnée}
					=> {
							retourne la réponse du serveur
					   }
					*/
					char * http_get(char * url_path, char * url_server);

					/*
						fonction strrch
						{Cherche une chaine dans une autre chaine}
						=> {
								retourne la position de la chaine recherchée ou -1 si la chaine n'est pas trouvée
						   }
					*/
					int strrch (char * string, char * recherche);

					/*
						fonction taille_corps
						{Calcule la taille du corps d'une réponse HTTP}
						=> {
								retourne la taille du corps de la réponse HTTP
						   }
					*/
					int taille_corps(char *requete);


				private:

					char * urlPath;
					char * urlServer;

			};
	}
}