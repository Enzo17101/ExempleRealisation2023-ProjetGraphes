#include "CException.h"


/****************************************************************************************************************
***** EXCLireValeur : cette méthode lit la valeur de la classe										   	    *****
*****************************************************************************************************************
***** Entrée : Rien																							*****
***** Nécessite : Rien																						*****
***** Sortie : unsigned int valeur																			*****
***** Entraîne : la fonction renvoie la valeur de l'exception												*****
*****************************************************************************************************************/

inline const unsigned int CException::EXCLireValeur() const
{
	return 0;
}


/****************************************************************************************************************
***** EXCModifierValeur	: cette méthode modifie la valeur de la classe										*****
*****************************************************************************************************************
***** Entrée : unsigned int uiNvValeur																		*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraîne : la valeur de l'exception est modifiée														*****
*****************************************************************************************************************/

inline void CException::EXCModifierValeur(unsigned int uiNvValeur)
{
	uiEXCValeur = uiNvValeur;
}