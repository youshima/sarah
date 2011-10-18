#include "StdAfx.h"
#include "SentenceParser.h"

Element::Element(string str)
{
	length = str.length();
	c = new char[length + 1];
	strcpy_s(c,sizeof(char) * length,str.c_str());
	c[length] = '\0';
}

Element::Element(char str)
{
	length = 1;
	c = new char[length + 1];
	c[0] = str;
	c[length] = '\0';
}

Element::~Element()
{
	delete[] c;
}
DWORD Element::getLength() {
	return length;
}

char* Element::getData() {
	return c;
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
SentenceParser::SentenceParser() : str("")
{
	elements.clear();
}

SentenceParser::~SentenceParser(void)
{
	str.empty();
}
vector<Element*>* SentenceParser::Analyse(System::String ^ str) {

	//passer le string managé en non managé
	cursor = 0;
	this->str.clear(); //effacer le contenu actuel de la chaine
	for(UINT i = 0; i < elements.size(); i++) //effacer les mots de l'analyse précédente
		elements.at(i)->~Element(); 
	elements.clear();

	for(UINT i = 0; i < (UINT)str->Length; i++) //boucle simple de copie
		this->str += str[i];
	while(readElement() != 0); //lecture de la phrase mot par mot et assemblage du vecteur de mots
	

	return &elements;
	
}
UINT SentenceParser::readElement() {
	UINT i = 0;
	string element = "";
	if(str.length() == 0 || cursor >= str.length()) //si la chaine est vide ou bien on a atteint la fin, retourner ""
		return 0;

	while(!isSeparator(str[cursor]))
	{
		element += str[cursor];
		cursor++;
		i++;
	}
	if(element.size() > 0)
	{
		Word* word = new Word(element);
		elements.push_back((Element*)word);
	}
	if(cursor < str.length()) //si on a fini de lire, inutile de continuer
	{
		//ajouter le separateur à la liste d'elements
		Separator* separator = new Separator(str[cursor]);
		if(strcmp(separator->getData()," ") != 0 || strcmp(separator->getData(),"\r") != 0 || strcmp(separator->getData(),"\n") != 0)
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

