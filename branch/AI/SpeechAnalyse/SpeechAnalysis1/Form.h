#pragma once
#include "STR.h"

namespace AI
{

enum TYPE {VERB, NOUN, ADJECTIVE, ADVERB, PRONOUN, PREPOSITION, FORMUNCTION, INTERJECTION, TYPE_NONE};
enum TENSE {PAST, NON_PAST, TENSE_NONE};
enum MOOD {INDICATIVE, SUBJUNCTIVE, IMPERATIVE, MOOD_NONE};
enum ASPECT {SIMPLE, CONTINUOUS, PERFECT, PERFECT_CONTINUOUS, ASPECT_NONE};
enum VOICE {ACTIVE, PASSIVE, VOICE_NONE};
/*
	class Form :
	definit une formes pour un verbe
*/
class Form
{
public:
	/*
		constructeur de Form
		{initialise les variables par défaut ou selon l'utilisateur}
	*/
	Form(std::string name = "", TENSE tense = TENSE_NONE, MOOD mood = MOOD_NONE, ASPECT aspect = ASPECT_NONE, VOICE voice = VOICE_NONE);
	/*
		destructeur de Form
		{nettoie la mémoire}
	*/
	~Form();
	/*
		operateur de comparaison entre deux Form
		=> { vrai si tous les parametres des élements sont égaux }
	*/
	bool operator==(Form form);
	/*
		operateur de comparaison entre deux Form
		=> { faux si tous les parametres des élements sont égaux }
	*/
	bool operator!=(Form form);
	/*
		fonction getName
		=> { pointeur sur le nom de la forme }
	*/
	std::string* getName();
	/*
		fonction getTense
		=> { pointeur sur le tense de la forme }
	*/
	TENSE* getTense();
	/*
		fonction getMood
		=> { pointeur sur le mood de la forme }
	*/
	MOOD* getMood();
	/*
		fonction getAspect
		=> { pointeur sur l'aspect de la forme }
	*/
	ASPECT* getAspect();
	/*
		fonction getVoice
		=> { pointeur sur voice de la forme }
	*/
	VOICE* getVoice();

	/*
		procedure setName
		{ attribue le nom de la forme }
	*/
	void setName(std::string* name);
	/*
		procedure setTense
		{ attribue le tense de la forme }
	*/
	void setTense(TENSE* tense);
	/*
		procedure setMood
		{ attribue le mood de la forme }
	*/
	void setMood(MOOD* mood);
	/*
		procedure setAspect
		{ attribue l'aspect de la forme }
	*/
	void setAspect(ASPECT* aspect);
	/*
		fonction getVoice
		{ attribue le voice de la forme }
	*/
	void setVoice(VOICE* voice);
private:
	std::string name;
	TENSE tense;
	MOOD mood;
	ASPECT aspect;
	VOICE voice;
};
}