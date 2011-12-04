#pragma once

#include "Database.h"
#include "Source.h"

namespace AI
{

	namespace BROWSER
	{
		/*
			classe Browser
			Permet de rechercher les informations d'un mot a partir d'un dictionnaire en ligne
		*/

		class Browser
		{
		public:
			/*
				constructeur de Browser
				{initialise les variables}
			*/
			Browser();

			/*
				destructeur de Browser
				{nettoie la mémoire}
			*/
			~Browser();

			/*
				fonction find
				=> {
						retourne un pointeur sur la structure DBWORD avec les infos du mot word
				   }
			*/
			DBWORD * find(std::string word);
		private:
			Database db;
			std::vector<Source *> SourceList;
		};
	}
}