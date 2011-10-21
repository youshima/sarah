#include "StdAfx.h"
#include "Rule.h"

Rule::Rule() : enabled(false) {

}
Rule::~Rule() {
	script.~STR();
	name.~STR();
	about.~STR();
}
bool Rule::getEnabled() {
	return this->enabled;
}
STR* Rule::getScript() {
	return &this->script;
}
STR* Rule::getName() {
	return &this->name;
}
STR* Rule::getAbout() {
	return &this->about;
}
void Rule::setScript(STR& script) {
	this->script = script;
}
void Rule::setName(STR& name) {
	this->name = name;
}
void Rule::setAbout(STR& about) {
	this->about = about;
}
void Rule::setEnabled(bool& enabled) {
	this->enabled = enabled;
}

