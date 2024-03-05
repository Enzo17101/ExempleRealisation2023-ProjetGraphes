#pragma once
#define PAS_ERREUR 0

//Pour les graphes
#define IDENTIFIANT_DOUBLE 10
#define SOMMET_INEXISTANT 11

//Pour les sommets
#define MAUVAISE_INITIALISATION 20
#define POSITION_INVALIDE 21
#define ARC_INEXISTANT 22

//Pour les analyseurs
#define SYNTAXE_INVALIDE 30
#define CHEMIN_INVALIDE 31
#define POSITION_CHAINE_INVALIDE 32
#define BALISE_INVALIDE 33
#define ENTIER_INVALIDE 34

#include <iostream>

using namespace std;


class CException
{
private:
	//Attributs
	unsigned int uiEXCValeur;

public:
	//Constructeur

	/****************************************************************************************************************
	***** CException : constructeur par défaut de la classe CException											*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception													    *****
	*****************************************************************************************************************/
	CException();

	/****************************************************************************************************************
	***** CException : constructeur de confort de la classe CException											*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiValeur																		*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception à la valeur passée en paramètre					    *****
	*****************************************************************************************************************/
	CException(unsigned int uiValeur);


	//Méthodes

	/****************************************************************************************************************
	***** EXCLireValeur : accesseur en lecture de uiEXCValeur											   	    *****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien																						*****
	***** Sortie : unsigned int valeur																			*****
	***** Entraîne : la fonction renvoie la valeur de l'exception												*****
	*****************************************************************************************************************/
	const unsigned int EXCLireValeur() const;

	/****************************************************************************************************************
	***** EXCModifierValeur	: accesseur en écriture de uiEXCValeur												*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiNvValeur																		*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraîne : la valeur de l'exception est modifiée														*****
	*****************************************************************************************************************/
	void EXCModifierValeur(unsigned int uiNvValeur);

	/****************************************************************************************************************
	***** EXCAfficherErreur	: cette méthode affiche le message correspondant à l'exception						*****
	*****************************************************************************************************************
	***** Entrée : CException EXCErreur																			*****
	***** Nécessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entraîne : le message correspondant à l'exception est affiché dans le terminal						*****
	*****************************************************************************************************************/
	void EXCAfficherErreur();
};

#include "CException.ipp"