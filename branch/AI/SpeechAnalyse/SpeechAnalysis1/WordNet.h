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
	void addWord(DBWORD word);
	inline void setValue(DBWORD word) { this->word = word; } 

};
//
class WordNet
{
private:
	MYSQL *connection, mysql;
	MYSQL_RES *result;
	MYSQL_RES* result2;
	MYSQL_ROW row;
	MYSQL_ROW row2;
	int query_state;
	TYPE type_of(char type);
	HRESULT runQuery(char* query); //fonction utilis�e dans toutes les fonctions find
								//pour executer les requ�tes dans la DB
public:
	WordNet(); //constructeur qui initialise la connection � la DB
	~WordNet(); //destructeur, qui ferme la connection � la DB
	HRESULT find(DBWORDLIST* wordlist, char* name, int numberOfOccurences);
	//{} => { word = pointeur sur une liste de DBWORD correspondant � name, et numberOfOccurences = nombre de DBWORD dans la liste}
};



#endif //WORDNET_H