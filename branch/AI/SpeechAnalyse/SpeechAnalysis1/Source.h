#pragma once

#include "HTTPGET.h"
#include "Database.h"
#include <string>

class Source
{
public:
	/*
		constructeur de Source
		{initialise les variables}
	*/
	Source(void);

	/*
		destructeur de Source
		{nettoie la mémoire}
	*/
	virtual ~Source(void);

	/*
		fonction Getword
		=> { Retourne les information du mot si on les trouve}
	*/
	virtual DBWORD * Getword(std::string& name) = 0;

	
private:

	std::string urlPath;
	std::string urlServer;
};
