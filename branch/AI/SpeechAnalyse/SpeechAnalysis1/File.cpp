#include "StdAfx.h"
#include "File.h"

File::File() {
	
}
File::~File() {
		this->close(); //fermer le fichier
}
HRESULT File::open(STR filename, bool& existed) {

	this->filename = filename;
	file.open( filename.getString() , std::fstream::binary | std::fstream::in );
	existed = file.is_open() ; //test si le fichier existait dejà

	this->close(); //fermer le fichier

	file.open(filename.getString(),std::ios_base::binary | std::ios_base::in | std::ios_base::out); //juste ouvrir le fichier normalement

	if(file.is_open())
		return S_OK;
	else
		return E_FILENOTFOUND;
}
HRESULT File::close() {
	if(this->isOpen())
	{
		file.close();

		filename = "";
		return S_OK;
	}
	else
		return E_FAIL;

}
int File::getCursor() {
	return file.tellg();
}
void File::toBegin() {
	file.seekg(std::ios_base::beg); //se mettre au début du fichier
}
void File::toEnd() {
	file.seekg(std::ios_base::end); //se mettre à la fin du fichier
}
bool File::isEmpty() {
	int cursor = file.tellg();
	toBegin();
	bool empty = file.eof(); // la fin est t'elle aussi le debut?
	file.seekg(std::ios_base::beg + cursor); // se remettre où nous etions avant l'opération

	return empty;
}
HRESULT File::write(STR& str) {

	if(isOpen())
	{
		file.write((char*)str.getLength(), sizeof(UINT)); //ecrire la longueur
		file.write((char*)str.getString(), sizeof(char) * *str.getLength() ); //ecrire la chaine de caracteres

		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(STR& str) {

	if(isOpen())
	{
		UINT strLength;
		file.read((char*)&strLength, sizeof(UINT)); //lire la longueur du nom
		char* buf = new char[strLength+1];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres
		buf[strLength] = '\0';
		str.setString(buf);

		delete[] buf;
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(Form& form) {

	if(isOpen())
	{
		//ecrire la forme
		write(*form.getName());

		file.write((char*)form.getTense(), sizeof(TENSE));
		file.write((char*)form.getMood(), sizeof(MOOD)); 
		file.write((char*)form.getAspect(), sizeof(ASPECT));
		file.write((char*)form.getVoice(), sizeof(VOICE)); 
		return S_OK;
	}
	else
		return E_FAIL;
}

HRESULT File::read(Form& form) {
	if(isOpen())
	{
		STR str;
		TENSE* tense = new TENSE();
		MOOD* mood = new MOOD();
		ASPECT* aspect = new ASPECT();
		VOICE* voice = new VOICE();

		read(str);

		file.read((char*)tense, sizeof(TENSE));
		file.read((char*)mood, sizeof(MOOD)); 
		file.read((char*)aspect, sizeof(ASPECT));
		file.read((char*)voice, sizeof(VOICE)); 
		
		form.setName(&str);
		form.setTense(tense);
		form.setMood(mood);
		form.setAspect(aspect);
		form.setVoice(voice);
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(VAR& var) {
	if(isOpen())
	{
		write(*var.getName());
		Value* val = var.getValue();
		
		VAR_TYPE type = val->getType();
		file.write((char*)&type, sizeof(VAR_TYPE));
		switch(type)
		{
			case INTEGER :
				file.write(val->getValue(), sizeof(int));
			break;
			case REAL :
				file.write(val->getValue(), sizeof(float));
			break;
			case VARCHAR :
				file.write(val->getValue(), sizeof(char));
			break;
			case STRING :
				STR* str = new STR();
				str = (STR*)val->getValue();
				write(*str);
			break;
			
		}
		return S_OK;
	}
	else
		return E_FAIL;

}
HRESULT File::read(VAR& var) {
	if(isOpen())
	{
		STR str;
		read(str);
		var.setName(str);

		Value val(VAR_TYPE_NONE);
		
		VAR_TYPE type;
		file.read((char*)&type, sizeof(VAR_TYPE));
		switch(type)
		{
			case INTEGER :
				int i;
				read(i);
				val.setValue((char*)&i);
			break;
			case REAL :
				float f;
				read(f);
				val.setValue((char*)&f);
			break;
			case VARCHAR :
				char c;
				read(c);
				val.setValue((char*)&c);
			break;
			case STRING :
				STR str;
				read(str);
				val.setValue((char*)&str);
			break;
			
		}
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(const int& integer) {
	if(isOpen())
	{
		file.write((char*)&integer, sizeof(int));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(int& integer) {
	if(isOpen())
	{
		file.read((char*)&integer, sizeof(int));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(const float& real) {
	if(isOpen())
	{
		file.write((char*)&real, sizeof(float));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(float& real) {
	if(isOpen())
	{
		file.read((char*)&real, sizeof(float));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(const bool& boolean) {
	if(isOpen())
	{
		file.write((char*)&boolean, sizeof(bool));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(char& boolean) {
	if(isOpen())
	{
		file.read((char*)&boolean, sizeof(bool));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(const char& caracter) {
	if(isOpen())
	{
		file.write((char*)&caracter, sizeof(char));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(bool& caracter) {
	if(isOpen())
	{
		file.read((char*)&caracter, sizeof(char));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(const TYPE& type) {
	if(isOpen())
	{
		file.write((char*)&type, sizeof(TYPE));
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(TYPE& type) {
	if(isOpen())
	{
		file.read((char*)&type, sizeof(TYPE));
		return S_OK;
	}
	else
		return E_FAIL;
}
bool File::eof() {
	if(file.is_open())
		return file.eof();
	else
		return true;
}
bool File::isOpen() {
	return file.is_open();
}