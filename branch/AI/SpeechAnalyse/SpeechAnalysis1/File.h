#pragma once

#include <fstream>

#include "Helpers.h"
#include "VAR.h"
#include "STR.h"
#include "Form.h"

class File
{
public:
	/*
		constructeur de File
		{ initialise les variables par d�faut }
	*/
	File();
	/*
		destructeur de File
		{ ferme le fichier s'il �tait ouvert }
	*/
	~File();
	/*
		fonction open
		{}
		=> {
			S_OK si fichier bien ouvert,
			E_FILENOTFOUND si fichier non trouv� }
	*/
	HRESULT open(STR filename, bool& existed);
	/*
		fonction close
		{}
		=> {
			S_OK si le fichier a bien �t� ferm�,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT close();
	/*
		fonction getCursor
		=> { position du curseur dans le fichier, -1 si le fichier n'est pas ouvert}
	*/
	int getCursor();
	/*
		procedure toBegin
		{ place le curseur au d�but du fichier }
	*/
	void toBegin();
	/*
		procedure toEnd
		{ place le curseur � la fin du fichier }
	*/
	void toEnd();
	/*
		fonction isEmpty
		=> { vrai si le fichier est vide }
	*/
	bool isEmpty();
	/*
		fonction write
		{ecrit dans le fichier un �lement de type STR}
	*/
	HRESULT write(const STR& str);
	/*
		fonction read
		{lit dans le fichier un �lement de type STR}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(STR& str);
	/*
		fonction write
		{ecrit dans le fichier un �lement de type VAR}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT write(const VAR& var);
	/*
		fonction read
		{lit dans le fichier un �lement de type VAR}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(VAR& var);
	/*
		fonction write
		{ecrit dans le fichier un �lement de type Form}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT write(Form& form);
	/*
		fonction read
		{lit dans le fichier un �lement de type Form}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(Form& form);
	/*
		fonction write
		{ecrit dans le fichier un �lement de type int}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT write(const int& integer);
	/*
		fonction read
		{lit dans le fichier un �lement de type int}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(int& integer);
	/*
		fonction write
		{ecrit dans le fichier un �lement de type bool}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT write(const bool& boolean);
	/*
		fonction read
		{lit dans le fichier un �lement de type bool}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(bool& boolean);
		/*
		fonction write
		{ecrit dans le fichier un �lement de type TYPE}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT write(const TYPE& type);
	/*
		fonction read
		{lit dans le fichier un �lement de type TYPE}
		=> {
			S_OK si l'op�ration c'est effectu�e correctement,
			E_FAIL si le fichier n'�tait pas ouvert }
	*/
	HRESULT read(TYPE& type);
	/*
		fonction eof
		=> { vrai si nous sommes � la fin du fichier }
	*/
	bool eof();
	/*
		fonction isOpen
		=> { vrai si le fichier est ouvert }
	*/
	bool isOpen();
private:
	std::fstream file;
	STR filename;
};