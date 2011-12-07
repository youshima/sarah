/*
Implémentation de la classe WordNet
*/
#include "StdAfx.h"
#include "WordNet.h"


DBWORDLIST::DBWORDLIST(DBWORD word)
{
	this->word = word;
	this->next = NULL;
}

void DBWORDLIST::setNext(DBWORD word)
{
	if (this->next)
		this->next->setValue(word);
	else
		this->next = new DBWORDLIST(word);
}

WordNet::WordNet()
{
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql,"address","login","password","wn_pro_mysql",0,0,0);
	if (connection == NULL) 
	{
		cout << mysql_error(&mysql) << endl;
		exit(-1);							//Remplacer par une exception ?
	}

}

WordNet::~WordNet()
{
	mysql_free_result(result);
	mysql_close(connection);
}

HRESULT WordNet::runQuery(char* query)
{
	query_state = mysql_query(connection, query);
	if (query_state !=0) 
	{
		cout << mysql_error(connection) << endl;
		return -1;  //exception ?
	}
	return 0;

}

TYPE WordNet::getType(char* word)
{
	string query = "SELECT ss_type FROM wn_synset WHERE word = '";
	query.append(word);
	query.append("' ;");
	runQuery((char*)query.c_str());
	result = mysql_store_result(connection);
	row = mysql_fetch_row(result);

	return NOUN;
}


HRESULT WordNet::find(DBWORDLIST* wordlist, char* name, int numberOfOccurences)
{
	wordlist = NULL;
	DBWORD word;
	string query = "SELECT * FROM wn_synset WHERE word = '";
	query.append(name);
	query.append("' ;");
	runQuery((char*)query.c_str());
	result = mysql_store_result(connection);
	while (row = mysql_fetch_row(result))
	{
		/*word.setName();
		word.setDef();
		word.setType();
		wordlist->addWord(word);*/
		cout << row << endl;
	}
	

	return 0;
}



/*
result = mysql_store_result(connection);
while ( ( row = mysql_fetch_row(result)) != NULL ) {
cout << row[0] << endl;
}
*/