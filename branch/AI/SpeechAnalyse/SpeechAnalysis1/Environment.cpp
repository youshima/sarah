#include "StdAfx.h"
#include "Environment.h"
/*

	CLASS ENVIRONMENT
*/
AI::Environment::Environment() {
	Load(); //charger l'environnement à partir du fichier
}

AI::Environment::~Environment() {
	Save();
	for(UINT i = 0; i < getVarCount() ; i++)
		Vars[i].~VAR();
	for(UINT i = 0; i < getRulesCount() ; i++)
		Rules[i].~Rule();
}

HRESULT AI::Environment::Save() {
	bool exists;
	if(file.open(FILENAME_ENV, exists) != S_OK) //ouvrir le fichier
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

HRESULT AI::Environment::Load() {
	bool exists;
	file.open(FILENAME_ENV, exists); //ouvrir le fichier
	if(!exists)
		return E_FILENOTFOUND; //fichier non trouvé

	if(file.isOpen()) //tentative de chargement en mémoire de l'environnement
	{
		if(!file.isEmpty()) //tester si le fichier est vide
		{
			//fichier existant et avec données, les charger en mémoire
			file.toBegin();
			int val;
			file.read(val); //lecture du nombre de variables stockées

			VAR var;
			for(UINT i = 0; i < (UINT)val; i++) //lire toutes les variables
			{
				file.write(var);
				AddVar(var); //ajouter la variable à la liste
			}

			file.read(val); //lecture du nombre de regles stockées

			Rule rule;
			for(UINT i = 0; i < (UINT)val; i++) //lire toutes les regles
			{
				file.read(rule);
				AddRule(rule); //ajouter la regle à la liste
			}
			var.~VAR();
			rule.~Rule();
			
		}

		file.close();
		return S_OK;
	}
	else
		return E_FAIL;
}

HRESULT AI::Environment::AddVar(VAR& var) {
	int index = FindVarIndex(var.getName());
	if(index >= 0) //la variable existe dejà
		return E_FAIL;
	else
		Vars.push_back(var); //sinon l'ajouter

	return S_OK;
}

HRESULT AI::Environment::RemoveVar(std::string& name) {
	int index = FindVarIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return RemoveVar(i);
	}
	else
		return E_FAIL;
}

HRESULT AI::Environment::RemoveVar(UINT& index) {
	if(index < getVarCount())
	{
		Vars[index].~VAR();
		Vars.erase(Vars.begin() + index);
		return S_OK;
	}
	else
		return E_FAIL;
}

int AI::Environment::FindVarIndex(std::string& name) {
	UINT i = 0;
	UINT size = getVarCount();
	while( i < size && Vars[i].getName() != name) i++;

	if(i == size)
		return -1;
	else
		return i;

}

VAR* AI::Environment::getVar(UINT& index) {
	if(index < getVarCount())
	{
		return &Vars[index];
	}
	else
		return 0;
}

VAR* AI::Environment::getVar(std::string& name) {
	int index = FindVarIndex(name);
	if(index >= 0)
	{
		UINT i = index;
		return getVar(i);
	}
	else
		return 0;
}

HRESULT AI::Environment::setVar(std::string& name, Value& value) {
	int index = FindVarIndex(name);
	if(index >= 0)
	{
		UINT i = index;
		return setVar(i,value);
	}
	else
		return E_FAIL;
}

HRESULT AI::Environment::setVar(UINT& index, Value& value) {
	if(index < getVarCount())
	{
		Vars[index].setValue(value);
		return S_OK;
	}
	else
		return E_FAIL;
}
/**************************************************/
HRESULT AI::Environment::AddRule(Rule& rule) {
	if(getRule(rule.getName()) == 0) // si la rule n'existe pas dejà
		Rules.push_back(rule);
	else
	{
		Rule* mrule = getRule(rule.getName());
		mrule->setName(rule.getName());
		mrule->setAbout(rule.getAbout());
		mrule->setEnabled(rule.getEnabled());
		mrule->setScript(rule.getScript());

		return E_FAIL; //modification
	}

	return S_OK;
}

HRESULT AI::Environment::RemoveRule(std::string& name) {
	int index = FindRuleIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return RemoveRule(i);
	}
	else
		return E_FAIL;
}

HRESULT AI::Environment::RemoveRule(UINT& index) {
	if(index < getRulesCount())
	{
		Rules[index].~Rule();
		Rules.erase(Rules.begin() + index);
		return S_OK;
	}
	else
		return E_FAIL;
}

int AI::Environment::FindRuleIndex(std::string& name) {
	UINT i = 0;

	while( i < getRulesCount() && Rules[i].getName() != name) i++;

	if(i == getRulesCount())
		return -1;
	else
		return i;

}

Rule* AI::Environment::getRule(UINT index) {
	if(index < getRulesCount())
	{
		return &Rules[index];
	}
	else
		return 0;
}

