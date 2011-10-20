#include "StdAfx.h"
#include "File.h"

File::File(STR filename, bool& exists) {
	//tester si le fichier est vide
	file.open( filename.getString() , std::fstream::binary | std::fstream::in );

	exists = file.is_open() ; //test si le fichier existait dejà

	if(file.is_open())
		file.close();

	file.open(filename.getString(),std::ios_base::binary | std::ios_base::in | std::ios_base::out); //juste ouvrir le fichier normalement
}
File::~File() {
	if(file.is_open())
		file.close();
}
void File::write(const STR& str) {

	file.write((char*)str.getLength(), sizeof(UINT)); //ecrire la longueur
	file.write((char*)str.getString(), sizeof(char) * *str.getLength() ); //ecrire la chaine de caracteres
}
void File::read(STR& str) {

		UINT strLength;
		file.read((char*)&strLength, sizeof(UINT)); //lire la longueur du nom
		char* buf = new char[strLength+1];
		file.read(buf, sizeof(char) * strLength ); //lire la chaine de caracteres
		buf[strLength] = '\0';
		str.setString(buf);

		delete[] buf;
}
void File::write(const Form& form) {

	//ecrire la forme
	write(&form.getName());

	file.write((char*)form.getTense(), sizeof(TENSE));
	file.write((char*)form.getMood(), sizeof(MOOD)); 
	file.write((char*)form.getAspect(), sizeof(ASPECT));
	file.write((char*)form.getVoice(), sizeof(VOICE)); 
}

void File::read(Form& form) {

		read(*form.getName());

		file.read((char*)form.getTense(), sizeof(TENSE));
		file.read((char*)form.getMood(), sizeof(MOOD)); 
		file.read((char*)form.getAspect(), sizeof(ASPECT));
		file.read((char*)form.getVoice(), sizeof(VOICE)); 
}
void File::write(const VAR& var) {


}
void File::read(VAR& var) {
	
}
void File::write(const int& integer) {
	file.write((char*)&integer, sizeof(TENSE));
}
void File::read(int& integer) {
	file.read((char*)&integer, sizeof(int));
}