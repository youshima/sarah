#include "StdAfx.h"
#include "Source.h"
#include "HTTPGET.h"

Source::Source(void):
httpGet()
{
}

Source::~Source(void)
{
}


DictionaryReference::DictionaryReference(void)
{
	this->urlPath.assign("/d/?q=");
	this->urlServer.assign("m.dictionary.com");
}

DictionaryReference::~DictionaryReference(void)
{
}

DBWORD * DictionaryReference::Getword(std::string& name)
{
	DBWORD * w;
	DBVERB * v;
	std::string urlPathTemp = urlPath + name;
	int longueur;
	int lecture = 0;
	int ecriture = 0;
	char fin[] = "Origin:";
	char * types[] = {"verb", "noun", "adjective", "adverb", "pronoun", "preposition", "formunction", "interjection", "Usage note"};
	char buffer_form[100];
	char buffer_def[1000];
	std::string string_form;
	std::string string_def;
	int i,j;
	Form * verb_form = NULL;
	TENSE tense = TENSE_NONE;
	MOOD mood = MOOD_NONE;
	ASPECT aspect = ASPECT_NONE;
	VOICE voice = VOICE_NONE;
	
	char * buffer_reponse = httpGet.http_get((char *)urlPathTemp.c_str(), (char *)this->urlServer.c_str());
	//On a le code de la page web contenant les infos du mot name

	strstr(buffer_reponse, "<div id=\"embed_dresultitem_r1\"");

	longueur = strlen(buffer_reponse);

	while (lecture < longueur)
	{
		if (buffer_reponse[lecture] == '<')//Filtre a balises html
		{
			while ((buffer_reponse[lecture] != '>') && (lecture < longueur))
			{
				lecture ++;
			}
			buffer_reponse[ecriture] = ' ';
			ecriture ++;
		}
		else
		{
			for (i = 0 ; i < 7 ; i ++)//Boucle pour detecter la fin de la partie de la page contenant les infos du mot
			{
				if (buffer_reponse[lecture + i] != fin[i])
					break;
			}
			if (i == 6)
				break;
			buffer_reponse[ecriture] = buffer_reponse[lecture];
			ecriture ++;
			lecture ++;
		}
	}

	buffer_reponse[ecriture] = '\0';
	strstr(buffer_reponse, "] ");

	i = 7;

	while (i >= 7)//pour eviter les problemes crées par l'ordre d'affichage chaotique des infos...
	{
		strstr(buffer_reponse, "- ");
		//On a une chaine contenant toutes les infos du mot

		for (i = 0 ; i < 8 ; i ++)//Boucle pour detecter le type du mot
		{
			longueur = strlen(types[i]);
			for (j = 0 ; j < longueur ; j ++)
			{
				if (buffer_reponse[j + 2] != types[i][j])
					break;
			}
			if (j == longueur - 1)
				break;
		}
	}

	if (i == 0)//c'est un verbe
	{
		v = new DBVERB(name);
		v->setType((AI::TYPE)i);

		strstr(buffer_reponse, ") ");

		if (httpGet.strrch(buffer_reponse, "1.") <= 6)//verbe regulier
		{
			v->setIrregular(false);
		}
		else
		{
			v->setIrregular(true);
			lecture = 1;
			i = 0;
			while (buffer_reponse[lecture] != '1')
			{
				ecriture = 0;
				while (buffer_reponse[lecture] == ' ')
					lecture ++;

				while (buffer_reponse[lecture] != ' ')
				{
					buffer_form[ecriture] = buffer_reponse[lecture];
					ecriture ++;
					lecture ++;
				}
				buffer_form[ecriture] = '\0';
				i ++;
				string_form.assign(buffer_form);
				if (httpGet.strrch(buffer_form, "ing") == strlen(buffer_form) - 3)//Forme en -ing
				{
					tense = TENSE_NONE;
					mood = INDICATIVE;
					aspect = CONTINUOUS;
					voice = ACTIVE;
				}
				else if (i == 1)//Forme du passé simple
				{
					tense = PAST;
					mood = INDICATIVE;
					aspect = SIMPLE;
					voice = ACTIVE;
				}
				else//Forme du past perfect
				{
					tense = PAST;
					mood = INDICATIVE;
					aspect = PERFECT;
					voice = ACTIVE;
				}
				verb_form = new Form(string_form, tense, mood, aspect, voice);
				v->AddForm(*verb_form);
			}
		}

		strstr(buffer_reponse, "1.");//On recupere la definition principale du mot

		for (i = 4 ; buffer_reponse[i] != '2' ; i ++)
		{
			buffer_def[i - 4] = buffer_reponse[i];
		}
		buffer_def[i - 4] = '\0';

		string_def.assign(buffer_def);
		v->setDef(string_def);

		return (DBWORD *)v;
	}
	else
	{
		w = new DBWORD(name);
		w->setType((AI::TYPE)i);

		strstr(buffer_reponse, "1.");//On recupere la definition principale du mot

		for (i = 4 ; buffer_reponse[i] != '2' ; i ++)
		{
			buffer_def[i - 4] = buffer_reponse[i];
		}
		buffer_def[i - 4] = '\0';

		string_def.assign(buffer_def);
		w->setDef(string_def);

		return w;
	}
}