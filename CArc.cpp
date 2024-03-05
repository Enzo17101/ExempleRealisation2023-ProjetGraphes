#include "CArc.h"


/****************************************************************************************************************
***** CArc : constructeur de confort de la classe CArc														*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestinationParam                                                           *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un arc avec l'identifiant en param�tre							    *****
*****************************************************************************************************************/

CArc::CArc(unsigned int uiIdDestinationParam)
{
	uiARCIdDestination = uiIdDestinationParam;
}