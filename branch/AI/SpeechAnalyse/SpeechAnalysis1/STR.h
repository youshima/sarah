#pragma once


#include "Helpers.h"

/*
	classe STR :
	contient une chaine de caracteres et sa longueur
*/

class STR
{
public:
	/*
		constructeur de STR
		{initialise les variables}
	*/
	STR(const char* c = "");
	/*
		destructeur de STR
		{nettoie la mémoire}
	*/
	~STR();
	
	/*
		operateur d'affectation
		{affecte la chaine de caracteres à l'élement}
	*/
	void operator=(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {vrai si les deux chaines ont la même taille et les mêmes caracteres}
	*/
	bool operator==(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {faux si les deux chaines ont la même taille et les mêmes caracteres}
	*/
	bool operator!=(const char* c);
	/*
		operateur d'affectation
		{affecte la valeur d'un STR à l'élement}
	*/
	void operator=(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {vrai si les deux STR ont la même taille et les mêmes caracteres}
	*/
	bool operator==(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {faux si les deux STR ont la même taille et les mêmes caracteres}
	*/
	bool operator!=(STR str);
	/*
		operateur d'acces
		{i represente l'index de l'élément auquel on souhaite acceder}
		=> {caractere à la position index ou bien 0 s'il n'existe pas}
	*/
	char* operator[](UINT index);
	/*
		fonction getString
		=> {le pointeur c}
	*/
	char* getString() const;
	/*
		fonction getLength
		=> {le pointeur de length}
	*/
	UINT* getLength();
	/*
		procedure setString
		{affecte la chaine de caracteres à celle de l'élement}
	*/
	void setString(char* c);
	/*
		procedure popHead
		{enlève le premier caractere}
	*/
	void popBack();
	/*
		procedure empty
		{vide le contenu de la chaine}
	*/
	void empty();
private:
	/*
		procedure setLength
		{affecte la longueur à celle de l'élement}
	*/
	void setLength(UINT length);
private:
	char* c;
	UINT length;
	
};
