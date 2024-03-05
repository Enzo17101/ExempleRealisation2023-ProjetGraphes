#include "CArc.h"


/****************************************************************************************************************
***** CArc : constructeur de confort de la classe CArc														*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestinationParam                                                           *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un arc avec l'identifiant en paramètre							    *****
*****************************************************************************************************************/

CArc::CArc(unsigned int uiIdDestinationParam)
{
	uiARCIdDestination = uiIdDestinationParam;
}