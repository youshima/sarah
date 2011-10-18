#pragma once
#include "Helpers.h"
#include "STR.h"

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
		fonction getOffset
		=> {retourne la valeur de l'offset}
	*/
	UINT getOffset();
	/*
		fonction getSynonym
		=> {retourne le prochain synonime du mot}
	*/
	MapWord* getSynonym();
	/*
		procedure setOffset
		{affecte la valeur offset à this->offset}
	*/
	void setOffset(UINT offset);
	/*
		procedure setSynonym
		{affecte la valeur de synonym au prochain synonime du mot}
	*/
	void setSynonym(MapWord* synonym);
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
		fonction getChild
		{c minuscule} => {retourne le pointeur sur l'enfant à la position i, 0 si i >= nombre d'enfants}
	*/
	MapWord* getChild(char c);

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
		{initialise les variables par défaut ou selon l'utilisateur}
	*/
	Form(STR name = "", TENSE tense = TENSE_NONE, MOOD mood = MOOD_NONE, ASPECT aspect = ASPECT_NONE, VOICE voice = VOICE_NONE);
	/*
		destructeur de Form
		{nettoie la mémoire}
	*/
	~Form();
	/*
		operateur de comparaison entre deux Form
		=> { vrai si tous les parametres des élements sont égaux }
	*/
	bool operator==(Form form);
	/*
		operateur de comparaison entre deux Form
		=> { faux si tous les parametres des élements sont égaux }
	*/
	bool operator!=(Form form);
	/*
		fonction getName
		=> { pointeur sur le nom de la forme }
	*/
	STR* getName();
	/*
		fonction getTense
		=> { pointeur sur le tense de la forme }
	*/
	TENSE* getTense();
	/*
		fonction getMood
		=> { pointeur sur le mood de la forme }
	*/
	MOOD* getMood();
	/*
		fonction getAspect
		=> { pointeur sur l'aspect de la forme }
	*/
	ASPECT* getAspect();
	/*
		fonction getVoice
		=> { pointeur sur voice de la forme }
	*/
	VOICE* getVoice();

	/*
		procedure setName
		{ attribue le nom de la forme }
	*/
	void setName(STR name);
	/*
		procedure setTense
		{ attribue le tense de la forme }
	*/
	void setTense(TENSE tense);
	/*
		procedure setMood
		{ attribue le mood de la forme }
	*/
	void setMood(MOOD mood);
	/*
		procedure setAspect
		{ attribue l'aspect de la forme }
	*/
	void setAspect(ASPECT aspect);
	/*
		fonction getVoice
		{ attribue le voice de la forme }
	*/
	void setVoice(VOICE voice);
private:
	STR name;
	TENSE tense;
	MOOD mood;
	ASPECT aspect;
	VOICE voice;
};
/*
	classe DBWORD :
	spécifie le contenu d'un mot stocké dans la BDD
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
		fonction getName
		=> {le pointeur sur name}
	*/
	STR* getName();
	/*
		fonction getDef
		=> {le pointeur sur def}
	*/
	STR* getDef();
	/*
		fonction getType
		=> {le pointeur sur type}
	*/
	TYPE* getType();
	/*
		procedure setName
		{affecte la valeur de name à self.name}
	*/
	void setName(STR name);
	/*
		procedure setDef
		{affecte la valeur de def à self.def}
	*/
	void setDef(STR def);
	/*
		procedure setType
		{affecte la valeur de type à self.type}
	*/
	void setType(TYPE type);

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
		fonction getFormCount
		=> {nombre de formes}
	*/
	UINT getFormCount() const;
	/*
		fonction getForm
		=> {le pointeur sur la forme à la position i}
	*/
	Form* getForm(UINT i);
	/*
		procedure setIrregular
		{affecte la valeur de irregular à self.irregular}
	*/
	void setIrregular(bool irregular);
	/*
		fonction AddForm
		{ajoute une forme à la liste des formes du verbe}
		=> {
			S_OK si l'opération c'est bien déroulée
			E_FAIL si la forme existe dejà dans la liste
		}
	*/
	HRESULT AddForm(Form form);
	/*
		fonction RemoveForm
		{trouve et enleve une forme de la liste des formes du verbe}
		=> {
			S_OK si l'opération c'est bien déroulée
			E_FAIL si la forme n'a pas été trouvée
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
	/*
		procedure write
		{ecrit dans le fichier un élement de type STR}
	*/
	void write(STR* str);
	/*
		procedure write
		{ecrit dans le fichier un élement de type Form}
	*/
	void write(Form* form);

	/*
		procedure write
		{ecrit dans le fichier un élement de type STR}
	*/
	void read(STR* str);
	/*
		procedure write
		{ecrit dans le fichier un élement de type Form}
	*/
	void read(Form* form);

private:
	MapWord* map[8]; //maps des offsets pour la BDD classées par type dans l'ordre de l'enuméré TYPE
	std::fstream file;
	

};

/*
	classe RechercheInfo
	Permet de rechercher les informations d'un mot a partir d'un dictionnaire en ligne
*/

class RechercheInfo
{
public:
	/*
		constructeur de RechercheInfo
		{initialise les variables}
	*/
	RechercheInfo(STR mot);

	/*
		destructeur de RechercheInfo
		{nettoie la mémoire}
	*/
	~RechercheInfo();

	/*
		fonction rechercheEtAjout
		=> {
			S_OK si le mot a été trouvé, et ajouté à la Database 
			E_OUTOFMEMORY si problème de mémoire,
			E_FAIL sinon 
			}
	*/
	HRESULT rechercheEtAjout();
private:
	/*
		fonction http_get
		{Envoie une requete HTTP de type GET à l'url donnée sur la page donnée}
		=> {
				retourne la réponse du serveur
		   }
	*/
	char * http_get(char * url_path, char * url_server);

	/*
		fonction strrch
		{Cherche une chaine dans une autre chaine}
		=> {
				retourne la position de la chaine recherchée ou -1 si la chaine n'est pas trouvée
		   }
	*/
	int strrch (char * string, char * recherche);

	/*
		fonction taille_corps
		{Calcule la taille du corps d'une réponse HTTP}
		=> {
				retourne la taille du corps de la réponse HTTP
		   }
	*/
	int taille_corps(char *requete);

	char * mot;

	DBWORD word;
	DBVERB verb;

	char * urlPath;
	char * urlServer;
	char * debutParseType;
	char * finParseType;
	char * debutParseDef;
	char * finParseDef;
	//...
};
