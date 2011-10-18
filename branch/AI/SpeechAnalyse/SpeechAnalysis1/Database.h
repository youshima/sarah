#pragma once
#include "Helpers.h"

#include <iostream> //traitement de fichiers
#include <fstream>

#define LIST(x) std::vector<x>

#define FILENAME "database.data"

enum TYPE {VERB, NOUN, ADJECTIVE, ADVERB, PRONOUN, PREPOSITION, FormUNCTION, INTERJECTION, TYPE_NONE};
enum TENSE {PAST, NON_PAST, TENSE_NONE};
enum MOOD {INDICATIVE, SUBJUNCTIVE, IMPERATIVE, MOOD_NONE};
enum ASPECT {SIMPLE, CONTINUOUS, PERFECT, PERFECT_CONTINUOUS, ASPECT_NONE};
enum VOICE {ACTIVE, PASSIVE, VOICE_NONE};

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
		=> {le pointeur de length}
	*/
	UINT* GetLength();
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
	/*
		procedure PopHead
		{enl�ve le premier caractere}
	*/
	void PopBack();

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
	MapWord(UINT offset = 0);
	/*
		destructeur de MapWord
		{nettoie la m�moire}
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
		{affecte la valeur offset � this->offset}
	*/
	void SetOffset(UINT offset);
	/*
		procedure SetSynonym
		{affecte la valeur de synonym au prochain synonime du mot}
	*/
	void SetSynonym(MapWord* synonym);
	/*
		fonction Add [recursive]
		{ajoute un enfant � la liste des enfants ou bien � leurs enfants suivant l'ordre alphabetique, name en minuscules}
		=> {
			S_OK si l'�l�ment a bien �t� ajout�
			E_FAIL si l'�l�ment existe dej�
			}
	*/
	HRESULT Add(MapWord* mw, STR name);
	/*
		fonction Find [recursive]
		=> { offset du mot recherch�, 0 sinon, name en minuscules }
	*/
	UINT Find(STR name);
private:
	/*
		fonction GetChild
		{c minuscule} => {retourne le pointeur sur l'enfant � la position i, 0 si i >= nombre d'enfants}
	*/
	MapWord* GetChild(char c);
private:
	UINT offset;
	MapWord* child[26];
	MapWord* synonym; //pointeur au prochain synonime
};

/*
	class Form :
	definit une formes pour un verbe
*/
class Form
{
public:
	/*
		constructeur de Form
		{initialise les variables par d�faut ou selon l'utilisateur}
	*/
	Form(STR name = "", TENSE tense = TENSE_NONE, MOOD mood = MOOD_NONE, ASPECT aspect = ASPECT_NONE, VOICE voice = VOICE_NONE);
	/*
		destructeur de Form
		{nettoie la m�moire}
	*/
	~Form();
	/*
		operateur de comparaison entre deux Form
		=> { vrai si tous les parametres des �lements sont �gaux }
	*/
	bool operator==(Form form);
	/*
		operateur de comparaison entre deux Form
		=> { faux si tous les parametres des �lements sont �gaux }
	*/
	bool operator!=(Form form);
	/*
		fonction GetName
		=> { pointeur sur le nom de la forme }
	*/
	STR* GetName();
	/*
		fonction GetTense
		=> { pointeur sur le tense de la forme }
	*/
	TENSE* GetTense();
	/*
		fonction GetMood
		=> { pointeur sur le mood de la forme }
	*/
	MOOD* GetMood();
	/*
		fonction GetAspect
		=> { pointeur sur l'aspect de la forme }
	*/
	ASPECT* GetAspect();
	/*
		fonction GetVoice
		=> { pointeur sur voice de la forme }
	*/
	VOICE* GetVoice();

	/*
		procedure SetName
		{ attribue le nom de la forme }
	*/
	void SetName(STR name);
	/*
		procedure SetTense
		{ attribue le tense de la forme }
	*/
	void SetTense(TENSE tense);
	/*
		procedure SetMood
		{ attribue le mood de la forme }
	*/
	void SetMood(MOOD mood);
	/*
		procedure SetAspect
		{ attribue l'aspect de la forme }
	*/
	void SetAspect(ASPECT aspect);
	/*
		fonction GetVoice
		{ attribue le voice de la forme }
	*/
	void SetVoice(VOICE voice);
private:
	STR name;
	TENSE tense;
	MOOD mood;
	ASPECT aspect;
	VOICE voice;
};
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
	bool isIrregular() const;
	/*
		fonction GetFormCount
		=> {nombre de formes}
	*/
	UINT GetFormCount() const;
	/*
		fonction GetForm
		=> {le pointeur sur la forme � la position i}
	*/
	Form* GetForm(UINT i);
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
	HRESULT AddForm(Form form);
	/*
		fonction RemoveForm
		{trouve et enleve une forme de la liste des formes du verbe}
		=> {
			S_OK si l'op�ration c'est bien d�roul�e
			E_FAIL si la forme n'a pas �t� trouv�e
		}
	*/
	HRESULT RemoveForm(Form form);

private:
	//LIST(Form*) form;
	std::vector<Form*> form;
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
		fonction LoadMap
		=> {
			S_OK si le chargement de la BDD c'est bien pass�, 
			E_OUTOFMEMORY si probl�me de m�moire,
			E_fileNOTFOUND si fichier non trouv�,
			E_FAIL sinon 
			}
	*/
	HRESULT LoadMap();
	/*
		fonction AddWord
		=> {
			S_OK si la sauvegarde de la BDD c'est bien pass�, 
			E_OUTOFMEMORY si probl�me de m�moire,
			E_FAIL sinon 
			}
	*/
	HRESULT AddWord(DBWORD* word);

private:
	/*
		fonction MapNextWord
		=> {
			S_OK si le mot a �t� mapp�, 
			E_OUTOFMEMORY si probl�me de m�moire,
			E_FAIL sinon 
			}
	*/
	HRESULT MapNextWord();

private:
	MapWord* map[8]; //maps des offsets pour la BDD class�es par type dans l'ordre de l'enum�r� TYPE
	std::fstream file;
	

};