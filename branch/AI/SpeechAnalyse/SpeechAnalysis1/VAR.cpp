#include "StdAfx.h"
#include "VAR.h"
#include "StdAfx.h"
#include "Environment.h"

/*
	CLASS VALUE
*/
Value::Value(VAR_TYPE type) {
	switch(this->type)
	{
		case INTEGER :
			buffer = (char*)malloc(sizeof(int));
			break;
		case REAL :
			buffer = (char*)malloc(sizeof(float));
			break;
		case STRING :
			buffer = 0;
			break;
		case VARCHAR :
			buffer = (char*)malloc(sizeof(char));
			break;
	}
}

Value::~Value() {
	free((void*)buffer);
}

VAR_TYPE Value::getType() {
	return this->type;
}

char* Value::getValue() {
	return this->buffer;
}

void Value::setValue(char* value) {
	switch(this->type)
	{
		case INTEGER :
			memcpy((void*)buffer,value,sizeof(int));
			break;
		case REAL :
			memcpy((void*)buffer,value,sizeof(float));
			break;
		case STRING :
			free((char*)buffer);
			buffer = (char*)malloc(sizeof(char) * strlen(value));
			memcpy((void*)buffer,value,strlen(value));
			break;
		case VARCHAR :
			memcpy((void*)buffer,value,sizeof(char));
			break;
	}
}
bool Value::operator ==(Value value) {
	switch(this->type)
	{
		case INTEGER :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(int)) == 0 );
			break;
		case REAL :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(float)) == 0 );
			break;
		case STRING :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(strlen(this->buffer))) == 0 );
			break;
		case VARCHAR :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(char)) == 0 );
			break;
		default :
			return false;
	}
	
}
bool Value::operator !=(Value value) {
	return !(*this == value);
}
/*
	CLASS VAR
*/
VAR::VAR(std::string name) : name(name) {
	this->value = 0;
}

VAR::~VAR() {
	if(value)
		value->~Value();
}

std::string* VAR::getName() {
	return &this->name;
}

Value* VAR::getValue() {
	return value;
}

void VAR::setName( std::string name ) {
	this->name = name;
}

void VAR::setValue( Value val ) {
	this->value = new Value(val.getType());
	this->value->setValue(val.getValue());
}

void VAR::operator=( Value val ) {
	this->setValue(val);
}

bool VAR::operator==( VAR val ) {
	return ( *this->getValue() == *val.getValue());
}
bool VAR::operator!=( VAR val ) {
	return !( *this == val );
}
