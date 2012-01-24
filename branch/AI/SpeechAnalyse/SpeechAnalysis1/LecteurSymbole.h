#pragma once

#include "Symbole.h"
#include <string>
/** Cette classe permet de lire un script caractere par caractere et identifie les symboles présents, l'accès se fait symbole par symbole
* @brief Lit une chaine de caracteres en identifiant les symboles
* @autor Anton Possylkine
*/
class LecteurSymbole
{
public:
	/** Constructeur de LecteurSymbole
	* @param str Chaine contenant le script
	*/
	LecteurSymbole(std::string str);
	/** Abandonne le symbole courant et lit le suivant
	*/
	void suivant();
	/** getteur pour le symbole courant
	*/
	inline Symbole getSymCour() {return symbole;}
private:
	std::string str;	//!< Chaine contenant le script
	unsigned cursor;	//!< Curseur utilisé lors de la lecture
	Symbole symbole;	//!< Pointeur sur symbole courant
};

