#include "CArc.h"


/****************************************************************************************************************
***** ARCLireIdDestination : accesseur en lecture de uiIdDestination										*****
*****************************************************************************************************************
***** Entrée :	Rien							                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int								                                                    *****
***** Entraine : La fonction renvoie la valeur de l'attribut											    *****
*****************************************************************************************************************/

inline unsigned int CArc::ARCLireIdDestination() const
{
	return uiARCIdDestination;
}


/****************************************************************************************************************
***** ARCModifierIdDestination : accesseur en écriture de uiIdDestination									*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestinationParam                                                           *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien										                                                    *****
***** Entraine : La fonction modifie la valeur de l'attribut											    *****
*****************************************************************************************************************/

inline void CArc::ARCModifierIdDestination(unsigned int uiIdDestinationParam)
{
	uiARCIdDestination = uiIdDestinationParam;
}