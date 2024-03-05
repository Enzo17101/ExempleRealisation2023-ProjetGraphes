#pragma once

#include <cstring>

#include "CException.h"


class CAnalyseurLexical
{
private:

	//Attribut
	char* pcANLChaine;

public:

	//Constructeurs et destructeurs

	/****************************************************************************************************************
	***** CAnalyseurLexical : constructeur par défaut de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical												*****
	*****************************************************************************************************************/
	CAnalyseurLexical();

	/****************************************************************************************************************
	***** CAnalyseurLexical : constructeur de recopie de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entrée :	AnalyseurLexical ANLParam			                                                        *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical à partir d'un autre analyseur lexical			*****
	*****************************************************************************************************************/
	CAnalyseurLexical(CAnalyseurLexical& ANLParam);

	/****************************************************************************************************************
	***** CAnalyseurLexical : constructeur de confort de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entrée :	char * pcChaineParam			                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical à partir d'une chaine de caractère				*****
	*****************************************************************************************************************/
	CAnalyseurLexical(const char * pcChaineParam);

	/****************************************************************************************************************
	***** ~CAnalyseurLexical : destructeur de la classe CAnalyseurLexical										*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction désalloue l'espace mémoire attribué à l'analyseur lexical						*****
	*****************************************************************************************************************/
	~CAnalyseurLexical();

	//Méthodes et fonctions

	/****************************************************************************************************************
	***** ARCLireIdDestination : accesseur en écriture de pcANLChaine											*****
	*****************************************************************************************************************
	***** Entrée :	char * pcNouvelleChaine																		*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie la valeur de pcANLChaine											    *****
	*****************************************************************************************************************/
	void ANLModifierChaine(const char* pcNouvelleChaine);

	/****************************************************************************************************************
	***** ANLLireBalise : fonction renvoyant, s'il en trouve une, la balise lue dans une chaine de caractère de	*****
	*****				  la forme <Balise>=<reste de la chaîne>												*****
	*****************************************************************************************************************
	***** Entrée :	char * pcChaine	                                                                            *****
	***** Nécessite : La désallocation de la chaine retournée avec delete										*****
	***** Sortie : char *							                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique à partir d'une chaine de caractère		  OU*****
	**************** Exception BALISE_INVALIDE : Le caractère de délimitation de la balise (en l'occurence		*****
	**************** le caractère "=" n'a pas été trouvé dans la chaîne											*****
	*****************************************************************************************************************/
	char* ANLLireBalise();

	/****************************************************************************************************************
	***** ANLLireNaturel : fonction renvoyant l'entier naturel lu à la position donnée d'une chaine				*****
	*****************************************************************************************************************
	***** Entrée :unsigned int uiPositionNaturel					                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'entier naturel lu												  OU*****
	**************** Exception POSITION_CHAINE_INVALIDE : La position spécifiée est en dehors de la chaîne	  OU*****
	**************** Exception ENTIER_INVALIDE : Un des caractère lu ne correspond pas à un chiffre			    *****
	*****************************************************************************************************************/
	unsigned int ANLLireNaturel(unsigned int uiPositionNaturel);
};

#include "CAnalyseurLexical.ipp"