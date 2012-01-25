#pragma once

#include "Helpers.h"
#include "STR.h"

enum VAR_TYPE { INTEGER, STRING, VARCHAR, REAL,VARBOOL, VARRESULT, SENTENCE, VAR_TYPE_NONE };
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
	Value(VAR_TYPE type = VAR_TYPE_NONE);
	/*
		constructeur de Value
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	/*Value(int val);
	Value(float val);
	Value(bool val);
	Value(HRESULT val);
	Value(std::string val);
	Value(char val);*/
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
	/** change le type de la variable
	*/
	void setType(VAR_TYPE type);
	/*
		operateur ==
		{ vrai si les Value ont le m�me type et meme valeur }
	*/
	bool operator==(Value value);
	/*
		operateur !=
	*/
	bool operator!=(Value value);

	void operator=(bool val);
	void operator=(std::string val);
	void operator=(char val);
	void operator=(HRESULT val);
	void operator=(int val);
	void operator=(float val);
	void operator=(Value val);

	bool operator==(bool val);
	bool operator==(std::string val);
	bool operator==(char val);
	bool operator==(HRESULT val);
	bool operator==(int val);
	bool operator==(float val);

	bool operator!=(bool val);
	bool operator!=(std::string val);
	bool operator!=(char val);
	bool operator!=(HRESULT val);
	bool operator!=(int val);
	bool operator!=(float val);

private:
	char buffer[256];
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
	VAR(std::string name = "");
	/*
		destructeur de VAR
		{nettoie la m�moire}
	*/
	~VAR();
	
	/*
		fonction getName
		=> { pointeur sur le nom de la variable }
	*/
	std::string getName();
	/*
		fonction getValue
		=> { pointeur sur la valeur de la variable }
	*/
	Value getValue();
	/*
		procedure setName
		{ attribue la valeur de nom � this->nom }
	*/
	void setName( std::string name );
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
	std::string name; //nom effectif de la variable
	Value value; //valeur de la variable

};