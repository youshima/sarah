#pragma once

#include "Helpers.h"
#include "VAR.h"
#include "Rule.h"
#include "File.h"


#define FILENAME "environment.data"

namespace AI
{

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
public:
	/*
		fonction Save
		{enregistre l'environnement dans un fichier}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si le fichier n'a pas pu �tre cr�� }
	*/
	HRESULT Save();
	/*
		fonction Load
		{charge l'environnement depuis un fichier}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FILENOTFOUND si le fichier n'existe pas
			 E_FAIL si le fichier n'a pas pu �tre ouvert }
	*/
	HRESULT Load();
	/*
		fonction AddVar
		{ ajoute une variable d'environnement } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment existe dej� dans la liste }
	*/
	HRESULT AddVar(VAR& var);
	/*
		fonction RemoveVar
		{ supprime une variable d'environnement en fonction de son nom } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste }
	*/
	HRESULT RemoveVar(std::string& name);
	/*
		fonction RemoveVar
		{ supprime une variable d'environnement en fonction de son index } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (index > nombre d'elements - 1)}
	*/
	HRESULT RemoveVar(UINT& index);
	/*
		fonction FindVarIndex
		=> { index de la variable dans la liste }
	*/
	int FindVarIndex(std::string& name);
	/*
		fonction getVar
		=> { pointeur sur la variable � l'index, 0 si non trouv� }
	*/
	VAR* getVar(UINT& index);
	/*
		fonction getVar
		=> { pointeur sur la variable portant le nom choisi, 0 si non trouv� }
	*/
	VAR* getVar(std::string& name);
	/*
		fonction setVar
		{modifie la valeur d'une variable d'environnement}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste}
	*/
	HRESULT setVar(std::string& name, Value& value);
	/*
		fonction setVar
		{modifie la valeur d'une variable d'environnement}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (selon l'index)}
	*/
	HRESULT setVar(UINT& index, Value& value);
	/*
		fonction AddRule
		{ ajoute une regle � l'environnement } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment existe dej� dans la liste }
	*/
	HRESULT AddRule(Rule& rule);
	/*
		fonction RemoveRule
		{ supprime une regle de l'environnement en fonction de son nom } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste }
	*/
	HRESULT RemoveRule(std::string& name);
	/*
		fonction RemoveRule
		{ supprime une regle de l'environnement en fonction de son index } 
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (index > nombre d'elements - 1)}
	*/
	HRESULT RemoveRule(UINT& index);
	/*
		fonction FindRuleIndex
		=> { index de la regle dans la liste }
	*/
	int FindRuleIndex(std::string& name);
	/*
		fonction getRule
		=> { pointeur sur la regle � l'index, 0 si non trouv� }
	*/
	Rule* getRule(UINT index);
	/*
		fonction getRule
		=> { pointeur sur la regle portant le nom choisi, 0 si non trouv� }
	*/
	Rule* getRule(std::string& name);
	/*
		fonction setRule
		{modifie les valeurs d'une regle d'environnement en la retrouvant avec son nom}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste}
	*/
	HRESULT setRule(std::string& name, std::string& script, std::string& about, bool active);
	/*
		fonction setRule
		{modifie les valeurs d'une regle d'environnement en la retrouvant avec son index}
		=> { 
			 S_OK si l'op�ration a r�ussi
			 E_FAIL si l'�l�ment n'existe pas dans la liste (selon l'index)}
	*/
	HRESULT setRule(UINT& index, std::string& script, std::string& about, bool active);
	/*
		fonction getVarCount
		=> { nombre de variables }
	*/
	UINT getVarCount();
	/*
		fonction getRulesCount
		=> { nombre de regles }
	*/
	UINT getRulesCount();


private:
	std::vector<VAR> Vars; //liste des variables d'environnement
	std::vector<Rule> Rules; //liste des regles de l'environnement
	File file; //fichier de sauvegarde
};

}