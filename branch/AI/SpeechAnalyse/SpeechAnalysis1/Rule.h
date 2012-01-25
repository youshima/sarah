#pragma once
#include "Helpers.h"
#include "STR.h"

namespace AI
{
/*
	classe Rule
	definit une regle utilisée pour l'analyse
*/
class Rule
{
public:
	/*
		constructeur de Rule
		{initialise les variables par défaut)
	*/
	Rule();
	/*
		destructeur de Rule
		{nettoie la mémoire}
	*/
	~Rule();
	/*
		fonction getEnabled
		=> { vrai si la regle est activée }
	*/
	bool getEnabled();
	/*
		fonction getScript
		=> { le script de la regle }
	*/
	std::string getScript();
	/*
		fonction getName
		=> { le nom de la regle }
	*/
	std::string getName();
	/*
		fonction getAbout
		+> { descriptif de la regle }
	*/
	std::string getAbout();
	/*

	*/
	std::string getResult();
	/*
		procedure getScript
		{ affecte la valeur de script }
	*/
	void setScript(std::string& script);
	/*
		procedure getName
		{ affecte la valeur de name }
	*/
	void setName(std::string& name);
	/*
		procedure getAbout
		{ affecte la valeur de about }
	*/
	void setAbout(std::string& about);

	void setResult(std::string& result);
	/*
		procedure setEnabled
		{ affecte la valeur d'enabled }
	*/
	void setEnabled(bool enabled);

	
private:

private:
	std::string script; //code de la regle
	std::string name; //nom de la regle
	std::string about; //descriptif de la regle
	std::string result;
	bool enabled; //activer ou desactiver la regle
};
}