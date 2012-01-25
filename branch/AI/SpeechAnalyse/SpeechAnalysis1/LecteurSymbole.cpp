#include "StdAfx.h"
#include "LecteurSymbole.h"


LecteurSymbole::LecteurSymbole(std::string str) : str(str),cursor(0)
{
	suivant();
}
void LecteurSymbole::suivant() {
	if(cursor >= str.size() || str[cursor] == '\0')
			symbole = Symbole("\0");
	else
	{
		std::string tempstr = "";
		while(tempstr == "")
		{
			if(str[cursor] == '(' || str[cursor] == ')' || str[cursor] == ',' || str[cursor] == ';')
			{
				tempstr += str[cursor];
				cursor++;
			}
			else if( str[cursor] == '[' )
			{
				tempstr += str[cursor];
				cursor++;
				while(cursor < str.size() && str[cursor] != ']')
				{
					tempstr += str[cursor];
					cursor++;
				}
				tempstr += "]";
		
			}
			else if( str[cursor] == '"' )
			{
				tempstr += str[cursor];
				cursor++;
				while(cursor < str.size() && str[cursor] != '"')
				{
					tempstr += str[cursor];
					cursor++;
				}
				tempstr += "\"";
				cursor++;
			}
			else
			while(cursor < str.size() && str[cursor] != ' ' && str[cursor] != ',' && str[cursor] != ';' && str[cursor] != '\n' && str[cursor] != '(' && str[cursor] != ')' && str[cursor] != '"')
			{
				tempstr += str[cursor];
				cursor++;
			}

			if(cursor == str.size() || str[cursor] == '\0')
				symbole = Symbole("\0");
			symbole = Symbole(tempstr);

			cursor++;
		}

		
	}
}
