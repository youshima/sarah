#ifndef WORDNET_H
#define WORDNET_H

#define HRESULT long
/*

Utilitaire pour la gestion de la DB mysql WordNet

*/
#include "Database.h"
#include <mysql.h> //librairie pour la gestion de MySQL
using namespace std;

//liste de DBWORDs
class DBWORDLIST
{
private:
	DBWORD word;
	DBWORDLIST* next;
public:
	DBWORDLIST(DBWORD word);
	inline DBWORD getWord() { return this->word; }
	inline DBWORDLIST* getNext() { return this->next; }
	void setNext(DBWORD word);
	inline void setValue(DBWORD word) { this->word = word; } 

};
//
class WordNet
{
private:
	MYSQL *connection, mysql;
	MYSQL_RES *result;
	MYSQL_ROW row;
	int query_state;
	HRESULT runQuery(char* query); //fonction utilisée dans toutes les fonctions find
								//pour executer les requêtes dans la DB
public:
	WordNet(); //constructeur qui initialise la connection à la DB
	~WordNet(); //destructeur, qui ferme la connection à la DB
	HRESULT WordNet::find(DBWORDLIST* wordlist, char* name, int numberOfOccurences);
	//{} => { word = pointeur sur une liste de DBWORD correspondant à name, et numberOfOccurences = nombre de DBWORD dans la liste}
	TYPE WordNet::getType(char* word);
};



#endif //WORDNET_H