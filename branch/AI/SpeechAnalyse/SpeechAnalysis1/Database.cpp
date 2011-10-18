#include "StdAfx.h"
#include "Database.h"
/*

		CLASS STR




*/
STR::STR(const char *c) {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	SetString(new char[*getLength()]);
	strcpy_s(getString(), *getLength(), c); //copie de la chaine
}
STR::~STR() {
	delete[] c;	//suppression du tableau de pointeurs
	SetLength(0);
}


void STR::operator =(const char *c) {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	delete[] c;
	SetString(new char[*getLength()]);
	strcpy_s(getString(), *getLength(), c); //copie de la chaine
}
bool STR::operator ==(const char *c) {
	return strcmp(getString(),c) == 0;	//comparaison des deux chaines
}
bool STR::operator !=(const char *c) {
	return !(*this == c);	//comparaison des deux chaines
}
void STR::operator =(STR str) {
	SetLength(str.length); //recuperation de la taille de la chaine
	delete[] c;
	SetString(new char[*getLength()]);
	strcpy_s(getString(), *getLength(), str.c); //copie de la chaine
}
bool STR::operator ==(STR str) {
	return strcmp(getString(),str.getString()) == 0;	//comparaison des deux chaines
}
bool STR::operator !=(STR str) {
	return !(*this == str);	//comparaison des deux chaines
}
char* STR::getString() const {
	return this->c;
}
UINT* STR::getLength() {
	return &this->length;
}
void STR::SetString(char *c) {
	SetLength(strlen(c)); //recuperation de la taille de la chaine
	delete[] c;
	this->c = new char[*getLength()];
	strcpy_s(c, *getLength(), c); //copie de la chaine
}
void STR::SetLength(UINT length) {
	this->length = length;//recuperation de la taille de la chaine
}
void STR::PopBack() {
	this->c++;
	this->length--;
}

/*
		CLASS MAPWORD

*/
MapWord::MapWord(UINT offset) {
	SetOffset(offset);
	for(UINT i = 0; i < 26; i++)
		this->child[i] = 0; //tous les child � nul
	SetSynonym(0);
}
	
MapWord::~MapWord() {
	for(UINT i = 0; i < 26; i++)
	{
		if(this->child[i])
		{
			this->child[i]->~MapWord();
			this->child[i] = 0;
		}
	}
}
bool MapWord::operator ==(MapWord* word) {
	return ( getOffset() == word->getOffset());
}
bool MapWord::operator !=(MapWord* word) {
	return !( *this == word );
}
	
UINT MapWord::getOffset() {
	return this->offset;
}

MapWord* MapWord::getSynonym()
{
	return this->synonym;
}
	
void MapWord::SetOffset(UINT offset) {
	this->offset = offset;
}
	
void MapWord::SetSynonym(MapWord* synonym)
{
	this->synonym = synonym;
}

HRESULT MapWord::Add(MapWord* mw, STR name) {
	if(this == mw)
		return E_FAIL; //on essaye d'ajouter le m�me �l�ment

	if(name != "")
	{
		
		if(this->getChild(name.getString()[0]) == 0) //si le fils n'existe pas encore
			this->child[ name.getString()[0] ] = new MapWord(); //en creer un
		name.PopBack();//enlever le premier caractere 
		return this->getChild(name.getString()[0])->Add(mw, name); //calculer � quelle branche continuer r�cursivement
	}
	else //on a trouv� l'emplacement
	{
		SetOffset(mw->getOffset());
		return S_OK; //ajout� avec succ�s
	}
}


UINT MapWord::Find(STR name)
{
	if(name != "")
	{
		
		if(this->getChild(name.getString()[0]) == 0) //si le fils existe
		{
			name.PopBack();//enlever le premier caractere
			return this->getChild(name.getString()[0])->Find(name); //calculer � quelle branche continuer r�cursivement
		}
		else
			return 0; //n'existe pas
	}
	else
	{
		return getOffset(); //on a trouv� l'�l�ment
	}
}

MapWord* MapWord::getChild(char c) {
	if( c >= 'a' && c <= 'z')
		return this->child[c - 'a'];
	else
		return 0;
}
/*
	
		CLASS Form

*/
Form::Form(STR name, TENSE tense, MOOD mood, ASPECT aspect, VOICE voice) {
	SetName(name);
	SetTense(tense);
	SetMood(mood);
	SetAspect(aspect);
	SetVoice(voice);
}

