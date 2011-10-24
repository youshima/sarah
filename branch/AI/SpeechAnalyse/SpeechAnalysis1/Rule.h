#pragma once
#include "Helpers.h"
#include "STR.h"
namespace AI
{
/*
	classe Rule
	definit une regle utilis�e pour l'analyse
*/
class Rule
{
public:
	/*
		constructeur de Rule
		{initialise les variables par d�faut)
	*/
	Rule();
	/*
		destructeur de Rule
		{nettoie la m�moire}
	*/
	~Rule();
	/*
		fonction getEnabled
		=> { vrai si la regle est activ�e }
	*/
	bool getEnabled();
	/*
		fonction getScript
		=> { pointeur sur le script de la regle }
	*/
	std::string* getScript();
	/*
		fonction getName
		=> { pointeur sur le nom de la regle }
	*/
	std::string* getName();
	/*
		fonction getAbout
		+> { pointeur sur le descriptif de la regle }
	*/
	std::string* getAbout();
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
	bool enabled; //activer ou desactiver la regle
};
}