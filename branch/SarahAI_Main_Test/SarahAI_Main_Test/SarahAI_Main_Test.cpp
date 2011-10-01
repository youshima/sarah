/*
  _______                   .__     
 /   _____/____ ____________  |  |__  
 \_____  \\__  \\_  __ \__  \ |  |  \ 
 /        \/ __ \|  | \// __ \|   Y  \
/_______  (____  /__|  (____  /___|  /
        \/     \/           \/     \/ 

Ceci est le programme permettant de tester l'Intelligence
Artificielle de Sarah en console.

Par : André-Poyaud Tom
	  Espie-Caullet Jonathan

Créé le : 9/29/2011
*/

#include "stdafx.h"
#include <Windows.h>
#include "SarahAI.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string sentence;
	SarahAI* sarah = new SarahAI;
	getline(cin,sentence);
	while (sentence != ".")
	{
		cout << sarah->think(sentence) << endl;
		getline(cin,sentence);
	}
		cout << "Au revoir !" <<endl;
		Sleep(1000);
	return 0;
}

