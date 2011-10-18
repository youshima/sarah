#include "StdAfx.h"
#include "STR.h"

/*

		CLASS STR


*/
STR::STR(const char *c) {
	setLength(strlen(c)); //recuperation de la taille de la chaine
	if(*getLength() > 0)
	{
		setString(new char[*getLength()]);
		strcpy_s(this->c, *getLength(), c); //copie de la chaine
	}
	else
		this->c = 0;
}
STR::~STR() {
	empty();
}


void STR::operator =(const char *c) {
	setLength(strlen(c)); //recuperation de la taille de la chaine

	if(this->c)
	delete[] this->c;

	if(*getLength() > 0)
	{
		this->c = new char[*getLength()] ;
		strcpy(this->c, c); //copie de la chaine
	}
	else
		this->c = 0;
}
bool STR::operator ==(const char *c) {
	return strcmp(getString(),c) == 0;	//comparaison des deux chaines
}
bool STR::operator !=(const char *c) {
	return !(*this == c);	//comparaison des deux chaines
}
void STR::operator =(STR str) {
	setLength(*str.getLength()); //recuperation de la taille de la chaine
	if(this->c)
	delete[] this->c;
	if(*getLength() > 0)
	{
		this->c = new char[*getLength()];
		strcpy(this->c, c); //copie de la chaine
	}
}
bool STR::operator ==(STR str) {
	return strcmp(getString(),str.getString()) == 0;	//comparaison des deux chaines
}
bool STR::operator !=(STR str) {
	return !(*this == str);	//comparaison des deux chaines
}
char* STR::operator []( UINT index)
{
	return &c[index];
}
char* STR::getString() const {
	return this->c;
}
const UINT* STR::getLength() {
	return &this->length;
}
void STR::setString(char *c) {
	setLength(strlen(c)); //recuperation de la taille de la chaine
	delete[] c;
	if(*getLength() > 0)
	{
		this->c = new char[*getLength()];
		strcpy(this->c, c); //copie de la chaine
	}
}
void STR::setLength(UINT length) {
	this->length = length;//recuperation de la taille de la chaine
}
void STR::popBack() {
	this->c++;
	this->length--;
}
void STR::empty() {
	delete [] this->c;
	this->length = 0;
}