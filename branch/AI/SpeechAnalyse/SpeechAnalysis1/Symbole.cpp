#include "StdAfx.h"
#include "Symbole.h"

Symbole::Symbole(std::string chaine) : chaine(chaine)
{
	if(chaine.size() == 0)
		type = FIN;
	else
	{
		if(chaine[0] == '$')
		{
			type = VARIABLE;
			this->chaine = chaine.substr(1, chaine.size());
		}
		else if(chaine[0] == '[')
		{
			type = SENTENCE;
		}
		else if( atoi(&chaine[0]) > 0 && atoi(&chaine[0]) < 9 ) //alpha
			type = VALEUR;
		else if( chaine[0] == '"' ) //chaine
		{
			type = CHAINE;
			this->chaine = chaine.substr(1, chaine.size()-2); //retirer les ""
		}
		else if( chaine == "+" || chaine == "=" || chaine == "!" || chaine == "&" || chaine == "|" || chaine == "==" || chaine == "!=") 
			type = OPERATION;
		else if( chaine == ";" || chaine == "then" ) 
			type = FIN_INST;
		else if( chaine == "" || chaine == "endif" || chaine == "else") 
			type = FIN;
		else
			type = INCONNU;
	}

}
Symbole::~Symbole()
{

}