Form::~Form() {
	this->name.~STR();
}

bool Form::operator==(Form form) {
	return ( this->name == form.name && this->mood == form.mood && this->aspect == form.aspect && this->tense == form.tense && this->voice == form.voice ); 
}

bool Form::operator!=(Form form) {
	return !(*this == form) ; 
}

STR* Form::getName() {
	return &this->name;
}
TENSE* Form::getTense() {
	return &this->tense;
}
MOOD* Form::getMood() {
	return &this->mood;
}
ASPECT* Form::getAspect() {
	return &this->aspect;
}
VOICE* Form::getVoice() {
	return &this->voice;
}
void Form::SetName(STR name) {
	this->name = name;
}
void Form::SetTense(TENSE tense) {
	this->tense = tense;
}
void Form::SetMood(MOOD mood) {
	this->mood = mood;
}
void Form::SetAspect(ASPECT aspect) {
	this->aspect = aspect;
}
void Form::SetVoice(VOICE voice) {
	this->voice = voice;
}
/*

		CLASS DBWORD



*/
DBWORD::DBWORD(STR name) {
	SetName(name);
	SetDef("");
	SetType(TYPE_NONE);
}

DBWORD::~DBWORD() {
	DESTROY(name);
	DESTROY(def);
}
	

STR* DBWORD::getName() {
	return &this->name;
}
	
STR* DBWORD::getDef() {
	return &this->def;
}
	
