#pragma once
#include "Helpers.h"

#include <iostream> //traitement de fichiers
#include <fstream>

#define LIST(x) std::vector<x>

#define FILENAME "database.data"

enum TYPE {VERB, NOUN, ADJECTIVE, ADVERB, PRONOUN, PREPOSITION, FORMUNCTION, INTERJECTION, NONE};
enum TENSE {PAST, NON_PAST, NONE};
enum MOOD {INDICATIVE, SUBJUNCTIVE, IMPERATIVE, NONE};
enum ASPECT {SIMPLE, CONTINUOUS, PERFECT, PERFECT_CONTINUOUS, NONE};
enum VOICE {ACTIVE, PASSIVE, NONE};

/*
	structure STR :
	contient une chaine de caracteres et sa longueur
*/

class STR
{
public:
	/*
		constructeur de STR
		{initialise les variables}
	*/
	STR(const char* c = "");
	/*
		destructeur de STR
		{nettoie la m�moire}
	*/
	~STR();
	
	/*
		operateur d'affectation
		{affecte la chaine de caracteres � l'�lement}
	*/
	void operator=(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {vrai si les deux chaines ont la m�me taille et les m�mes caracteres}
	*/
	bool operator==(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {faux si les deux chaines ont la m�me taille et les m�mes caracteres}
	*/
	bool operator!=(const char* c);
	/*
		operateur d'affectation
		{affecte la valeur d'un STR � l'�lement}
	*/
	void operator=(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {vrai si les deux STR ont la m�me taille et les m�mes caracteres}
	*/
	bool operator==(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {faux si les deux STR ont la m�me taille et les m�mes caracteres}
	*/
	bool operator!=(STR str);
	/*
		fonction GetString
		=> {le pointeur c}
	*/
	char* GetString() const;
	/*
		fonction GetLength
		=> {la valeur de l}
	*/
	UINT GetLength() const;
	/*
		procedure SetString
		{affecte la chaine de caracteres � celle de l'�lement}
	*/
	void SetString(char* c);
	/*
		procedure SetLength
		{affecte la longueur � celle de l'�lement}
	*/
	void SetLength(UINT length);

private:
	char* c;
	UINT length;
	
};

/*
	classe MapWord
	repr�sente le mappage de la base de donn�es pour la partie analyse
*/
class MapWord
{
public:
	/*
		constructeur de MapWord
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	MapWord(str = "", offset = 0);
	/*
		destructeur de MapWord
		{nettoie la m�moire}
	*/
	~MapWord();
	/*
		operateur de comparaison
		{compare le MapWord avec un autre}
		=> {vrai si les deux MapWord ont le meme nom et offset}
	*/
	bool operator==(MapWord* word);
	/*
		operateur de comparaison
		{compare le MapWord avec un autre}
		=> {faux si les deux MapWord ont le meme nom et offset}
	*/
	bool operator!=(MapWord* word);
	/*
		fonction GetString
		=> {ponteur de str}
	*/
	STR* GetString();
	/*
		fonction GetOffset
		=> {retourne la valeur de l'offset}
	*/
	UINT GetOffset();
	/*
		fonction GetChildrenCount
		=> {retourne le nombre d'enfants}
	*/
	UINT GetChildrenCount();
	/*
		fonction GetChildren
		=> {retourne le pointeur sur l'enfant � la position i, 0 si i >= nombre d'enfants}
	*/
	MapWord* GetChildren(UINT i);
	/*
		procedure SetString
		{affecte la valeur de str � this->str}
	*/
	void SetString(STR str);
	/*
		procedure SetOffset
		{affecte la valeur offset � this->offset}
	*/
	void SetOffset(UINT offset);
	/*
		fonction AddChildren [recursive]
		{ajoute un enfant � la liste des enfants ou bien � leurs enfants suivant l'ordre alphabetique}
		=> {
			S_OK si l'�l�ment a bien �t� ajout�
			E_FAIL si l'�l�ment existe dej�
			}
	*/
	HRESULT AddChildren(MapWord* mw);
	/*
		fonction RemoveChildren [recursive]
		{retrouve et supprime l'�l�ment dans la liste des enfants}
		=> {
			S_OK si l'�l�ment a bien �t� supprim�
			E_FAIL si l'�l�ment n'a pas �t� trouv�
			}
	*/
	HRESULT RemoveChildren(MapWord* mw);

private:
	STR str;
	UINT offset;
	LIST(MapWord) child;
};

/*
	classe MapWord_s
	repr�sente le mappage de la base de donn�es pour la partie reponse
*/
class MapWord_s : MapWord
{
	TYPE type;
	_MapWord_s* synonym; //pointeur au prochain synonime
};

/*
	structure FORM :
	definit une formes pour un verbe
*/
typedef struct _FORM
{
	STR name;
	TENSE tense;
	MOOD mood;
	ASPECT aspect;
	VOICE voice;
	/*
		operateur de comparaison entre deux FORM
		=> { vrai si tous les parametres des �lements sont �gaux }
	*/
	bool operator==(_FORM* form) {return ( this->name == form->name && this->mood == form->mood && this->aspect == form->aspect && this->tense == form->tense && this->voice == form->voice ); };
	/*
		operateur de comparaison entre deux FORM
		=> { faux si tous les parametres des �lements sont �gaux }
	*/
	bool operator!=(_FORM* form) {return !(this == form) };

} FORM;
/*
	classe DBWORD :
	sp�cifie le contenu d'un mot stoqu� dans la BDD
*/
class DBWORD
{
public:
	/*
		constructeur de DBWORD
		{initialise les variables]
	*/
	DBWORD(STR name = "");
	/*
		destructeur de DBWORD
		{nettoie la m�moire}
	*/
	~DBWORD();
	
	/*
		fonction GetName
		=> {le pointeur sur name}
	*/
	STR* GetName() const;
	/*
		fonction GetDef
		=> {le pointeur sur def}
	*/
	STR* GetDef() const;
	/*
		fonction GetType
		=> {le pointeur sur type}
	*/
	TYPE GetType() const;
	/*
		procedure SetName
		{affecte la valeur de name � self.name}
	*/
	void SetName(STR name);
	/*
		procedure SetDef
		{affecte la valeur de def � self.def}
	*/
	void SetDef(STR def);
	/*
		procedure SetType
		{affecte la valeur de type � self.type}
	*/
	void SetType(TYPE type);

private:
	STR name;
	STR def;
	TYPE type;
};
/*
	classe DBVERB :
	herite de DBWORD et sp�cifie un verbe
*/
class DBVERB : public DBWORD
{
public:
	/*
		constructeur de DBVERB
		{intialise les variables}
	*/
	DBVERB(STR name = "", bool irregular = false);
	/*
		destructeur de DBVERB
		{nettoie la m�moire}
	*/
	~DBVERB();

	/*
		fonction isIrregular
		=> {vrai si le verbe est irr�gulier}
	*/
	bool isIrregular();
	/*
		fonction GetFormList
		=> {le pointeur sur la liste des formess du verbe}
	*/
	LIST(FORM)* GetFormList() const;
	/*
		procedure SetIrregular
		{affecte la valeur de irregular � self.irregular}
	*/
	void SetIrregular(bool irregular);
	/*
		fonction AddForm
		{ajoute une forme � la liste des formes du verbe}
		=> {
			S_OK si l'op�ration c'est bien d�roul�e
			E_FAIL si la forme existe dej� dans la liste
		}
	*/
	HRESULT AddForm(FORM form);
	/*
		fonction RemoveForm
		{trouve et enleve une forme de la liste des formes du verbe}
		=> {
			S_OK si l'op�ration c'est bien d�roul�e
			E_FAIL si la forme n'a pas �t� trouv�e
		}
	*/
	HRESULT RemoveForm(FORM form);

private:
	LIST(FORM) form;
	bool irregular;
};

/*
	classe Database
	gestion generale de la BDD
*/
class Database
{
public:
	/*
		constructeur de Database
		{initialise les variables}
	*/
	Database();
	/*
		destructeur de Database
		{nettoie la m�moire}
	*/
	~Database();

	/*
		fonction Load
		=> {
			S_OK si le chargement de la BDD c'est bien pass�, 
			E_OUTOFMEMORY si probl�me de m�moire,
			E_FILENOTFOUND si fichier non trouv�,
			E_FAIL sinon 
			}
	*/
	HRESULT Load();
	/*
		fonction Save
		=> {
			S_OK si la sauvegarde de la BDD c'est bien pass�, 
			E_OUTOFMEMORY si probl�me de m�moire,
			E_FAIL sinon 
			}
	*/
	HRESULT Save();
	/*
		fonction Remap
		=> {
			S_OK si les deux maps ont �t� gener�es corr�ctement, 
			E_FAIL sinon 
			}
	*/
	HRESULT Remap();
private:
	MapWord* map; //map tri�e par ordre alphabetique
	MapWord_s* map_s; //map tri�e par type et synonime
	fstream FILE;
	

};