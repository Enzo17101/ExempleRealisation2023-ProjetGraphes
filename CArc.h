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
	***** Entrée :	unsigned int uiIdDestinationParam                                                           *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un arc avec l'identifiant en paramètre							    *****
	*****************************************************************************************************************/
	CArc(unsigned int uiIdDestinationParam);


	//Méthodes

	/****************************************************************************************************************
	***** ARCLireIdDestination : accesseur en lecture de uiIdDestination										*****
	*****************************************************************************************************************
	***** Entrée :	Rien							                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int								                                                    *****
	***** Entraine : La fonction renvoie la valeur de l'attribut											    *****
	*****************************************************************************************************************/
	unsigned int ARCLireIdDestination() const;

	/****************************************************************************************************************
	***** ARCModifierIdDestination : accesseur en écriture de uiIdDestination									*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdDestinationParam                                                           *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien										                                                    *****
	***** Entraine : La fonction modifie la valeur de l'attribut											    *****
	*****************************************************************************************************************/
	void ARCModifierIdDestination(unsigned int uiIdDestinationParam);
};

#include "CArc.ipp"