#include "StdAfx.h"
#include "File.h"

File::File() {
	
}
File::~File() {
		this->close(); //fermer le fichier
}
HRESULT File::open(std::string filename, bool& existed) {

	this->filename = filename;
	file.open( this->filename.c_str() , std::fstream::binary | std::fstream::in );
	existed = file.is_open() ; //test si le fichier existait dejà

	file.close(); //fermer le fichier

	file.open(this->filename.c_str(),std::ios_base::binary | std::ios_base::in | std::ios_base::out | std::ios_base::app); //juste ouvrir le fichier normalement

	if(file.is_open())
		return S_OK;
	else
		return E_FILENOTFOUND;
}
HRESULT File::close() {
	if(this->isOpen())
	{
		file.close();
		return S_OK;
	}
	else
		return E_FAIL;

}
HRESULT File::empty() {
	if(this->isOpen())
	{
		close(); //fermer le fichier
		file.open( filename.c_str() , std::fstream::binary | std::fstream::out );
		if(file.is_open()) //le fichier a été vidé par fstream
		{
			close(); //fermer le fichier
			bool existed;
			open(filename, existed); //réouvrir le fichier
			return S_OK;
		}
		else
			return E_FAIL;
	}
	else
		return E_FAIL;
}
int File::getReadCursor() {
	return file.tellg();
}
int File::getWriteCursor() {
	return file.tellp();
}
void File::to(UINT offset) {
	file.seekg(offset,file.beg); //se mettre a l'offset offset à partir du début du fichier
	file.seekp(offset,file.beg); //se mettre a l'offset offset à partir du début du fichier
}
void File::toBegin() {
	file.seekg(0,file.beg); //se mettre au début du fichier
	file.seekp(0,file.beg); //se mettre au début du fichier
}
void File::toEnd() {
	file.seekg(0,file.end); //se mettre à la fin du fichier
	file.seekp(0,file.end); //se mettre au début du fichier
}
bool File::isEmpty() {
	int cursor = file.tellg();
	toBegin();
	int cursorPos1 = file.tellg();
	toEnd();
	int cursorPos2 = file.tellg();

	bool empty = cursorPos1 == cursorPos2;

	file.seekg(file.beg + cursor); // se remettre où nous etions avant l'opération

	return empty;
}
HRESULT File::write(std::string& str) {
	toEnd();
	if(isOpen())
	{
		write((int)str.size()); //ecrire la longueur
		if(str.size() > 0)
		file.write((char*)str.c_str(), sizeof(char) * str.size() ); //ecrire la chaine de caracteres

		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(std::string& str) {

	if(isOpen())
	{
		int strLength;
		read(strLength); //lire la longueur du nom
		char* buf = new char[strLength+1];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres
		buf[strLength] = '\0';

		str = buf;

		delete[] buf;
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::write(Form& form) {
	toEnd();
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
		std::string str;
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
	toEnd();
	if(isOpen())
	{
		write(var.getName());
		Value val = var.getValue();
		
		VAR_TYPE type = val.getType();
		file.write((char*)&type, sizeof(VAR_TYPE));
		switch(type)
		{
			case INTEGER :
				file.write((char*)val.getValue(), sizeof(int));
			break;
			case REAL :
				file.write((char*)val.getValue(), sizeof(float));
			break;
			case VARCHAR :
				file.write(val.getValue(), sizeof(char));
			break;
			case STRING :
				std::string str;
				str = val.getValue();
				write(str);
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
		std::string str;
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
				std::string str;
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
		toEnd();
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
		toEnd();
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
		toEnd();
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
		toEnd();
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
		toEnd();
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
HRESULT File::write(Rule& rule) {
	if(isOpen())
	{
		toEnd();
		write(rule.getName());
		write(rule.getScript());
		write(rule.getAbout());
		write(rule.getEnabled());
		return S_OK;
	}
	else
		return E_FAIL;
}
HRESULT File::read(Rule& rule) {
	if(isOpen())
	{
		std::string name,script,about,result;
		bool enabled;
		read(name);
		read(script);
		read(about);
		read(enabled);

		rule.setName(name);
		rule.setScript(script);
		rule.setAbout(about);
		rule.setResult(std::string("NONE"));
		rule.setEnabled(enabled);

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