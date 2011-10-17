#include "StdAfx.h"
#include "Database.h"
/*

		CLASS STR




*/
STR::STR(const char *c = "") {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	SetString(new CHAR[GetLength()]);
	strcpy_s(GetString(), GetLength(), c); //copie de la chaine
}
STR::~STR() {
	delete[] c;	//suppression du tableau de pointeurs
	l = 0;
}


void STR::operator =(const char *c) {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	delete[] c;
	SetString(new CHAR[GetLength()]);
	strcpy_s(GetString(), GetLength(), c); //copie de la chaine
}
bool STR::operator ==(const char *c) {
	return strcmp(GetString(),c);	//comparaison des deux chaines
}
bool STR::operator !=(const char *c) {
	return !(this == c);	//comparaison des deux chaines
}
void STR::operator =(STR str) {
	SetLength(str.length); //recuperation de la taille de la chaine
	delete[];
	SetString(new CHAR[GetLength()]);
	strcpy_s(GetString(), GetLength(), str.c); //copie de la chaine
}
bool STR::operator ==(STR str) {
	return strcmp(GetString(),str.GetString());	//comparaison des deux chaines
}
bool STR::operator !=(STR str) {
	return !(this == str);	//comparaison des deux chaines
}
char* STR::GetString() const {
	return this->c;
}
UINT STR::GetLength() const {
	return this->length;
}
void STR::SetString(char *c) {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	delete[] c;
	GetString() = new CHAR[GetLength()]);
	strcpy_s(GetString(), GetLength(), c); //copie de la chaine
}
void STR::SetLength(UINT length) {
	this->length = length;//recuperation de la taille de la chaine
}

/*
		CLASS MAPWORD

*/
MapWord::MapWord(str = "", offset = 0) {
	SetString(str);
	SetOffset(offset);
}
	
MapWord::~MapWord() {
	DESTROY(this->str);
	for(UINT i = 0; i < GetChildrenCount(); i++)
		DESTROY(this->child[i]);
	this->child.clear();
}
bool MapWord::operator ==(MapWord* word) {
	return ( GetString() == word->GetString() && GetOffset() word->GetOffset());
}
bool MapWord::operator !=(MapWord* word) {
	return !( this == word );
}
STR* MapWord::GetString() {
	return this->str;
}
	
UINT MapWord::GetOffset() {
	return this->offset;
}
	
UINT MapWord::GetChildrenCount() {
	return this->child.size();
}
	
MapWord* MapWord::GetChildren(UINT i) {
	if( i < GetChildrenCount() )
		return this->child[i];
	else
		return 0;
}
	
void MapWord::SetString(STR str) {
	this->str = str;
}
	
void MapWord::SetOffset(UINT offset) {
	this->offset = offset;
}
	
HRESULT MapWord::AddChildren(MapWord* mw) {
	if(this == mw)
		return E_FAIL; //on essaye d'ajouter le même élément

	for(UINT i = 0; i < GetChildrenCount(); i++)
	{
		
	}
	this->form.push_back(form);

	return S_OK; //forme ajoutée avec succès
}
	
HRESULT MapWord::RemoveChildren(MapWord* mw) {

}

/*

		CLASS DBWORD



*/
DBWORD::DBWORD(STR name = "") {
	SetName(name);
	SetDef("");
	SetType(NONE);
}

DBWORD::~DBWORD() {
	DESTROY(this->name);
	DESTROY(this->def);
}
	

STR* DBWORD::GetName() const {
	return &this->name;
}
	
STR* DBWORD::GetDef() const {
	return &this->def;
}
	
TYPE DBWORD::GetType() const {
	return &this->type;
}

void DBWORD::SetName(STR name) {
	this->name = name;
}
	
void DBWORD::SetDef(STR def) {
	this->def = def;
}
	
void DBWORD::SetType(TYPE type) {
	this->type = type;
}

/*

		CLASS DBVERB


*/
DBVERB::DBVERB(STR name = "", bool irregular = false) {
	DBWORD::DBWORD(name);
	SetIrregular(irregular);
}

DBVERB::~DBVERB() {
	DBWORD::~DBWORD();
	form.clear();
}

bool DBVERB::isIrregular() {
	return this->irregular;
}

LIST(FORM)* DBVERB::GetFormList() const {
	return &this->form;
}

void DBVERB::SetIrregular(bool irregular) {
	this->irregular = irregular;
}

HRESULT DBVERB::AddForm(FORM form) {
	for(UINT i = 0; i < this->form.size(); i++)
	{
		if(this->form[i] == form)
			return E_FAIL; //la forme existe dejà dans la liste
	}
	this->form.push_back(form);

	return S_OK; //forme ajoutée avec succès
}

HRESULT DBVERB::RemoveForm(FORM form) {
	UINT i = 0;
	while(i < this->form.size() && this->form[i] != form); //boucler tant qu'on ne trouve pas la forme

	if( i == this->form.size() ) //as t-on trouvé la forme?
		return E_FAIL; //non
	else
		this->form.erase(i);

	return S_OK; //forme supprimée avec succès
}

/*
	CLASS DATABASE

*/
Database::Database() {
	map = new MapWord();
	map->offset = 0;
	map->str = "root";
}

Database::~Database() {

}

HRESULT Database::Load() {

}
	
HRESULT Database::Save() {

}
	
HRESULT Database::Remap() {

}