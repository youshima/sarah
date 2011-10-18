#pragma once

#include "Helpers.h"
#include "STR.h"

using namespace std;
/*
	classe Element
	represente un mot ou un separateur

*/
class Element
{
public:
	/*
		Constructeur de Element
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Element(string str = "");
	/*
		Constructeur de Element
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Element(char str);
	/*
		Constructeur de Element
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Element(STR str);
	/*
		Destructeur de Element
		{nettoie la m�moire}
	*/
	~Element();
	/*
		fonction getLength
		=> { la taille de l'�l�ment }
	*/
	const UINT* getLength();
	/*
		fonction getData
		=> { pointeur sur le string de l'�l�ment }
	*/
	STR* getString();
	/*
		procedure setSata
		{ affecte this->str � str }
	*/
	void setString(STR str);
	/*
		fonction isSeparator (virtuelle)
		=> { vrai si l'�l�ment est un s�parateur }
	*/
	virtual bool isSeparator() = 0;
private:
	STR str;
};
/*
	classe Word
	represente un mot

*/
class Word : public Element
{
public:
	/*
		Constructeur de Word
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Word(string str = "");
	/*
		Destructeur de Word
		{nettoie la m�moire}
	*/
	~Word();
	/*
		fonction isSeparator
		=> { faux }
	*/
	bool isSeparator();

};

class Separator : public Element
{
public:
	/*
		Constructeur de Separator
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Separator(char str = '.');
		/*
		Destructeur de Separator
		{nettoie la m�moire}
	*/
	~Separator();
	/*
		fonction isSeparator
		=> { vrai }
	*/
	bool isSeparator();
};
/*
	classe SentenceParser
	Se charge d�cortiquer un texte pour le transformer en une liste d'objets de type Element

*/
class SentenceParser
{
public:
	/*
		constructeur de SentenceParser
	*/
	SentenceParser();
	/*
		destructeur de SentenceParser
	*/
	virtual ~SentenceParser();
	/*
		fonction Analyse
		{ une chaine de caracteres } => { liste d'Elements }
	*/
	vector<Element*>* Analyse(System::String^ str); //permet d'analyser une phrase et la transformer en suite de Element


private:
	/*
		fonction readElement
		=> { le mot suivant dans 'str', "" si plus de mots � lire }
	*/
	UINT readElement();
	/*
		fonction isAlpha
		=> { vrai si le caractere est alphabetique }
	*/
	bool isAlpha(char c); //retourne vrai si le caractere est un alphabetique
	/*
		fonction isNumeric
		=> { vrai si le caractere est numerique }
	*/
	bool isNumeric(char c); //retourne vrai si le caractere est un nombre
	/*
		fonction isSeparator
		=> { vrai si le caractere est un s�paratuer (non alpha et non numerique) }
	*/
	bool isSeparator(char c);

	DWORD cursor;
	STR str;
	vector<Element*> elements;
};

