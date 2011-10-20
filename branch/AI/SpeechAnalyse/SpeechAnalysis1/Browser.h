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
		{nettoie la m�moire}
	*/
	~RechercheInfo();

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
