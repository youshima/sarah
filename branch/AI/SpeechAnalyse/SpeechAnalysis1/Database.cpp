#include "StdAfx.h"
#include "Database.h"

using namespace AI;

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
	
UINT* MapWord::getOffset() {
	return &this->offset;
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

HRESULT MapWord::Add(MapWord* mw, std::string name) {
	if(this == mw)
		return E_FAIL; //on essaye d'ajouter le même élément

	if(name != "")
	{
		
		if(this->getChild(name[0]) == 0) //si le fils n'existe pas encore
			this->child[ name[0] ] = new MapWord(); //en creer un
		name.erase(name.begin());//enlever le premier caractere 
		return this->getChild(name[0])->Add(mw, name); //calculer à quelle branche continuer récursivement
	}
	else //on a trouvé l'emplacement
	{
		setOffset(*mw->getOffset());
		return S_OK; //ajouté avec succès
	}
}


UINT MapWord::Find(std::string& name)
{
	if(name != "")
	{
		
		if(this->getChild(name[0]) == 0) //si le fils existe
		{
			name.erase(name.begin());//enlever le premier caractere
			return this->getChild(name[0])->Find(name); //calculer à quelle branche continuer récursivement
		}
		else
			return 0; //n'existe pas
	}
	else
	{
		return *getOffset(); //on a trouvé l'élément
	}
}

MapWord* MapWord::getChild(char c) {
	if( c >= 'a' && c <= 'z')
		return this->child[c - 'a'];
	else
		return 0;
}

/*

		CLASS DBWORD



*/
DBWORD::DBWORD(std::string name) {
	setName(name);
	this->type = TYPE_NONE;
}

DBWORD::~DBWORD() {
	DESTROY(name);
	DESTROY(def);
}
	

std::string* DBWORD::getName() {
	return &this->name;
}
	
std::string* DBWORD::getDef() {
	return &this->def;
}
	
TYPE* DBWORD::getType() {
	return &this->type;
}

void DBWORD::setName(std::string name) {
	this->name = name;
}
	
void DBWORD::setDef(std::string def) {
	this->def = def;
}
	
void DBWORD::setType(TYPE type) {
	this->type = type;
}

/*

		CLASS DBVERB


*/
DBVERB::DBVERB(std::string name, bool irregular) : DBWORD(name) {
	
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

Form* DBVERB::getForm(UINT& i) {
	return this->form[i];
}

void DBVERB::setIrregular(bool irregular) {
	this->irregular = irregular;
}

HRESULT DBVERB::AddForm(Form& form) {
	for(UINT i = 0; i < this->form.size(); i++)
	{
		if(*this->form[i] == form)
			return E_FAIL; //la forme existe dejà dans la liste
	}
	this->form.push_back(&form);

	return S_OK; //forme ajoutée avec succès
}

HRESULT DBVERB::RemoveForm(Form& form) {
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
	bool existed;
	file.open(FILENAME_DATA, existed);

	if(file.isEmpty() ) //le fichier est vide
	{	
		std::string check = "DATABASE";
		file.write(check); //poser la signature
	}
	file.close(); //fermer le fichier
}

Database::~Database() {
	file.~File();
}

HRESULT Database::LoadMap() {

	bool existed;
	file.open(FILENAME_DATA, existed);
	if(file.isOpen())
	{
		if( file.isEmpty() )
		{
			file.close();
			return E_FAIL;
		}
		//
		std::string check; //signature
		file.read(check);
		if(check != "DATABASE") //il y a erreur
			return E_FAIL;

		while(! file.eof() )
		{
			MapNextWord();
		}
		file.close();
		return S_OK;
	}
	else
	{
		file.close();
		return E_FILENOTFOUND;
	}
}
	
HRESULT Database::AddWord(DBWORD& word) {

	bool existed;
	file.open(FILENAME_DATA, existed);

	if(file.isOpen())
	{
		file.toEnd();
		

		file.write(*word.getType()); //ecrire le type

		file.write(*word.getName());

		file.write(*word.getDef());

		if(*word.getType() == VERB)	//tester si le mot est un verbe
		{
			DBVERB* verb = (DBVERB*)&word; //caster le mot en verbe
			
			file.write(verb->isIrregular()); //ecrire le booleen spécifiant l'irrégularité du verbe

			UINT val = verb->getFormCount();

			file.write((int)val); //ecrire le nombre de formes

			for(UINT i = 0; i < val ; i++)
			{
				//ecrire la forme
				file.write(*verb->getForm(i));

			}
			verb = 0; //abandonner le pointeur
		}
		return S_OK;
	}
	else
		return E_FILENOTFOUND;
}

DBWORD * Database::Getword(std::string& name) {

	bool existed;
	file.open(FILENAME_DATA, existed);
	DBWORD * word;
	std::string wname;
	std::string wdef;
	bool virregular;

	if(file.isOpen())
	{
		TYPE word_type; 

		file.to(this->Find(name));//On se place dans le fichier a l'offset du mot recherché

		file.read(word_type);//On lit le type du mot

		if (word_type == VERB)//On lit le verbe
		{
			DBVERB * verb;
			int nb_forms;
			AI::Form vform;
			verb = new DBVERB(name);
			verb->setType(word_type);
			file.read(wname);
			file.read(wdef);
			verb->setDef(wdef);
			file.read(virregular); //lire le booleen spécifiant l'irrégularité du verbe
			verb->setIrregular(virregular);
			file.read(nb_forms); //lire le nombre de formes
			for(int i = 0; i < nb_forms ; i++)
			{
				//lire la forme
				file.read(vform);
				verb->AddFormW(vform);
			}
			return (DBWORD*)verb;
		}
		else//On lit le mot
		{
			DBWORD * word;
			word = new DBWORD(name);
			word->setType(word_type);
			file.read(wname);
			file.read(wdef);
			word->setDef(wdef);

			return word;
		}
	}
	else
		return 0;
}

HRESULT Database::MapNextWord() {

		TYPE type;
		UINT offset = file.getReadCursor();
		file.read(type);//lire le type

		std::string str;
		DBVERB* verb = new DBVERB();

		file.read(str);
		verb->setName(str);

		file.read(str);
		verb->setDef(str);

		if(type == VERB)	//tester si le mot est un verbe
		{

			bool irregular;
			file.read(irregular);//lire le booleen spécifiant l'irrégularité du verbe

			verb->setIrregular(irregular);
			
			int formCount;
			file.read(formCount);//lire le nombre de formes

			for(UINT i = 0; i < (UINT)formCount; i++)
			{
				Form form;
				//lire la forme
				file.read(form);

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


UINT Database::Find(std::string& name) {
	for(UINT i = 0; i < 8; i++)
	{
		UINT off = this->map[i]->Find(name);
		if(off > 0)
			return off;
	}
	return 0;
}

bool Database::Exist(std::string& name) {
	return (this->Find(name) != 0);
}