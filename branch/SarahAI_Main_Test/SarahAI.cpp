#include "StdAfx.h"
#include "SarahAI.h"
#include <stdio.h>

//================================PUBLIC=======================================================

/*========
	Constructeur
==========*/
SarahAI::SarahAI(void)
{
	this->tree = new WordTree;
	this->tree->word = "grand-messes";
	this->tree->left = NULL;
	this->tree->right = NULL;
	ifstream file("../liste.de.mots.francais.frgut.txt", ios::in); //mot au milieu de la liste, pour l'efficacité de la dichotomie.
	string word;
	if (file)
	{
		int i=0;
		string load = "Loading word database. [                    ] ";
		while (getline(file,word))
		{
			this->addWord(this->tree,word);
			i++;
			if (!(i%16826))
			{
				load[23+(i/16826)] = '=';
				printf("%s",load);
				printf("\r");					//Barre de chargement \o/
				fflush(stdout);
			}
			if (i==1)
			{
				printf("%s",load);
				printf("\r");
				fflush(stdout);
			}
			cout << endl;
		}
		file.close();
		cout << "Done loading " << i << " words." << endl;
	}
	else
	{
		cout << "Je ne trouve pas mon dictionnaire, je ne peux pas vous aider." << endl;
		Sleep(5000);
		exit;

	}
}


/*========
	Destructeur
==========*/
SarahAI::~SarahAI(void)
{
}


/*========
	Think
	Fonction principale
	Prend une phrase complète en entrée, sur une ligne
	Rend une réponse.
==========*/

string SarahAI::think(string sentence)
{
	if (iKnow(this->tree,sentence))
		cout << "Je connais le mot " << sentence << " !" << endl;
	return sentence;
}

//============================PRIVATE===================================

/*========
	AddWord
	Ajoute un mot dans l'arbre de mots
==========*/

void SarahAI::addWord(WordTree*& root, string word)
{
	if (!root)
		addLeaf(root,word);
	else if (root->word < word)
		addWord(root->right,word);
	else
		addWord(root->left,word);
		
}

void SarahAI::addLeaf(WordTree*& leaf, string word)
{
	leaf = new WordTree;
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->word = word;
	leaf->type = 0; //TODO : find how to add type
}

/*=================
	bool iKnow(word)
	retourne vrai si le mot est dans l'arbre
=================*/

bool SarahAI::iKnow(WordTree* tree,string word)
{
	if (tree)
	{
		if (tree->word == word)
			return true;
		else if (word < tree->word)
			return iKnow(tree->left, word);
		else
			return iKnow(tree->right, word);
	}
	else
		return false;
}