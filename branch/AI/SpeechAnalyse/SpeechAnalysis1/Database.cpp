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

RechercheInfo::RechercheInfo(STR mot)
{
	strcpy(this->mot, mot.getString());
	//Par defaut, le constructeur définira les regle de parsing et le site visé
}

RechercheInfo::~RechercheInfo()
{
}

HRESULT RechercheInfo::rechercheEtAjout()
{
	//Le parseur sera ici.

	//L'ajout du mot dans la Database se fera ici.

	return S_OK;
}

int RechercheInfo::strrch (char * string, char * recherche)
{
	int i,j;
	int max1 = (strlen(string) - strlen(recherche));//Calcule une fois pour toutes les longueurs de string et de recherche
	int max2 = strlen(recherche);//                   pour ne pas avoir à les recalculer à chaques tours de boucles

	for (i = 0 ; i <= max1 ; i ++)
	{
		for (j = 0 ; j < max2 ; j ++)
		{
			if (string[i + j] != recherche[j])
			{
				break;
			}
		}
		if (j == max2)
		{
			return i;
		}
	}
	return -1;
}

int RechercheInfo::taille_corps(char *reponse)
{
	int corps = 0;
	char * str;
	strcpy(str, strstr(reponse, "\r\n\r\n"));//Coupe le header de la réponse qui se termine forcement par "\r\n\r\n" (mais laisse la chaine "\r\n\r\n")

	while (str[corps + 4] != '\0')//On doit donc calculer la longueur du corps à partir de la fin de la chaine "\r\n\r\n" soit 4 caracteres plus loin
	{
		corps++;
	}
	return corps;
}

char * RechercheInfo::http_get(char * url_path, char * url_server)
{
	//Envoie la requête donnée en paramètre et retourne la réponse du serveur
	SOCKET s;
	char reponse[64000];
	char buffer[64000];
	char requete[64000] = "GET ";
	int n, corps;

	s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);//Création de la socket
	if (s == INVALID_SOCKET)//Erreur d'initialisation de la socket
	{
		printf("La fonction socket a echoue.\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
		system("pause");//								* EXCEPTION ??
		return "0";//									*
	}
	else//La socket est correctement initialisée
	{
		SOCKADDR_IN server;
		struct hostent *remoteHost = gethostbyname(url_server);//Fait une requete DNS pour avoir l'adresse IP du serveur

		if (remoteHost->h_addr_list[0] == 0)//La requete DNS a echouée
		{
			printf("Erreur de connexion au DNS...\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
			system("pause");//								* EXCEPTION ??
			return "0";//									* MEME CHOSE...
		}
	            
		server.sin_family = AF_INET;
		server.sin_addr.s_addr = *(u_long *) remoteHost->h_addr_list[0];//IP du serveur
		server.sin_port = htons(80);//Port de communication 80
		memset(&server.sin_zero, '\0', sizeof(server.sin_zero));
	            
		if (connect(s, (SOCKADDR *)&server, sizeof(server)) == SOCKET_ERROR)//Connection au serveur
		{
			printf("Impossible de se connecter au serveur !\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
			system("pause");//								* EXCEPTION ??
			return "0";//									* MEME CHOSE...
		}
		else//On est connecté au serveur
		{
			strcat(requete, url_path);//Construction de la requete HTTP...
			strcat(requete, " HTTP/1.1\r\nHost: ");
			strcat(requete, url_server);
			strcat(requete, "\r\nUser-Agent: Mozilla/5.0 (Windows NT 6.0; rv:6.0.1) Gecko/20100101 Firefox/6.0.1\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\nAccept-Language: fr,fr-fr;q=0.8,en-us;q=0.5,en;q=0.3\r\nAccept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\r\nConnection: keep-alive\r\n\r\n");
			
			send(s, requete, (int)strlen(requete), 0);//Envoi de la requete HTTP
			n = recv(s, reponse, sizeof(reponse) - 1, 0);//Reception de la reponse HTTP
			reponse[n] = '\0';
			corps = this->taille_corps(reponse);//Calcul de la taille du corps de la reponse
			if (strrch(reponse, "Transfer-Encoding: chunked") != -1)//Reception de la suite de la reponse si elle est en encodage "chunked"
			{
				do
				{
					n = recv(s, buffer, sizeof(buffer) - 1, 0);//reception d'une partie de la reponse
					buffer[n] = '\0';
					strcat(reponse, buffer);//Concatenation de la partie de la reponse
					n = strrch(buffer, "0\r\n\r\n");
				}
				while ((n != 0) && (n != strlen(buffer) - 5));//On boucle tant qu'on a pas reçu entierement la reponse
			}
			else if (corps == 0)//Si la reponse ne contient que l'entête (le header) alors on attend le corps...
			{
				n = recv(s, buffer, sizeof(buffer) - 1, 0);///reception du corps de la reponse...
				buffer[n] = '\0';
				strcat(reponse, buffer);//Concatenation du corps de la reponse
			}
			closesocket(s);//Fermeture de la socket
			if (n != SOCKET_ERROR)
			{
				return reponse;
			}
			else
			{
				printf("Pas de connexion reseau.\n");//		* A CHANGER EN FONCTION DE L'INTERFACE !!!
				system("pause");//							* EXCEPTION ??
				return "0";//								* MEME CHOSE...
			}
		}
	}
	return "0";
}