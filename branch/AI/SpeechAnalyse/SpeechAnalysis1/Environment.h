#pragma once

#include "Helpers.h"
#include "STR.h"
#include "VAR.h"

#define FILENAME "environment.data"

/*
	classe Environment
	represente l'ensemble de l'environnement IA
*/
class Environment
{
public:
	/*
		constructeur de Environment
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Environment();
	/*
		destructeur de Environment
		{nettoie la m�moire}
	*/
	~Environment();
private:
	/*
		fonction Save
		{enregistre l'environnement dans un fichier}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si le fichier n'a pas pu �tre cr�� }
	*/
	HRESULT Save();
	/*
		fonction AddVar
		{ ajoute une variable d'environnement } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment existe dej� dans la liste }
	*/
	HRESULT AddVar(VAR var);
	/*
		fonction RemoveVar
		{ supprime une variable d'environnement en fonction de son nom } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste }
	*/
	HRESULT RemoveVar(STR name);
	/*
		fonction RemoveVar
		{ supprime une variable d'environnement en fonction de son index } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (index > nombre d'elements - 1)}
	*/
	HRESULT RemoveVar(UINT index);
	/*
		fonction FindVarIndex
		=> { index de la variable dans la liste }
	*/
	UINT FindVarIndex(STR name);
	/*
		fonction getVar
		=> { pointeur sur la variable � l'index, 0 si nono trouv� }
	*/
	VAR* getVar(UINT index);
	/*
		fonction getVar
		=> { pointeur sur la variable portant le nom choisi, 0 si non trouv� }
	*/
	VAR* getVar(STR name);
	/*
		fonction setVar
		{modifie la valeur d'une variable d'environnement}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste}
	*/
	HRESULT setVar(STR name, Value value);
	/*
		fonction setVar
		{modifie la valeur d'une variable d'environnement}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (selon l'index)}
	*/
	HRESULT setVar(UINT index, Value value);


private:
	std::vector<VAR> Vars; //liste des variables d'environnement
	File* file; //fichier de sauvegarde
};
