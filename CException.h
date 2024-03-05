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
	***** CException : constructeur par d�faut de la classe CException											*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception													    *****
	*****************************************************************************************************************/
	CException();

	/****************************************************************************************************************
	***** CException : constructeur de confort de la classe CException											*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiValeur																		*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : la fonction initialise une exception � la valeur pass�e en param�tre					    *****
	*****************************************************************************************************************/
	CException(unsigned int uiValeur);


	//M�thodes

	/****************************************************************************************************************
	***** EXCLireValeur : accesseur en lecture de uiEXCValeur											   	    *****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien																						*****
	***** Sortie : unsigned int valeur																			*****
	***** Entra�ne : la fonction renvoie la valeur de l'exception												*****
	*****************************************************************************************************************/
	const unsigned int EXCLireValeur() const;

	/****************************************************************************************************************
	***** EXCModifierValeur	: accesseur en �criture de uiEXCValeur												*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiNvValeur																		*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entra�ne : la valeur de l'exception est modifi�e														*****
	*****************************************************************************************************************/
	void EXCModifierValeur(unsigned int uiNvValeur);

	/****************************************************************************************************************
	***** EXCAfficherErreur	: cette m�thode affiche le message correspondant � l'exception						*****
	*****************************************************************************************************************
	***** Entr�e : CException EXCErreur																			*****
	***** N�cessite : Rien																						*****
	***** Sortie : Rien																							*****
	***** Entra�ne : le message correspondant � l'exception est affich� dans le terminal						*****
	*****************************************************************************************************************/
	void EXCAfficherErreur();
};

#include "CException.ipp"