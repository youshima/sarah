#include "StdAfx.h"
#include "VAR.h"
#include "StdAfx.h"
#include "Environment.h"

/*
	CLASS VALUE
*/
Value::Value(VAR_TYPE type = VAR_TYPE_NONE) : buffer(0) {
	setType(type);
}

Value::~Value() {
	free((void*)buffer);
}

VAR_TYPE Value::getType() {
	return this->type;
}

void Value::setType(VAR_TYPE type)
{
	if(buffer != 0)
		free((void*)buffer);
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
		case VARBOOL :
			buffer = (char*)malloc(sizeof(bool));
			break;
		case VARRESULT :
			buffer = (char*)malloc(sizeof(HRESULT));
			break;
		default :
			buffer = 0;
			break;
	}
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
		case VARBOOL :
			memcpy((void*)buffer,value,sizeof(bool));
			break;
		case VARRESULT :
			memcpy((void*)buffer,value,sizeof(HRESULT));
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
		case VARBOOL :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(bool)) == 0 );
			break;
		case VARRESULT :
			return ( this->getType() == value.getType() && memcmp(this->getValue(),value.getValue(), sizeof(HRESULT)) == 0 );
			break;
		default :
			return false;
	}
	
}
bool Value::operator !=(Value value) {
	return !(*this == value);
}
void Value::operator =(int val) {
	setType(INTEGER);
	this->setValue((char*) &val);
}
void Value::operator =(float val) {
	setType(REAL);
	this->setValue((char*) &val);
}
void Value::operator =(bool val) {
	setType(VARBOOL);
	this->setValue((char*) &val);
}
void Value::operator =(std::string val) {
	setType(STRING);
	this->setValue((char*) val.c_str());
}
void Value::operator =(HRESULT val) {
	setType(VARRESULT);
	this->setValue((char*) &val);
}
void Value::operator =(char val) {
	setType(VARCHAR);
	this->setValue((char*) val);
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
