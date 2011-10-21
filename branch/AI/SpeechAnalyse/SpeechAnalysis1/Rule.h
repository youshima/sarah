#pragma once
#include "Helpers.h"
#include "STR.h"
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
		=> { pointeur sur le script de la regle }
	*/
	STR* getScript();
	/*
		fonction getName
		=> { pointeur sur le nom de la regle }
	*/
	STR* getName();
	/*
		fonction getAbout
		+> { pointeur sur le descriptif de la regle }
	*/
	STR* getAbout();
	/*
		procedure getScript
		{ affecte la valeur de script }
	*/
	void setScript(STR& script);
	/*
		procedure getName
		{ affecte la valeur de name }
	*/
	void setName(STR& name);
	/*
		procedure getAbout
		{ affecte la valeur de about }
	*/
	void setAbout(STR& about);
	/*
		procedure setEnabled
		{ affecte la valeur d'enabled }
	*/
	void setEnabled(bool& enabled);
private:

private:
	STR script; //code de la regle
	STR name; //nom de la regle
	STR about; //descriptif de la regle
	bool enabled; //activer ou desactiver la regle
};