#pragma once

#include "Helpers.h"

using namespace std;
/*
	Element
	classe representant un mot

*/
class Element
{
public:
	Element(string str = "");
	Element(char str);
	~Element();

	DWORD getLength();
	char* getData();

	virtual bool isSeparator() = 0;
private:
	DWORD length;
	char* c;
};

class Word : public Element
{
public:
	Word(string str = "");
	~Word();

	bool isSeparator();

};

class Separator : public Element
{
public:
	Separator(char str = '.');
	~Separator();
	bool isSeparator();
};
/*
	SentenceParser
	classe se chargeant décortiquer un texte pour le transformer en une liste d'objets de type Element

*/
class SentenceParser
{
public:
	SentenceParser(); //initialise un SentenceParser
	virtual ~SentenceParser();
	vector<Element*>* Analyse(System::String^ str); //permet d'analyser une phrase et la transformer en suite de Element


private:
	UINT readElement(); //retourne le mot suivant dans 'str', "" si plus de mots à lire
	bool isAlpha(char c); //retourne vrai si le caractere est un alphabetique
	bool isNumerical(char c); //retourne vrai si le caractere est un nombre
	bool isSeparator(char c); //retourne vrai si le caractere est un separateur (non alpha et non numerique)
	DWORD cursor;
	string str;
	vector<Element*> elements;
};

