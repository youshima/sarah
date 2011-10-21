#include "StdAfx.h"
#include "Rule.h"

Rule::Rule() {

}
Rule::~Rule() {
	script.~STR();
	name.~STR();
	about.~STR();
}
STR* Rule::getScript() {
	return &script;
}
STR* Rule::getName() {
	return &name;
}
STR* Rule::getAbout() {
	return &about;
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

