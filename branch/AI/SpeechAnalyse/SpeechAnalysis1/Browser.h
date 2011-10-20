#pragma once

#include "Database.h"

/*
	classe RechercheInfo
	Permet de rechercher les informations d'un mot a partir d'un dictionnaire en ligne
*/

class RechercheInfo
{
public:
	/*
		constructeur de RechercheInfo
		{initialise les variables}
	*/
	RechercheInfo(STR mot);

	/*
		destructeur de RechercheInfo
		{nettoie la mémoire}
	*/
	~RechercheInfo();

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

	char * mot;

	DBWORD word;
	DBVERB verb;

	char * urlPath;
	char * urlServer;
	char * debutParseType;
	char * finParseType;
	char * debutParseDef;
	char * finParseDef;
	//...
};