TYPE* DBWORD::getType() {
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
DBVERB::DBVERB(STR name, bool irregular) : DBWORD(name) {
	
	SetIrregular(irregular);
}

DBVERB::~DBVERB() {
	DBWORD::~DBWORD();
	form.clear();
}

bool DBVERB::isIrregular() const {
	return this->irregular;
}

UINT DBVERB::getFormCount() const {
	return this->form.size();
}

Form* DBVERB::getForm(UINT i) {
	return this->form[i];
}

void DBVERB::SetIrregular(bool irregular) {
	this->irregular = irregular;
}

HRESULT DBVERB::AddForm(Form form) {
	for(UINT i = 0; i < this->form.size(); i++)
	{
		if(*this->form[i] == form)
			return E_FAIL; //la forme existe dej� dans la liste
	}
	this->form.push_back(&form);

	return S_OK; //forme ajout�e avec succ�s
}

HRESULT DBVERB::RemoveForm(Form form) {
	UINT i = 0;
	while(i < this->form.size() && *this->form[i] != form); //boucler tant qu'on ne trouve pas la forme

	if( i == this->form.size() ) //as t-on trouv� la forme?
		return E_FAIL; //non
	else
		this->form.erase(this->form.begin() + i);

	return S_OK; //forme supprim�e avec succ�s
}

/*
	CLASS DATABASE

*/
Database::Database() {
	for(UINT i = 0; i < 8; i++)
	{
		map[i] = new MapWord();
		map[i]->SetOffset(0);
	}
	//tester si le fichier est vide
	file.open( FILENAME , std::fstream::binary | std::fstream::in );

	if( !file.is_open() ) //le fichier n'existe pas encore
	{
			file.open(FILENAME,std::ios_base::binary | std::ios_base::in | std::ios_base::out);
			if(file.is_open() )
			file.write("DATABASE", sizeof(char) * 8);
	}
	else
		file.open(FILENAME,std::ios_base::binary | std::ios_base::in | std::ios_base::out); //juste ouvrir le fichier normalement

	
}

Database::~Database() {
	if(file.is_open())
		file.close();
}

HRESULT Database::LoadMap() {
	if(file.is_open())
	{
		file.seekg(std::ios_base::beg); //se mettre au d�but du fichier
		while(! file.eof() )
		{
			MapNextWord();
		}
		return S_OK;
	}
	else
		return E_FILENOTFOUND;
}
	
HRESULT Database::AddWord(DBWORD* word) {
	if(file.is_open())
	{
		file.seekg(std::ios_base::end); //se mettre � la fin du fichier
		

		file.write((char*)word->getType(), sizeof(TYPE)); //ecrire le type

		file.write((char*)word->getName()->getLength(), sizeof(UINT)); //ecrire la longueur du nom
		file.write((char*)word->getName()->getString(), sizeof(char) * *word->getName()->getLength() ); //ecrire la chaine de caracteres
		
		file.write((char*)word->getDef()->getLength(), sizeof(UINT)); //ecrire la longueur de la definition
		file.write((char*)word->getDef()->getString(), sizeof(char) * *word->getDef()->getLength() ); //ecrire la chaine de caracteres

		if(*word->getType() == VERB)	//tester si le mot est un verbe
		{
			DBVERB* verb = (DBVERB*)word; //caster le mot en verbe
			
			file.write((char*)verb->isIrregular(), sizeof(bool)); //ecrire le booleen sp�cifiant l'irr�gularit� du verbe

			file.write((char*)verb->getFormCount(), sizeof(UINT));  //ecrire le nombre de formes

			for(UINT i = 0; i < verb->getFormCount(); i++)
			{
				//ecrire la forme
				file.write((char*)verb->getForm(i)->getName()->getLength(), sizeof(UINT)); 
				file.write(verb->getForm(i)->getName()->getString(), sizeof(char) * *verb->getForm(i)->getName()->getLength()); 

				file.write((char*)verb->getForm(i)->getTense(), sizeof(TENSE));
				file.write((char*)verb->getForm(i)->getMood(), sizeof(MOOD)); 
				file.write((char*)verb->getForm(i)->getAspect(), sizeof(ASPECT));
				file.write((char*)verb->getForm(i)->getVoice(), sizeof(VOICE)); 

			}
			verb = 0; //abandonner le pointeur
		}
		return S_OK;
	}
	else
		return E_FILENOTFOUND;
}

HRESULT Database::MapNextWord()
{
		TYPE type;
		UINT offset = (UINT)file.tellg();

		file.read((char*)&type, sizeof(TYPE)); //lire le type

		UINT strLength;
		STR str;

		DBVERB* verb = new DBVERB();

		file.read((char*)&strLength, sizeof(UINT)); //lire la longueur du nom

		char* buf = new char[strLength];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres

		str.SetLength(strLength);
		str.SetString(buf);

		verb->SetName(str);

		delete[] buf;

		file.read((char*)&strLength, sizeof(UINT)); //lire la longueur de la definition

		buf = new char[strLength];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres

		str.SetLength(strLength);
		str.SetString(buf);

		verb->SetDef(str);

		delete[] buf;

		if(type == VERB)	//tester si le mot est un verbe
		{

			bool irregular;
			file.read((char*)&irregular, sizeof(bool)); //lire le booleen sp�cifiant l'irr�gularit� du verbe

			verb->SetIrregular(irregular);
			
			UINT formCount;
			file.read((char*)&formCount, sizeof(UINT));  //lire le nombre de formes

			for(UINT i = 0; i < formCount; i++)
			{
				Form form;
				//lire la forme
				file.read((char*)&strLength, sizeof(UINT)); //lire la longueur de la definition
				buf = new char[strLength];
				file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres

				form.getName()->SetLength(strLength);
				form.getName()->SetString(buf);

				

				delete[] buf;
				file.read((char*)form.getTense(), sizeof(TENSE));
				file.read((char*)form.getMood(), sizeof(MOOD)); 
				file.read((char*)form.getAspect(), sizeof(ASPECT));
				file.read((char*)form.getVoice(), sizeof(VOICE)); 

				

				HRESULT hr = verb->AddForm(form);
				if(hr != S_OK)
					return E_FAIL;
				
				MapWord mw;
				mw.SetOffset(offset);
				mw.SetSynonym(0);
				hr = map[*verb->getType()]->Add(&mw,*verb->getName());
				if(hr != S_OK)
					return E_FAIL;
			}

			verb = 0; //abandonner le pointeur
		}
		else	//le mot n'est pas un verbe
		{
			DBWORD* word = (DBWORD*)verb;

			MapWord mw;
			mw.SetOffset(offset);
			mw.SetSynonym(0);
			HRESULT hr = map[*word->getType()]->Add(&mw,*word->getName());
			if(hr != S_OK)
					return E_FAIL;

		}
		return S_OK;
}
