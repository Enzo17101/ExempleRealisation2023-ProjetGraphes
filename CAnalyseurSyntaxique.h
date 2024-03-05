#pragma once

#include <cstring>
#include <fstream>

#include "CException.h"
#include "CAnalyseurLexical.h"
#include "CGraphe.h"


class CAnalyseurSyntaxique
{
private:
	//Attribut
	char* pcANSChemin;

public:
	//Constructeurs et destructeurs

	/****************************************************************************************************************
	***** CAnalyseurSyntaxique : constructeur par défaut de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique												*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique();

	/****************************************************************************************************************
	***** CAnalyseurSyntaxique : constructeur de recopie de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entrée :	CAnalyseurSyntaxique ANSParam			                                                    *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique à partir d'un autre analyseur syntaxique	*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique(CAnalyseurSyntaxique& ANSParam);

	/****************************************************************************************************************
	***** CAnalyseurSyntaxique : constructeur de confort de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entrée : char * pcANSCheminFichier			                                                        *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique à partir d'une chaine de caractère			*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique(const char* pcCheminFichier);

	/****************************************************************************************************************
	***** ~CAnalyseurSyntaxique : destructeur de la classe CAnalyseurSyntaxique									*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction désalloue l'espace mémoire alloué à un CAnalyseurSyntaxique					*****
	*****************************************************************************************************************/
	~CAnalyseurSyntaxique();


	//Fonctions et méthodes

	/****************************************************************************************************************
	***** ANSGenererGraphe : Fonction permettant de créer un graphe à partir d'un fichier texte 				*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : CGraphe							                                                            *****
	***** Entraine : la fonction renvoie le graphe initialisé à partir du fichier correspondant au chemin de	*****
	*****			 CAnalyseurSyntaxique																	  OU*****
	**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin spécifié n'a pas pus être	*****
	**************** ouvert																					  OU*****
	**************** Exception SYNTAXE_INVALIDE : La syntaxe du fichier texte ne respecte pas le format attendu	*****
	*****************************************************************************************************************/
	CGraphe& ANSGenererGraphe();
};