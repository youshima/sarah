#include "StdAfx.h"
#include "SentenceParser.h"

Element::Element(string str)
{
	this->str = str.c_str();
}

Element::Element(char str)
{
	this->str = &str;
}

Element::~Element()
{
	this->str.~STR();
}
const UINT* Element::getLength() {
	return this->str.getLength();
}

STR* Element::getString() {
	return &str;
}
void Element::setString(STR str) {
	this->str = str;
}
Word::Word(std::string str) : Element(str)
{
	
}
Word::~Word()
{
	Element::~Element();
}
bool Word::isSeparator()
{
	return false;
}
Separator::Separator(char str) : Element(str)
{

}
Separator::~Separator()
{
	Element::~Element();
}
bool Separator::isSeparator()
{
	return true;
}
SentenceParser::SentenceParser()
{
	str = "";
	elements.clear();
}

SentenceParser::~SentenceParser(void)
{
	str.~STR();
}
vector<Element*>* SentenceParser::Analyse(System::String ^ str) {

	//passer le string managé en non managé
	cursor = 0;
	this->str.empty(); //effacer le contenu actuel de la chaine
	for(UINT i = 0; i < elements.size(); i++) //effacer les mots de l'analyse précédente
		elements.at(i)->~Element(); 
	elements.clear();
	
	std::string fastStr = "";
	for(UINT i = 0; i < (UINT)str->Length; i++) //boucle simple de copie
		fastStr += str[i];
	this->str = fastStr.c_str();

	fastStr.empty();

	while(readElement() != 0); //lecture de la phrase mot par mot et assemblage du vecteur de mots
	

	return &elements;
	
}
UINT SentenceParser::readElement() {
	UINT i = 0;
	string element = "";
	if(*this->str.getLength() == 0 || cursor >= *this->str.getLength()) //si la chaine est vide ou bien on a atteint la fin, retourner ""
		return 0;

	while(!isSeparator(*str[cursor]))
	{
		element += *str[cursor];
		cursor++;
		i++;
	}
	if(element.size() > 0)
	{
		Word* word = new Word(element);
		elements.push_back((Element*)word);
	}
	if(cursor < *this->str.getLength()) //si on a fini de lire, inutile de continuer
	{
		//ajouter le separateur à la liste d'elements
		Separator* separator = new Separator(*str[cursor]);
		if(*separator->getString() != " " && *separator->getString() != "\r" && *separator->getString() != "\n" )
			elements.push_back((Element*)separator);
		//sauter le separateur
		cursor++;
		i++;
	}
	return i;
}

bool SentenceParser::isAlpha(char c) {
	return ( ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') );
}
bool SentenceParser::isNumeric(char c) {
	return ( ('1' <= c && c <= '9') );
}
bool SentenceParser::isSeparator(char c) {
	return (!isAlpha(c) && !isNumeric(c));
}

