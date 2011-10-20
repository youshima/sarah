#pragma once

#include "Helpers.h"
#include "VAR.h"
#include "STR.h"
#include "Form.h"

class File
{
public:
	/*
		constructeur de File
		{ ouvre le fichier }
	*/
	File(STR filename, bool* exists);
	/*
		destructeur de File
		{ ferme le fichier }
	*/
	~File();
	/*
		procedure write
		{ecrit dans le fichier un élement de type STR}
	*/
	void write(STR* str);
	/*
		procedure read
		{lit dans le fichier un élement de type STR}
	*/
	void read(STR* str);
	/*
		procedure write
		{ecrit dans le fichier un élement de type VAR}
	*/
	void write(VAR* var);
	/*
		procedure read
		{lit dans le fichier un élement de type VAR}
	*/
	void read(VAR* var);
	/*
		procedure write
		{ecrit dans le fichier un élement de type Form}
	*/
	void write(Form* form);
	/*
		procedure read
		{lit dans le fichier un élement de type Form}
	*/
	void read(Form* form);
	/*
		procedure write
		{ecrit dans le fichier un élement de type int}
	*/
	void write(int* integer);
	/*
		procedure read
		{lit dans le fichier un élement de type int}
	*/
	void read(int* integer);
private:
	std::fstream file;
	STR filename;
};