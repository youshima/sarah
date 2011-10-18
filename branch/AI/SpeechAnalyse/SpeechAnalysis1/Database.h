#pragma once
#include "Helpers.h"

#include <iostream> //traitement de fichiers
#include <fstream>

#define LIST(x) std::vector<x>

#define FILENAME "database.data"

enum TYPE {VERB, NOUN, ADJECTIVE, ADVERB, PRONOUN, PREPOSITION, FORMUNCTION, INTERJECTION, NONE_TYPE};
enum TENSE {PAST, NON_PAST, NONE_TENSE};
enum MOOD {INDICATIVE, SUBJUNCTIVE, IMPERATIVE, NONE_MOOD};
enum ASPECT {SIMPLE, CONTINUOUS, PERFECT, PERFECT_CONTINUOUS, NONE_ASPECT};
enum VOICE {ACTIVE, PASSIVE, NONE_VOICE};

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
		=> {le pointeur de length}
	*/
	UINT* GetLength();
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
	/*
		procedure PopHead
		{enlève le premier caractere}
	*/
	void PopBack();

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
	MapWord(UINT offset = 0);
	/*
		destructeur de MapWord
		{nettoie la mémoire}
	*/
	~MapWord();
	/*
		operateur de comparaison
		{compare le MapWord avec un autre}
		=> {vrai si les deux MapWord ont le meme offset}
	*/
	bool operator==(MapWord* word);
	/*
		operateur de comparaison
		{compare le MapWord avec un autre}
		=> {faux si les deux MapWord ont le meme offset}
	*/
	bool operator!=(MapWord* word);
	/*
		fonction GetOffset
		=> {retourne la valeur de l'offset}
	*/
	UINT GetOffset();
	/*
		fonction GetSynonym
		=> {retourne le prochain synonime du mot}
	*/
	MapWord* GetSynonym();
	/*
		procedure SetOffset
		{affecte la valeur offset à this->offset}
	*/
	void SetOffset(UINT offset);
	/*
		procedure SetSynonym
		{affecte la valeur de synonym au prochain synonime du mot}
	*/
	void SetSynonym(MapWord* synonym);
	/*
		fonction Add [recursive]
		{ajoute un enfant à la liste des enfants ou bien à leurs enfants suivant l'ordre alphabetique, name en minuscules}
		=> {
			S_OK si l'élément a bien été ajouté
			E_FAIL si l'élément existe dejà
			}
	*/
	HRESULT Add(MapWord* mw, STR name);
	/*
		fonction Find [recursive]
		=> { offset du mot recherché, 0 sinon, name en minuscules }
	*/
	UINT Find(STR name);
private:
	/*
		fonction GetChild
		{c minuscule} => {retourne le pointeur sur l'enfant à la position i, 0 si i >= nombre d'enfants}
	*/
	MapWord* GetChild(char c);
private:
	UINT offset;
	MapWord* child[26];
	MapWord* synonym; //pointeur au prochain synonime
};

/*
	structure FORM :
	definit une formes pour un verbe
*/
typedef struct FORM
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
	bool operator==(FORM form) {return ( this->name == form.name && this->mood == form.mood && this->aspect == form.aspect && this->tense == form.tense && this->voice == form.voice ); };
	/*
		operateur de comparaison entre deux FORM
		=> { faux si tous les parametres des élements sont égaux }
	*/
	bool operator!=(FORM form) {return !(*this == form) ; };

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
	STR* GetName();
	/*
		fonction GetDef
		=> {le pointeur sur def}
	*/
	STR* GetDef();
	/*
		fonction GetType
		=> {le pointeur sur type}
	*/
	TYPE* GetType();
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
	bool isIrregular() const;
	/*
		fonction GetFormCount
		=> {nombre de formes}
	*/
	UINT GetFormCount() const;
	/*
		fonction GetForm
		=> {le pointeur sur la forme à la position i}
	*/
	FORM* GetForm(UINT i);
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
		fonction LoadMap
		=> {
			S_OK si le chargement de la BDD c'est bien passé, 
			E_OUTOFMEMORY si problème de mémoire,
			E_fileNOTFOUND si fichier non trouvé,
			E_FAIL sinon 
			}
	*/
	HRESULT LoadMap();
	/*
		fonction AddWord
		=> {
			S_OK si la sauvegarde de la BDD c'est bien passé, 
			E_OUTOFMEMORY si problème de mémoire,
			E_FAIL sinon 
			}
	*/
	HRESULT AddWord(DBWORD* word);

private:
	/*
		fonction MapNextWord
		=> {
			S_OK si le mot a été mappé, 
			E_OUTOFMEMORY si problème de mémoire,
			E_FAIL sinon 
			}
	*/
	HRESULT MapNextWord();

private:
	MapWord* map[8]; //maps des offsets pour la BDD classées par type dans l'ordre de l'enuméré TYPE
	std::fstream file;
	

};