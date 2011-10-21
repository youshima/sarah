#include "StdAfx.h"
#include "Environment.h"
/*

	CLASS ENVIRONMENT
*/
Environment::Environment() {
	bool existed;
	file.open(FILENAME, existed); //ouvrir le fichier

		/*if(!file->eof()) //tester si le fichier est vide
		{
		}*/
	file.close(); // fermer le fichier
}

Environment::~Environment() {
	Save();
	for(UINT i = 0; i < this->Vars.size() ; i++)
		Vars[i].~VAR();

	file.~File();
}

HRESULT Environment::Save() {
	bool exists;
	file.open(FILENAME, exists); //ouvrir le fichier
	if(!file.isOpen())
		return E_FILENOTFOUND;
	
	file.empty(); //vider le fichier
	int val = getVarCount();
	file.write(val); //ecriture du nombre de variables à stocker
	for(UINT i = 0; i < (UINT)val; i++)
		file.write(Vars[i]);
	val = getRulesCount();
	file.write(val); //ecriture du nombre de regles à stocker
	for(UINT i = 0; i < (UINT)val; i++)
		file.write(Rules[i]);
	file.close();
	return S_OK;
}

HRESULT Environment::AddVar(VAR& var) {
	if(getVar(*var.getName())) // si la variable existe
		Vars.push_back(var);
	else
		return E_FAIL;

	return S_OK;
}

HRESULT Environment::RemoveVar(STR& name) {
	int index = FindVarIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return RemoveVar(i);
	}
	else
		return E_FAIL;
}

HRESULT Environment::RemoveVar(UINT& index) {
	if(index < getVarCount())
	{
		Vars[index].~VAR();
		Vars.erase(Vars.begin() + index);
		return S_OK;
	}
	else
		return E_FAIL;
}

int Environment::FindVarIndex(STR& name) {
	UINT i = 0;

	while( i < getVarCount() && *Vars[i].getName() != name);

	if(i == getVarCount())
		return -1;
	else
		return i;

}

VAR* Environment::getVar(UINT& index) {
	if(index < getVarCount())
	{
		return &Vars[index];
	}
	else
		return 0;
}

VAR* Environment::getVar(STR& name) {
	int index = FindVarIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return getVar(i);
	}
	else
		return 0;
}

HRESULT Environment::setVar(STR& name, Value& value) {
	int index = FindVarIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return setVar(i,value);
	}
	else
		return E_FAIL;
}

HRESULT Environment::setVar(UINT& index, Value& value) {
	if(index < getVarCount())
	{
		Vars[index].setValue(value);
		return S_OK;
	}
	else
		return E_FAIL;
}
/**************************************************/
HRESULT Environment::AddRule(Rule& rule) {
	if(getRule(*rule.getName())) // si la ruleiable existe
		Rules.push_back(rule);
	else
		return E_FAIL;

	return S_OK;
}

HRESULT Environment::RemoveRule(STR& name) {
	int index = FindRuleIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return RemoveRule(i);
	}
	else
		return E_FAIL;
}

HRESULT Environment::RemoveRule(UINT& index) {
	if(index < getRulesCount())
	{
		Rules[index].~Rule();
		Rules.erase(Rules.begin() + index);
		return S_OK;
	}
	else
		return E_FAIL;
}

int Environment::FindRuleIndex(STR& name) {
	UINT i = 0;

	while( i < getRulesCount() && *Rules[i].getName() != name);

	if(i == getRulesCount())
		return -1;
	else
		return i;

}

Rule* Environment::getRule(UINT& index) {
	if(index < getRulesCount())
	{
		return &Rules[index];
	}
	else
		return 0;
}

Rule* Environment::getRule(STR& name) {
	int index = FindRuleIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return getRule(i);
	}
	else
		return 0;
}

HRESULT Environment::setRule(STR& name, STR& script, STR& about, bool active) {
	int index = FindRuleIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return setRule(i,script,about,active);
	}
	else
		return E_FAIL;
}

HRESULT Environment::setRule(UINT& index, STR& script, STR& about, bool active) {
	if(index < getRulesCount())
	{
		Rules[index].setScript(script);
		Rules[index].setAbout(about);
		Rules[index].setEnabled(active);
		return S_OK;
	}
	else
		return E_FAIL;
}
UINT Environment::getVarCount() {
	return this->Vars.size();
}
UINT Environment::getRulesCount() {
	return this->Rules.size();
}