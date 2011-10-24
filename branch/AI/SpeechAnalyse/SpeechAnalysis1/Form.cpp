#include "StdAfx.h"
#include "Form.h"
using namespace AI;
/*
	
		CLASS Form

*/
AI::Form::Form(std::string name, TENSE tense, MOOD mood, ASPECT aspect, VOICE voice) {
	setName(&name);
	setTense(&tense);
	setMood(&mood);
	setAspect(&aspect);
	setVoice(&voice);
}

AI::Form::~Form() {
	this->name.~basic_string();
}

bool AI::Form::operator==(Form form) {
	return ( this->name == form.name && this->mood == form.mood && this->aspect == form.aspect && this->tense == form.tense && this->voice == form.voice ); 
}

bool AI::Form::operator!=(Form form) {
	return !(*this == form) ; 
}

std::string* AI::Form::getName() {
	return &this->name;
}
TENSE* AI::Form::getTense() {
	return &this->tense;
}
MOOD* AI::Form::getMood() {
	return &this->mood;
}
ASPECT* AI::Form::getAspect() {
	return &this->aspect;
}
VOICE* AI::Form::getVoice() {
	return &this->voice;
}
void AI::Form::setName(std::string* name) {
	this->name = *name;
}
void AI::Form::setTense(TENSE* tense) {
	this->tense = *tense;
}
void AI::Form::setMood(MOOD* mood) {
	this->mood = *mood;
}
void AI::Form::setAspect(ASPECT* aspect) {
	this->aspect = *aspect;
}
void AI::Form::setVoice(VOICE* voice) {
	this->voice = *voice;
}