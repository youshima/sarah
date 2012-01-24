#pragma once
#include <string>
/** Cette classe definit un symbole par une chaine et un type
* @brief Definit un symbole
* @autor Anton Possylkine
*/
class Symbole
{
public:

	enum Type{VARIABLE,VALEUR,OPERATION,FIN,FIN_INST,INCONNU}; //!< Types possibles de symboles
	/** Constructeur de symbole
	*/
	Symbole(std::string chaine = "");
	/** Destructeur de symbole
	*/
	~Symbole();
	/** getteur pour le type de symbole
	* @return Le type de symbole
	*/
	inline Type getType() {return type;}
	/** getteur pour la chaine du symbole
	* @return La chaine du symbole
	*/
	inline std::string getChaine() {return chaine;} 
private:
	Type type;				//!< Type de symbole
	std::string chaine;		//!< Chaine du symbole
};