Rule* AI::Environment::getRule(std::string& name) {
	int index = FindRuleIndex(name);
	if(index >= 0)
	{
		UINT i = index;
		return getRule(i);
	}
	else
		return 0;
}

HRESULT AI::Environment::setRule(std::string& name, std::string& script, std::string& about, bool active) {
	int index = FindRuleIndex(name);
	if(index > 0)
	{
		UINT i = index;
		return setRule(i,script,about,active);
	}
	else
		return E_FAIL;
}

HRESULT AI::Environment::setRule(UINT& index, std::string& script, std::string& about, bool active) {
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
UINT AI::Environment::getVarCount() {
	return this->Vars.size();
}
UINT AI::Environment::getRulesCount() {
	return this->Rules.size();
}
HRESULT AI::Environment::executer(Rule* rule) {
	Value hr;
	ls = new LecteurSymbole(rule->getScript());
	hr = seqInst();
	if( hr != E_FAIL )
		return S_OK;
	else
	return E_FAIL;
}
Value AI::Environment::seqInst() {
	Value hr;
	while(ls->getSymCour().getType() != Symbole::Type::FIN)
	{
		if(ls->getSymCour().getChaine() == "if")
					hr = instIf();
		else
		hr = Inst();
		if( hr == E_FAIL )
			return hr;
	}
	hr = S_OK;
	return hr;
}
Value AI::Environment::Inst() {
	Value hr;
	if(ls->getSymCour().getType() != Symbole::Type::FIN_INST || ls->getSymCour().getType() != Symbole::Type::FIN)
	{

		switch(ls->getSymCour().getType())
		{
			case Symbole::VARIABLE :
				 hr = Operation();
				break;
			case Symbole::SENTENCE :
				 hr = Operation();
				break;
			default:
				hr = E_FAIL;
		}
		if(hr == E_FAIL)
			return hr;
	}
	return hr;
}
Value AI::Environment::instIf() {

	Value hr;
	ls->suivant();
	Value val = Inst();
	bool tr = (val == true);
	if( tr )
	{
		ls->suivant(); //sauter le then
		if(ls->getSymCour().getChaine() != "else" && ls->getSymCour().getChaine() != "endif")
		{
			hr = seqInst();
			if(hr == E_FAIL)
				return hr;

			while(ls->getSymCour().getChaine() != "endif")
			ls->suivant(); //zapper le else s'il y en a un
		}
	}
	else
	{
		while(ls->getSymCour().getChaine() != "else" && ls->getSymCour().getChaine() != "endif")
			ls->suivant(); //zapper les instructions de la condition
	
	}

	if(ls->getSymCour().getChaine() == "else")
	{
			ls->suivant();
			hr = seqInst();
			if(hr == E_FAIL)
				return hr;
	}

	hr = S_OK;
	return hr;
}
Value AI::Environment::Operation() {
	Value hr;
	Symbole sym = ls->getSymCour(); //variable de gauche
	
	Value valCom;
	VAR* var;
	if(sym.getType() == Symbole::Type::VARIABLE)
	{
		
		var = getVar(sym.getChaine());
		if(var == 0)
		{
				VAR newvar;
				newvar = VAR(sym.getChaine());
				Value n;
				n = "NULL";				
				newvar.setValue(n);
				AddVar(newvar);
				var = getVar(sym.getChaine());
		}
		

		valCom = var->getValue();

	}
	else if(sym.getType() == Symbole::Type::SENTENCE)
	{
		//ici la variable doit être composée à partir d'une transcription de la forme [element1, ... element n]
		valCom = sym.getChaine(); //recuperer la phrase et la stocker dans une value

	}
	else if(sym.getType() == Symbole::Type::CHAINE)
	{
		//ici la variable doit être d'une chaine
		valCom = sym.getChaine(); //recuperer la phrase et la stocker dans une value

	}

		
	ls->suivant();
	

	/*if(ls->getSymCour().getType() != Symbole::Type::OPERATION)
		return E_FAIL;*/
	
	
		if(ls->getSymCour().getChaine() == "==" || ls->getSymCour().getChaine() == "!=" || ls->getSymCour().getChaine() == "=")
		{
			std::string operateur = ls->getSymCour().getChaine();
			ls->suivant();
			
			Value val = Operation();
			if(operateur == "=")
			{
				var->setValue(val);
				return val;
			}
			else
			return Comparaison(&valCom,&val,operateur);
		}
		else
			return valCom; //au pire la valeur de l'operation est celle de la variable
	
}
Value AI::Environment::Comparaison(Value* gauche,Value* droit,std::string operateur) {
	Value hr;
	if(operateur == "==")
	{
		hr = (*gauche == *droit);
		return hr;
	}
	else if(operateur == "!=")
	{
		hr = (*gauche != *droit);
		return hr;
	}
	hr = false;
	return hr;
}