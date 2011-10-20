#include "StdAfx.h"
#include "Form.h"

/*
	
		CLASS Form

*/
Form::Form(STR name, TENSE tense, MOOD mood, ASPECT aspect, VOICE voice) {
	setName(&name);
	setTense(&tense);
	setMood(&mood);
	setAspect(&aspect);
	setVoice(&voice);
}

Form::~Form() {
	this->name.~STR();
}

bool Form::operator==(Form form) {
	return ( this->name == form.name && this->mood == form.mood && this->aspect == form.aspect && this->tense == form.tense && this->voice == form.voice ); 
}

bool Form::operator!=(Form form) {
	return !(*this == form) ; 
}

STR* Form::getName() {
	return &this->name;
}
TENSE* Form::getTense() {
	return &this->tense;
}
MOOD* Form::getMood() {
	return &this->mood;
}
ASPECT* Form::getAspect() {
	return &this->aspect;
}
VOICE* Form::getVoice() {
	return &this->voice;
}
void Form::setName(STR* name) {
	this->name = *name;
}
void Form::setTense(TENSE* tense) {
	this->tense = *tense;
}
void Form::setMood(MOOD* mood) {
	this->mood = *mood;
}
void Form::setAspect(ASPECT* aspect) {
	this->aspect = *aspect;
}
void Form::setVoice(VOICE* voice) {
	this->voice = *voice;
}