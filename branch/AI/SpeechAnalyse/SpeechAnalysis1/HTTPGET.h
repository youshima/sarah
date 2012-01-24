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
						{nettoie la m�moire}
					*/
					~HTTPGET();
					/*
						fonction http_get
						{Envoie une requete HTTP de type GET � l'url donn�e sur la page donn�e}
					=> {
							retourne la r�ponse du serveur
					   }
					*/
					char * http_get(char * url_path, char * url_server);

					/*
						fonction strrch
						{Cherche une chaine dans une autre chaine}
						=> {
								retourne la position de la chaine recherch�e ou -1 si la chaine n'est pas trouv�e
						   }
					*/
					int strrch (char * string, char * recherche);

					/*
						fonction taille_corps
						{Calcule la taille du corps d'une r�ponse HTTP}
						=> {
								retourne la taille du corps de la r�ponse HTTP
						   }
					*/
					int taille_corps(char *requete);


				private:

					char * urlPath;
					char * urlServer;

			};
	}
}