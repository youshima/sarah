/*
  _______                   .__     
 /   _____/____ ____________  |  |__  
 \_____  \\__  \\_  __ \__  \ |  |  \ 
 /        \/ __ \|  | \// __ \|   Y  \
/_______  (____  /__|  (____  /___|  /
        \/     \/           \/     \/ 

Ceci est la classe qui définit toutes les fonctionnalités de 
l'Intelligence Artificielle de Sarah.

Par : André-Poyaud Tom
	  Espie-Caullet Jonathan

Créé le : 9/29/2011
*/

#pragma once
#include <string>
#include <Windows.h>
#include <iostream>
using namespace std;
#include <fstream>

#define uint unsigned int

enum WordType
{
	UNKNOWN		= 0,
	NOM			= 1,
	VERBE		= 2,
	ADJECTIF	= 3,	//TODO : complete that list, and find how to assign a type value to each word
	DETERMINANT	= 4,
	ADVERBE		= 5
};

struct WordTree 
{
	string word;
	uint type;
	WordTree* left;
	WordTree* right;
};

class SarahAI
{
public:
	SarahAI(void);
	~SarahAI(void);
	string think(string sentence);
	void dumpTree();
	void dumpTree(WordTree* tree);

protected:
private:
	WordTree* tree;
	void addWord(WordTree*& root,string word);
	void addLeaf(WordTree*& leaf,string word);
	bool iKnow(WordTree* tree,string word);
};

