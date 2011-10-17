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
		{nettoie la mémoire}
	*/
	~STR();
	
	/*
		operateur d'affectation
		{affecte la chaine de caracteres à l'élement}
	*/
	void operator=(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {vrai si les deux chaines ont la même taille et les mêmes caracteres}
	*/
	bool operator==(const char* c);
	/*
		operateur de comparaison
		{compare le STR avec une chaine de caracteres}
		=> {faux si les deux chaines ont la même taille et les mêmes caracteres}
	*/
	bool operator!=(const char* c);
	/*
		operateur d'affectation
		{affecte la valeur d'un STR à l'élement}
	*/
	void operator=(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {vrai si les deux STR ont la même taille et les mêmes caracteres}
	*/
	bool operator==(STR str);
	/*
		operateur de comparaison
		{compare le STR avec un autre STR}
		=> {faux si les deux STR ont la même taille et les mêmes caracteres}
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
		{affecte la chaine de caracteres à celle de l'élement}
	*/
	void SetString(char* c);
	/*
		procedure SetLength
		{affecte la longueur à celle de l'élement}
	*/
	void SetLength(UINT length);

private:
	char* c;
	UINT length;
	
};

/*
	classe MapWord
	représente le mappage de la base de données pour la partie analyse
*/
class MapWord
{
public:
	/*
		constructeur de MapWord
		{initialise les variables par défaut ou selon l'utilisateur}
	*/
	MapWord(str = "", offset = 0);
	/*
		destructeur de MapWord
		{nettoie la mémoire}
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
		=> {retourne le pointeur sur l'enfant à la position i, 0 si i >= nombre d'enfants}
	*/
	MapWord* GetChildren(UINT i);
	/*
		procedure SetString
		{affecte la valeur de str à this->str}
	*/
	void SetString(STR str);
	/*
		procedure SetOffset
		{affecte la valeur offset à this->offset}
	*/
	void SetOffset(UINT offset);
	/*
		fonction AddChildren [recursive]
		{ajoute un enfant à la liste des enfants ou bien à leurs enfants suivant l'ordre alphabetique}
		=> {
			S_OK si l'élément a bien été ajouté
			E_FAIL si l'élément existe dejà
			}
	*/
	HRESULT AddChildren(MapWord* mw);
	/*
		fonction RemoveChildren [recursive]
		{retrouve et supprime l'élément dans la liste des enfants}
		=> {
			S_OK si l'élément a bien été supprimé
			E_FAIL si l'élément n'a pas été trouvé
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
	représente le mappage de la base de données pour la partie reponse
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
		=> { vrai si tous les parametres des élements sont égaux }
	*/
	bool operator==(_FORM* form) {return ( this->name == form->name && this->mood == form->mood && this->aspect == form->aspect && this->tense == form->tense && this->voice == form->voice ); };
	/*
		operateur de comparaison entre deux FORM
		=> { faux si tous les parametres des élements sont égaux }
	*/
	bool operator!=(_FORM* form) {return !(this == form) };

} FORM;
/*
	classe DBWORD :
	spécifie le contenu d'un mot stoqué dans la BDD
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
		{nettoie la mémoire}
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
		{affecte la valeur de name à self.name}
	*/
	void SetName(STR name);
	/*
		procedure SetDef
		{affecte la valeur de def à self.def}
	*/
	void SetDef(STR def);
	/*
		procedure SetType
		{affecte la valeur de type à self.type}
	*/
	void SetType(TYPE type);

private:
	STR name;
	STR def;
	TYPE type;
};
/*
	classe DBVERB :
	herite de DBWORD et spécifie un verbe
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
		{nettoie la mémoire}
	*/
	~DBVERB();

	/*
		fonction isIrregular
		=> {vrai si le verbe est irrégulier}
	*/
	bool isIrregular();
	/*
		fonction GetFormList
		=> {le pointeur sur la liste des formess du verbe}
	*/
	LIST(FORM)* GetFormList() const;
	/*
		procedure SetIrregular
		{affecte la valeur de irregular à self.irregular}
	*/
	void SetIrregular(bool irregular);
	/*
		fonction AddForm
		{ajoute une forme à la liste des formes du verbe}
		=> {
			S_OK si l'opération c'est bien déroulée
			E_FAIL si la forme existe dejà dans la liste
		}
	*/
	HRESULT AddForm(FORM form);
	/*
		fonction RemoveForm
		{trouve et enleve une forme de la liste des formes du verbe}
		=> {
			S_OK si l'opération c'est bien déroulée
			E_FAIL si la forme n'a pas été trouvée
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
		{nettoie la mémoire}
	*/
	~Database();

	/*
		fonction Load
		=> {
			S_OK si le chargement de la BDD c'est bien passé, 
			E_OUTOFMEMORY si problème de mémoire,
			E_FILENOTFOUND si fichier non trouvé,
			E_FAIL sinon 
			}
	*/
	HRESULT Load();
	/*
		fonction Save
		=> {
			S_OK si la sauvegarde de la BDD c'est bien passé, 
			E_OUTOFMEMORY si problème de mémoire,
			E_FAIL sinon 
			}
	*/
	HRESULT Save();
	/*
		fonction Remap
		=> {
			S_OK si les deux maps ont été generées corréctement, 
			E_FAIL sinon 
			}
	*/
	HRESULT Remap();
private:
	MapWord* map; //map triée par ordre alphabetique
	MapWord_s* map_s; //map triée par type et synonime
	fstream FILE;
	

};