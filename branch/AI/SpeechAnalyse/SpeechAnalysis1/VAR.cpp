#include "StdAfx.h"
#include "VAR.h"
#include "StdAfx.h"
#include "Environment.h"

/*
	CLASS VALUE
*/
Value::Value(VAR_TYPE type) {
	setType(type);
}

/*Value::Value(int val) : buffer(0) {
	*this = val;
}
Value::Value(float val) : buffer(0) {
	*this = val;
}
Value::Value(bool val) : buffer(0) {
	*this = val;
}
Value::Value(std::string val) : buffer(0) {
	*this = val;
}
Value::Value(char val) : buffer(0) {
	*this = val;
}
Value::Value(HRESULT val) : buffer(0) {
	*this = val;
}*/
Value::~Value() {
	//if(getType() != STRING && getType() != SENTENCE)
	//free((void*)buffer);
}

VAR_TYPE Value::getType() {
	return this->type;
}

void Value::setType(VAR_TYPE type)
{
	this->type = type;
	/*if(buffer != 0)
		free((void*)buffer);
	switch(this->type)
	{
		case INTEGER :
			buffer = (char*)malloc(sizeof(int));
			break;
		case REAL :
			buffer = (char*)malloc(sizeof(float));
			break;
		case STRING :
			buffer = 0;
			break;
		case SENTENCE :
			buffer = 0;
			break;
		case VARCHAR :
			buffer = (char*)malloc(sizeof(char));
			break;
		case VARBOOL :
			buffer = (char*)malloc(sizeof(bool));
			break;
		case VARRESULT :
			buffer = (char*)malloc(sizeof(HRESULT));
			break;
		default :
			buffer = 0;
			break;
	}*/
}

char* Value::getValue() {
	return this->buffer;
}

