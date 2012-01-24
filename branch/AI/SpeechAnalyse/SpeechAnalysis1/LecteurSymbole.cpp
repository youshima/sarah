#include "StdAfx.h"
#include "LecteurSymbole.h"


LecteurSymbole::LecteurSymbole(std::string str) : str(str),cursor(0)
{
}
void LecteurSymbole::suivant() {
	std::string tempstr = "";
	while(cursor < str.size() && str[cursor] != ' ' && str[cursor] != ';')
	{
		tempstr += str[cursor];
		cursor++;
	}

	symbole = Symbole(tempstr);

	cursor++;

}
