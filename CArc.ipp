#include "CArc.h"


/****************************************************************************************************************
***** ARCLireIdDestination : accesseur en lecture de uiIdDestination										*****
*****************************************************************************************************************
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int								                                                    *****
***** Entraine : La fonction renvoie la valeur de l'attribut											    *****
*****************************************************************************************************************/

inline unsigned int CArc::ARCLireIdDestination() const
{
	return uiARCIdDestination;
}


/****************************************************************************************************************
***** ARCModifierIdDestination : accesseur en �criture de uiIdDestination									*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestinationParam                                                           *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien										                                                    *****
***** Entraine : La fonction modifie la valeur de l'attribut											    *****
*****************************************************************************************************************/

inline void CArc::ARCModifierIdDestination(unsigned int uiIdDestinationParam)
{
	uiARCIdDestination = uiIdDestinationParam;
}