void Value::setValue(char* value) {
	switch(this->type)
	{
		case INTEGER :
			memcpy((void*)buffer,value,sizeof(int));
			break;
		case REAL :
			memcpy((void*)buffer,value,sizeof(float));
			break;
		case STRING :
			//free((char*)buffer);
			//buffer = (char*)malloc(sizeof(char) *  ( strlen(value) +1 ));
			strcpy(buffer,value);
			//memcpy((void*)buffer,value,strlen(value));
			//buffer[strlen(value)] = '\0'; //ajouter le end string
			break;
		case SENTENCE:
			//free((char*)buffer);
			//buffer = (char*)malloc(sizeof(char) *  ( strlen(value) +1 ));
			strcpy(buffer,value);
			//memcpy((void*)buffer,value,strlen(value));
			//buffer[strlen(value)] = '\0'; //ajouter le end string
			break;
		case VARCHAR :
			memcpy((void*)buffer,value,sizeof(char));
			break;
		case VARBOOL :
			memcpy((void*)buffer,value,sizeof(bool));
			break;
		case VARRESULT :
			memcpy((void*)buffer,value,sizeof(HRESULT));
			break;
	}
}
bool Value::operator ==(Value value) {

	switch(this->type)
	{
		case INTEGER :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(int)) == 0 );
			break;
		case REAL :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(float)) == 0 );
			break;
		case STRING :
			if(value.getType() == SENTENCE)
				{
					std::string str2 = (char*)this->getValue();
					std::string str1 = (char*)value.getValue();
					LecteurSymbole* ls1 = new LecteurSymbole(str1.substr(1,str1.size()));
					LecteurSymbole* ls2 = new LecteurSymbole(str2);
					//vrai = %
					//faux = *
					int minimalSkips;
					int maximalSkips;
					Symbole goal;
					while( ls1->getSymCour().getChaine() != "]" ) //on s'arrete au crochet final
					{
						minimalSkips = 0;
						maximalSkips = 0;
						std::string str = ls1->getSymCour().getChaine();
						while(ls1->getSymCour().getType() != Symbole::FIN && ls1->getSymCour().getType() != Symbole::CHAINE)
						{
							switch(str[0])
							{
							case '%':
								maximalSkips = 20;
								break;
							case '*':
								minimalSkips++;
								break;
							case ' ': //ignorer
								break; 
							case ',': //ignorer
								break;
							default : 
								
								break;
							}
							
							ls1->suivant();
						}
						
							goal = ls1->getSymCour();
						//	if(ls1->getSymCour().getType() != Symbole::FIN)
						//goal = Symbole(goal.getChaine().substr(1,goal.getChaine().size()2) );
						//on a reperé le prochain but à atteindre
						int skips = 0;
						while(ls2->getSymCour().getType() != Symbole::Type::FIN && ls2->getSymCour().getChaine() != goal.getChaine() ) //parcourir la phrase à comparer jusqu à trouver le but
						{
							skips++;
							ls2->suivant();
							
						}
						if( ls2->getSymCour().getType() == Symbole::Type::FIN && goal.getType() != Symbole::Type::FIN ) //but non atteint
							return false;
						//if(ls2->getSymCour().getType() == Symbole::Type::FIN)
						//	return false;
						//else
						{
							if( skips >= minimalSkips && skips <= maximalSkips ) //si on a sauté un nombre de mots correctement defini par la syntaxe
								ls2->suivant();
							else
								return false;	//pas bon, la phrase ne correspond pas
						}
						ls1->suivant(); //sauter le goal

						if(ls2->getSymCour().getType() == Symbole::Type::FIN && ls1->getSymCour().getType() == Symbole::Type::FIN)
							break;
					}

					return true; //l'ensemble de la phrase a été parcourue et tous les buts sont atteints
				}
			else
			return ( this->getType() == value.getType() && strcmp(this->getValue(),value.getValue()) == 0 );
			break;
		case SENTENCE :
			if( value.getType() != SENTENCE && value.getType() != STRING )
				return false;
			else
			{
				if(value.getType() == STRING)
				{
					std::string str1 = (char*)this->getValue();
					std::string str2 = (char*)value.getValue();
					LecteurSymbole* ls1 = new LecteurSymbole(str1.substr(1,str1.size()));
					LecteurSymbole* ls2 = new LecteurSymbole(str2);
					//vrai = %
					//faux = *
					int minimalSkips;
					int maximalSkips;
					Symbole goal;
					while( ls1->getSymCour().getChaine() != "]" ) //on s'arrete au crochet final
					{
						minimalSkips = 0;
						maximalSkips = 0;
						std::string str = ls1->getSymCour().getChaine();
						while(ls1->getSymCour().getType() != Symbole::FIN && ls1->getSymCour().getType() != Symbole::CHAINE)
						{
							switch(str[0])
							{
							case '%':
								maximalSkips = 20;
								break;
							case '*':
								minimalSkips++;
								break;
							case ' ': //ignorer
								break; 
							case ',': //ignorer
								break;
							default : 
								
								break;
							}
							
							ls1->suivant();
						}
						
							goal = ls1->getSymCour();
						//	if(ls1->getSymCour().getType() != Symbole::FIN)
						//goal = Symbole(goal.getChaine().substr(1,goal.getChaine().size()2) );
						//on a reperé le prochain but à atteindre
						int skips = 0;
						while(ls2->getSymCour().getType() != Symbole::Type::FIN && ls2->getSymCour().getChaine() != goal.getChaine() ) //parcourir la phrase à comparer jusqu à trouver le but
						{
							skips++;
							ls2->suivant();
							
						}
						if( ls2->getSymCour().getType() == Symbole::Type::FIN && goal.getType() != Symbole::Type::FIN ) //but non atteint
							return false;
						//if(ls2->getSymCour().getType() == Symbole::Type::FIN)
						//	return false;
						//else
						{
							if( skips >= minimalSkips && skips <= maximalSkips ) //si on a sauté un nombre de mots correctement defini par la syntaxe
								ls2->suivant();
							else
								return false;	//pas bon, la phrase ne correspond pas
						}
						ls1->suivant(); //sauter le goal

						if(ls2->getSymCour().getType() == Symbole::Type::FIN && ls1->getSymCour().getType() == Symbole::Type::FIN)
							break;
					}

					return true; //l'ensemble de la phrase a été parcourue et tous les buts sont atteints
				}
				return false;
			}
			break;
		case VARCHAR :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(char)) == 0 );
			break;
		case VARBOOL :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(bool)) == 0 );
			break;
		case VARRESULT :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(HRESULT)) == 0 );
			break;
		default :
			return false;
	}
	
}
bool Value::operator !=(Value value) {
	return !(*this == value);
}
void Value::operator =(int val) {
	setType(INTEGER);
	this->setValue((char*) &val);
}
void Value::operator =(float val) {
	setType(REAL);
	this->setValue((char*) &val);
}
void Value::operator =(bool val) {
	setType(VARBOOL);
	this->setValue((char*) &val);
}
void Value::operator =(std::string val) {
	if(val.size() > 0 && val[0] == '[')
		setType(SENTENCE);
	else
		setType(STRING);
	this->setValue((char*) val.c_str());
}
void Value::operator =(HRESULT val) {
	setType(VARRESULT);
	this->setValue((char*) &val);
}
void Value::operator =(char val) {
	setType(VARCHAR);
	this->setValue((char*) val);
}
void Value::operator =(Value val) {
	std::string str;
	if(buffer != 0)
	 str = val.getValue();
	else
	str = "";
	*this = str;
	setType(val.getType());

}

bool Value::operator ==(int val) {
	Value temp;
	temp = val; 
	return *this == temp;
}
bool Value::operator ==(float val) {
	Value temp;
	temp = val; 
	return *this == temp;
}
bool Value::operator ==(bool val) {
	Value temp;
	temp = val; 
	return *this == temp;
}
bool Value::operator ==(std::string val) {
	Value temp;
	temp = val; 
	return *this == temp;
}
bool Value::operator ==(HRESULT val) {
	Value temp;
	temp = val; 
	return *this == temp;
}
bool Value::operator ==(char val) {
	Value temp;
	temp = val; 
	return *this == temp;
}

bool Value::operator !=(int val) {
	return !(*this == val);
}
bool Value::operator !=(float val) {
	return !(*this == val);
}
bool Value::operator !=(bool val) {
	return !(*this == val);
}
bool Value::operator !=(std::string val) {
return !(*this == val);
}
bool Value::operator !=(HRESULT val) {
	return !(*this == val);
}
bool Value::operator !=(char val) {
	return !(*this == val);
}
/*
	CLASS VAR
*/
VAR::VAR(std::string name) : name(name) {
}

VAR::~VAR() {
}

std::string VAR::getName() {
	return this->name;
}

Value VAR::getValue() {
	return value;
}

void VAR::setName( std::string name ) {
	this->name = name;
}

void VAR::setValue( Value val ) {
	this->value.setType(val.getType());
	this->value.setValue(val.getValue());
}

void VAR::operator=( Value val ) {
	this->setValue(val);
}

bool VAR::operator==( VAR val ) {
	return ( this->getValue() == val.getValue());
}
bool VAR::operator!=( VAR val ) {
	return !( *this == val );
}
