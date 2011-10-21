#include "StdAfx.h"
#include "Rule.h"

AI::Rule::Rule() : enabled(false) {

}
AI::Rule::~Rule() {
	script.~STR();
	name.~STR();
	about.~STR();
}
bool AI::Rule::getEnabled() {
	return this->enabled;
}
STR* AI::Rule::getScript() {
	return &this->script;
}
STR* AI::Rule::getName() {
	return &this->name;
}
STR* AI::Rule::getAbout() {
	return &this->about;
}
void AI::Rule::setScript(STR& script) {
	this->script = script;
}
void AI::Rule::setName(STR& name) {
	this->name = name;
}
void AI::Rule::setAbout(STR& about) {
	this->about = about;
}
void AI::Rule::setEnabled(bool& enabled) {
	this->enabled = enabled;
}

