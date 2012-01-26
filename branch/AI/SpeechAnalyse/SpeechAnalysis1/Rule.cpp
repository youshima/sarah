#include "StdAfx.h"
#include "Rule.h"

AI::Rule::Rule() : enabled(false) {
	result = "NONE";
}
AI::Rule::~Rule() {

}
bool AI::Rule::getEnabled() {
	return this->enabled;
}
std::string AI::Rule::getScript() {
	return this->script;
}
std::string AI::Rule::getName() {
	return this->name;
}
std::string AI::Rule::getAbout() {
	return this->about;
}
std::string AI::Rule::getResult() {
	return this->result;
}
void AI::Rule::setScript(std::string& script) {
	this->script = script;
}
void AI::Rule::setName(std::string& name) {
	this->name = name;
}
void AI::Rule::setAbout(std::string& about) {
	this->about = about;
}
void AI::Rule::setResult(std::string& result) {
	this->result = result;
}
void AI::Rule::setEnabled(bool enabled) {
	this->enabled = enabled;
}

