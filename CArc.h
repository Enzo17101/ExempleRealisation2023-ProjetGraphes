#pragma once


class CArc
{
private:
	//Attribut
	unsigned int uiARCIdDestination;

public:
	//Constructeur

	/****************************************************************************************************************
	***** CArc : constructeur de confort de la classe CArc														*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdDestinationParam                                                           *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un arc avec l'identifiant en param�tre							    *****
	*****************************************************************************************************************/
	CArc(unsigned int uiIdDestinationParam);


	//M�thodes

	/****************************************************************************************************************
	***** ARCLireIdDestination : accesseur en lecture de uiIdDestination										*****
	*****************************************************************************************************************
	***** Entr�e :	Rien							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int								                                                    *****
	***** Entraine : La fonction renvoie la valeur de l'attribut											    *****
	*****************************************************************************************************************/
	unsigned int ARCLireIdDestination() const;

	/****************************************************************************************************************
	***** ARCModifierIdDestination : accesseur en �criture de uiIdDestination									*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdDestinationParam                                                           *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien										                                                    *****
	***** Entraine : La fonction modifie la valeur de l'attribut											    *****
	*****************************************************************************************************************/
	void ARCModifierIdDestination(unsigned int uiIdDestinationParam);
};

#include "CArc.ipp"