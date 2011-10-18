#include "StdAfx.h"
#include "Database.h"

/*
		CLASS MAPWORD

*/
MapWord::MapWord(UINT offset) {
	setOffset(offset);
	for(UINT i = 0; i < 26; i++)
		this->child[i] = 0; //tous les child à nul
	setSynonym(0);
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
	
void MapWord::setOffset(UINT offset) {
	this->offset = offset;
}
	
void MapWord::setSynonym(MapWord* synonym)
{
	this->synonym = synonym;
}

HRESULT MapWord::Add(MapWord* mw, STR name) {
	if(this == mw)
		return E_FAIL; //on essaye d'ajouter le même élément

	if(name != "")
	{
		
		if(this->getChild(name.getString()[0]) == 0) //si le fils n'existe pas encore
			this->child[ name.getString()[0] ] = new MapWord(); //en creer un
		name.popBack();//enlever le premier caractere 
		return this->getChild(name.getString()[0])->Add(mw, name); //calculer à quelle branche continuer récursivement
	}
	else //on a trouvé l'emplacement
	{
		setOffset(mw->getOffset());
		return S_OK; //ajouté avec succès
	}
}


UINT MapWord::Find(STR name)
{
	if(name != "")
	{
		
		if(this->getChild(name.getString()[0]) == 0) //si le fils existe
		{
			name.popBack();//enlever le premier caractere
			return this->getChild(name.getString()[0])->Find(name); //calculer à quelle branche continuer récursivement
		}
		else
			return 0; //n'existe pas
	}
	else
	{
		return getOffset(); //on a trouvé l'élément
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
	setName(name);
	setTense(tense);
	setMood(mood);
	setAspect(aspect);
	setVoice(voice);
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
void Form::setName(STR name) {
	this->name = name;
}
void Form::setTense(TENSE tense) {
	this->tense = tense;
}
void Form::setMood(MOOD mood) {
	this->mood = mood;
}
void Form::setAspect(ASPECT aspect) {
	this->aspect = aspect;
}
void Form::setVoice(VOICE voice) {
	this->voice = voice;
}
/*

		CLASS DBWORD



*/
DBWORD::DBWORD(STR name) {
	setName(name);
	setDef("");
	setType(TYPE_NONE);
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

void DBWORD::setName(STR name) {
	this->name = name;
}
	
void DBWORD::setDef(STR def) {
	this->def = def;
}
	
void DBWORD::setType(TYPE type) {
	this->type = type;
}

/*

		CLASS DBVERB


*/
DBVERB::DBVERB(STR name, bool irregular) : DBWORD(name) {
	
	setIrregular(irregular);
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

void DBVERB::setIrregular(bool irregular) {
	this->irregular = irregular;
}

HRESULT DBVERB::AddForm(Form form) {
	for(UINT i = 0; i < this->form.size(); i++)
	{
		if(*this->form[i] == form)
			return E_FAIL; //la forme existe dejà dans la liste
	}
	this->form.push_back(&form);

	return S_OK; //forme ajoutée avec succès
}

HRESULT DBVERB::RemoveForm(Form form) {
	UINT i = 0;
	while(i < this->form.size() && *this->form[i] != form); //boucler tant qu'on ne trouve pas la forme

	if( i == this->form.size() ) //as t-on trouvé la forme?
		return E_FAIL; //non
	else
		this->form.erase(this->form.begin() + i);

	return S_OK; //forme supprimée avec succès
}

/*
	CLASS DATABASE

*/
Database::Database() {
	for(UINT i = 0; i < 8; i++)
	{
		map[i] = new MapWord();
		map[i]->setOffset(0);
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
		file.seekg(std::ios_base::beg); //se mettre au début du fichier
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
		file.seekg(std::ios_base::end); //se mettre à la fin du fichier
		

		file.write((char*)word->getType(), sizeof(TYPE)); //ecrire le type

		write(word->getName());

		write(word->getDef());

		if(*word->getType() == VERB)	//tester si le mot est un verbe
		{
			DBVERB* verb = (DBVERB*)word; //caster le mot en verbe
			
			file.write((char*)verb->isIrregular(), sizeof(bool)); //ecrire le booleen spécifiant l'irrégularité du verbe

			file.write((char*)verb->getFormCount(), sizeof(UINT));  //ecrire le nombre de formes

			for(UINT i = 0; i < verb->getFormCount(); i++)
			{
				//ecrire la forme
				write(verb->getForm(i));

			}
			verb = 0; //abandonner le pointeur
		}
		return S_OK;
	}
	else
		return E_FILENOTFOUND;
}

HRESULT Database::MapNextWord() {

		TYPE type;
		UINT offset = (UINT)file.tellg();
		file.read((char*)&type, sizeof(TYPE)); //lire le type

		STR str;
		DBVERB* verb = new DBVERB();

		read(&str);
		verb->setName(str);

		read(&str);
		verb->setDef(str);

		if(type == VERB)	//tester si le mot est un verbe
		{

			bool irregular;
			file.read((char*)&irregular, sizeof(bool)); //lire le booleen spécifiant l'irrégularité du verbe

			verb->setIrregular(irregular);
			
			UINT formCount;
			file.read((char*)&formCount, sizeof(UINT));  //lire le nombre de formes

			for(UINT i = 0; i < formCount; i++)
			{
				Form form;
				//lire la forme
				read(&form);

				HRESULT hr = verb->AddForm(form);
				if(hr != S_OK)
					return E_FAIL;
				
				MapWord mw;
				mw.setOffset(offset);
				mw.setSynonym(0);
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
			mw.setOffset(offset);
			mw.setSynonym(0);
			HRESULT hr = map[*word->getType()]->Add(&mw,*word->getName());
			if(hr != S_OK)
					return E_FAIL;

		}
		return S_OK;
}

void Database::write(STR* str) {

	file.write((char*)str->getLength(), sizeof(UINT)); //ecrire la longueur
	file.write((char*)str->getString(), sizeof(char) * *str->getLength() ); //ecrire la chaine de caracteres
}
void Database::write(Form *form) {

	//ecrire la forme
	write(form->getName());

	file.write((char*)form->getTense(), sizeof(TENSE));
	file.write((char*)form->getMood(), sizeof(MOOD)); 
	file.write((char*)form->getAspect(), sizeof(ASPECT));
	file.write((char*)form->getVoice(), sizeof(VOICE)); 
}
void Database::read(STR* str) {

		UINT strLength;
		file.read((char*)&strLength, sizeof(UINT)); //lire la longueur du nom
		char* buf = new char[strLength+1];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres
		buf[strLength] = '\0';
		str->setString(buf);

		delete[] buf;
}
void Database::read(Form* form) {

		read(form->getName());

		file.read((char*)form->getTense(), sizeof(TENSE));
		file.read((char*)form->getMood(), sizeof(MOOD)); 
		file.read((char*)form->getAspect(), sizeof(ASPECT));
		file.read((char*)form->getVoice(), sizeof(VOICE)); 
}