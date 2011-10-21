#include "StdAfx.h"
#include "STR.h"

/*

		CLASS STR


*/
STR::STR(const char *c) {
	char* myc = new char[strlen(c)]; //copie du const char
	if(strlen(c) > 0)
	strcpy_s(myc, sizeof(char) * strlen(c) , c);
	else
		myc = new char;
	setString(myc);
}
STR::~STR() {
	empty();
}


void STR::operator =(const char *c) {

	setString(c);
	
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
		strcpy_s(this->c, sizeof(char) * *getLength(), str.getString()); //copie de la chaine
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
UINT* STR::getLength() {
	return &this->length;
}
void STR::setString(const char *c) {
	setLength(strlen(c)); //recuperation de la taille de la chaine
	if(*getLength() > 0)
	{
		if(this->c)
			delete[] this->c;
		this->c = new char[*getLength()];
		strcpy_s(this->c, sizeof(char) * *getLength(), c); //copie de la chaine
	}
	else
		this->c = 0;
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