
/*

	CLASS ENVIRONMENT
*/
Environment::Environment() {
	file.open(FILENAME,std::ios_base::binary | std::ios_base::in | std::ios_base::out); //juste ouvrir le fichier normalement
	if(file.is_open())
	{
		if(!file.eof()) //tester si le fichier est vide
		{
			
		}
		file.close();
	}
}
~Environment::Environment() {
	Save();
	for(UINT i = 0; i < this->Vars.size() ; i++)
		Vars[i].~VAR();
}

HRESULT Environment::Save() {

}

HRESULT Environment::AddVar(VAR var) {

}

HRESULT Environment::RemoveVar(STR name) {

}

HRESULT Environment::RemoveVar(UINT index) {

}

UINT Environment::FindVarIndex(STR name) {

}

VAR* Environment::getVar(UINT index) {

}

VAR* Environment::getVar(STR name) {

}

HRESULT Environment::setVar(STR name, Value value) {

}

HRESULT Environment::setVar(UINT index, Value value) {

}