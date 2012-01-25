#pragma once
#include "Helpers.h"
#include "STR.h"
#include "Form.h"
#include "File.h"

#include <iostream> //traitement de fichiers
#include <fstream>

#define LIST(x) std::vector<x>

#define FILENAME_DATA "database.data"

namespace AI
{

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
	UINT* getOffset();
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
	HRESULT Add(MapWord* mw, std::string name);
	/*
		fonction Find [recursive]
		=> { offset du mot recherché, 0 sinon, name en minuscules }
	*/
	UINT Find(std::string& name);
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
	DBWORD(std::string name = "");
	/*
		destructeur de DBWORD
		{nettoie la mémoire}
	*/
	~DBWORD();
	
	/*
		fonction getName
		=> {le pointeur sur name}
	*/
	std::string* getName();
	/*
		fonction getDef
		=> {le pointeur sur def}
	*/
	std::string* getDef();
	/*
		fonction getType
		=> {le pointeur sur type}
	*/
	TYPE* getType();
	/*
		procedure setName
		{affecte la valeur de name à self.name}
	*/
	void setName(std::string name);
	/*
		procedure setDef
		{affecte la valeur de def à self.def}
	*/
	void setDef(std::string def);
	/*
		procedure setType
		{affecte la valeur de type à self.type}
	*/
	void setType(TYPE type);

private:
	std::string name;
	std::string def;
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
	DBVERB(std::string name = "", bool irregular = false);
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
	Form* getForm(UINT& i);
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
	HRESULT AddForm(Form& form);
	/*
		fonction RemoveForm
		{trouve et enleve une forme de la liste des formes du verbe}
		=> {
			S_OK si l'opération c'est bien déroulée
			E_FAIL si la forme n'a pas été trouvée
		}
	*/
	HRESULT RemoveForm(Form& form);

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
	HRESULT AddWord(DBWORD& word);

	/*
		fonction Exist
		=> { Retourne vrai si le mot existe dans database, faux sinon }
	*/
	bool Exist(std::string& name);

	/*
		fonction Getword
		=> { Retourne les information du mot; le mot EST DANS la database, le fichier file EST OUVERT }
	*/
	DBWORD * Getword(std::string& name);
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
		fonction Find
		=> { offset du mot recherché, 0 sinon, name en minuscules }
	*/
	UINT Find(std::string& name);

private:
	MapWord* map[8]; //maps des offsets pour la BDD classées par type dans l'ordre de l'enuméré TYPE
	File file;
	

};


}