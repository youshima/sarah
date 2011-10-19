#pragma once

#include "Helpers.h"
#include "STR.h"

enum VAR_TYPE { INTEGER, STRING, VARCHAR, REAL };
/*
	classe Value
	represente une valeur de type quelconque
*/
class Value
{
public:
	/*
		constructeur de Value
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Value(VAR_TYPE type);
	/*
		destructeur de Value
		{nettoie la m�moire}
	*/
	~Value();
	/*
		fonction getType
		=> { type de la variable }
	*/
	VAR_TYPE getType();

	/*
		fonction getValue
		=> { pointeur sur le buffer de la valeur }
	*/
	char* getValue();
	/*
		procedure setValue
		{attribue la valeur au buffer de variable}
	*/
	void setValue(char* value);
	/*
		operateur ==
		{ vrai si les Value ont le m�me type et meme valeur }
	*/
	bool operator==(Value value);
	/*
		operateur !=
		{ faux si les Value ont le m�me type et meme valeur }
	*/
	bool operator!=(Value value);
private:
	char* buffer;
	VAR_TYPE type;
};

/*
	classe VAR
	represente une variable d'environnement
*/
class VAR
{
public:
	/*
		constructeur de VAR
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	VAR(STR name = "");
	/*
		destructeur de VAR
		{nettoie la m�moire}
	*/
	~VAR();
	
	/*
		fonction getName
		=> { pointeur sur le nom de la variable }
	*/
	STR* getName();
	/*
		fonction getValue
		=> { pointeur sur la valeur de la variable }
	*/
	Value* getValue();
	/*
		procedure setName
		{ attribue la valeur de nom � this->nom }
	*/
	void setName( STR name );
	/*
		procedure setValue
		{ attribue la valeur de value � this->val }
	*/
	void setValue( Value val );
	/*
		operateur =
		{ affectation de value }
	*/
	void operator=( Value val );
	/*
		operateur ==
		=> { vrai si les deux variables sont �gales (meme Value) }
	*/
	bool operator==( VAR val );
	/*
		operateur !=
		=> { faux si les deux variables sont �gales (meme Value) }
	*/
	bool operator!=( VAR val );


private:
	STR name; //nom effectif de la variable
	Value* value; //valeur de la variable

};
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
};
