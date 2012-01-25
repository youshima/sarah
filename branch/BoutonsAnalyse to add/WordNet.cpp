/*
Implémentation de la classe WordNet
*/
#include "StdAfx.h"
#include "WordNet.h"


DBWORDLIST::DBWORDLIST(DBWORD* word)
{
	this->word = word;
	this->next = NULL;
}

void DBWORDLIST::setNext(DBWORD* word)
{
	if (this->next)
		this->next->setValue(word);
	else
		this->next = new DBWORDLIST(word);
}

void DBWORDLIST::addWord(DBWORD* word)
{
	DBWORDLIST* tmp = this;
	do
		tmp=tmp->getNext();
	while(tmp);
	tmp = new DBWORDLIST(word);

}

WordNet::WordNet()
{
	mysql_init(&mysql);
	connection = mysql_real_connect(&mysql,"pg.no-ip.biz","wordnet","wordnet","wn_pro_mysql",3306,0,0);
	if (connection == NULL) 
	{
		cout << mysql_error(&mysql) << endl;
		exit(-5545);							//Remplacer par une exception ?
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

TYPE WordNet::type_of(char type)
{
	//VERB, NOUN, ADJECTIVE, ADVERB, PRONOUN, PREPOSITION, FORMUNCTION, INTERJECTION, TYPE_NONE
	switch(type)
	{
	case 'n':
		return NOUN;
		break;
	case 'v':
		return VERB;
		break;
	case 'a':
	case 's':
		return ADJECTIVE;
		break;
	case 'r':
		return ADVERB;
		break;
	default:
		return TYPE_NONE;
	}
}

HRESULT WordNet::find(DBWORDLIST* wordlist, char* name, int numberOfOccurences)
{
	wordlist = NULL;
	numberOfOccurences = 0;
	DBWORD* word;
	string query = "SELECT * FROM wn_synset WHERE word = '";
	query.append(name);
	query.append("' ;");
	runQuery((char*)query.c_str());
	result = mysql_store_result(connection);
	while (row = mysql_fetch_row(result))
	{
		if (type_of((char)row[3][0])!='v')
		{
			word = new DBWORD;
			word->setName(((std::string)row[2]));
			word->setType(type_of((char)row[3][0]));
			string query = "SELECT * FROM wn_gloss WHERE synset_id = '";
			query.append(row[0]);
			query.append("' ;");
		
			runQuery((char*)query.c_str());
			result2 = mysql_store_result(connection);
			row2 = mysql_fetch_row(result2);
			word->setDef((std::string )row2[1]);
		}
		else //c'est un verbe
		{
			word = new DBVERB;
			word->setName((std::string &)row[2]);
			word->setType(VERB);
			string query = "SELECT * FROM wn_gloss WHERE synset_id = '";
			query.append(row[0]);
			query.append("' ;");
		
			runQuery((char*)query.c_str());
			result2 = mysql_store_result(connection);
			row2 = mysql_fetch_row(result2);
			word->setDef((std::string &)row2[1]);

		}
		if (!wordlist)
			wordlist = new DBWORDLIST(word);
		else
			wordlist->addWord(word);

		numberOfOccurences++;
	}
	

	return 0;
}

HRESULT WordNet::findSynonims(DBWORDLIST* wordlist, DBWORD wordQuery, int numberOfSynonims)
{
	wordlist = NULL;
	numberOfSynonims = 0;
	DBWORD* word;
	string query = "SELECT synset_id FROM wn_gloss WHERE gloss = '";
	query.append((char*)wordQuery.getDef());
	query.append("' ;");
	runQuery((char*)query.c_str());
	result = mysql_store_result(connection);
	while (row = mysql_fetch_row(result))
	{
		query = "SELECT * FROM wn_synset WHERE synset_id IN (SELECT synset_id_1 FROM wn_see_also WHERE synset_id_2 ='";
		query.append((char*)row[0]);
		query.append("') OR synset_id IN (SELECT synset_id_2 FROM wn_see_also WHERE synset_id_1='");
		query.append((char*)row[0]);
		query.append("' ;");
		runQuery((char*)query.c_str());
		result2 = mysql_store_result(connection);
		while (row2 = mysql_fetch_row(result2))
		{
			if (type_of((char)row[3][0])!='v')
			{
				word = new DBWORD;
				word->setName((std::string &)row[2]);
				word->setType(type_of((char)row[3][0]));
				string query = "SELECT * FROM wn_gloss WHERE synset_id = '";
				query.append(row2[0]);
				query.append("' ;");
		
				runQuery((char*)query.c_str());
				result3 = mysql_store_result(connection);
				row3 = mysql_fetch_row(result3);
				word->setDef((std::string &)row3[1]);
			}
			else //c'est un verbe
			{
				word = new DBVERB;
				word->setName((std::string &)row[3]);
				word->setType(VERB);
				string query = "SELECT * FROM wn_gloss WHERE synset_id = '";
				query.append(row2[0]);
				query.append("' ;");
		
				runQuery((char*)query.c_str());
				result3 = mysql_store_result(connection);
				row3 = mysql_fetch_row(result3);
				word->setDef((std::string &)row3[1]);

			}
			if (!wordlist)
				wordlist = new DBWORDLIST(word);
			else
				wordlist->addWord(word);
		}
			
		numberOfSynonims++;
	}
	

	return 0;
}

/*
result = mysql_store_result(connection);
while ( ( row = mysql_fetch_row(result)) != NULL ) {
cout << row[0] << endl;
}
*/