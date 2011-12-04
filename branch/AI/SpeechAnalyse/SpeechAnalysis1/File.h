#pragma once

#include <fstream>

#include "Helpers.h"
#include "VAR.h"
#include "STR.h"
#include "Form.h"
#include "Rule.h"

using namespace AI;

class File
{
public:
	/*
		constructeur de File
		{ initialise les variables par défaut }
	*/
	File();
	/*
		destructeur de File
		{ ferme le fichier s'il était ouvert }
	*/
	~File();
	/*
		fonction open
		{}
		=> {
			S_OK si fichier bien ouvert,
			E_FILENOTFOUND si fichier non trouvé }
	*/
	HRESULT open(std::string filename, bool& existed);
	/*
		fonction close
		{}
		=> {
			S_OK si le fichier a bien été fermé,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT close();
	/*
		fonction empty
		{}
		=> {
			S_OK si le fichier a bien été vidé,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT empty();
	/*
		fonction getReadCursor
		=> { position du curseur dans le fichier, -1 si le fichier n'est pas ouvert}
	*/
	int getReadCursor();
	/*
		fonction getWriteCursor
		=> { position du curseur dans le fichier, -1 si le fichier n'est pas ouvert}
	*/
	int getWriteCursor();
	/*
		procedure to
		{ place le curseur à l'offset indiqué dans le fichier }
	*/
	void to(UINT offset);
	/*
		procedure toBegin
		{ place le curseur au début du fichier }
	*/
	void toBegin();
	/*
		procedure toEnd
		{ place le curseur à la fin du fichier }
	*/
	void toEnd();
	/*
		fonction isEmpty
		=> { vrai si le fichier est vide }
	*/
	bool isEmpty();
	/*
		fonction write
		{ecrit dans le fichier un élement de type STR}
	*/
	HRESULT write(std::string& str);
	/*
		fonction read
		{lit dans le fichier un élement de type STR}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(std::string& str);
	/*
		fonction write
		{ecrit dans le fichier un élement de type VAR}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(VAR& var);
	/*
		fonction read
		{lit dans le fichier un élement de type VAR}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(VAR& var);
	/*
		fonction write
		{ecrit dans le fichier un élement de type Form}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(AI::Form& form);
	/*
		fonction read
		{lit dans le fichier un élement de type Form}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(AI::Form& form);
	/*
		fonction write
		{ecrit dans le fichier un élement de type int}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(const int& integer);
	/*
		fonction read
		{lit dans le fichier un élement de type int}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(int& integer);
	/*
		fonction write
		{ecrit dans le fichier un élement de type float}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(const float& real);
	/*
		fonction read
		{lit dans le fichier un élement de type float}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(float& real);
	/*
		fonction write
		{ecrit dans le fichier un élement de type bool}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(const bool& boolean);
	/*
		fonction read
		{lit dans le fichier un élement de type bool}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(bool& boolean);
	/*
		fonction write
		{ecrit dans le fichier un élement de type char}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(const char& caracter);
	/*
		fonction read
		{lit dans le fichier un élement de type char}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(char& caracter);
	/*
		fonction write
		{ecrit dans le fichier un élement de type TYPE}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(const TYPE& type);
	/*
		fonction read
		{lit dans le fichier un élement de type TYPE}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(TYPE& type);
	/*
		fonction write
		{ecrit dans le fichier un élement de type Rule}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT write(AI::Rule& rule);
	/*
		fonction read
		{lit dans le fichier un élement de type Rule}
		=> {
			S_OK si l'opération c'est effectuée correctement,
			E_FAIL si le fichier n'était pas ouvert }
	*/
	HRESULT read(AI::Rule& rule);
	/*
		fonction eof
		=> { vrai si nous sommes à la fin du fichier }
	*/
	bool eof();
	/*
		fonction isOpen
		=> { vrai si le fichier est ouvert }
	*/
	bool isOpen();
private:
	std::fstream file;
	std::string filename;
};