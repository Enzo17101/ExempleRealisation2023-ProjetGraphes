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
	***** CAnalyseurSyntaxique : constructeur par d�faut de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique												*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique();

	/****************************************************************************************************************
	***** CAnalyseurSyntaxique : constructeur de recopie de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entr�e :	CAnalyseurSyntaxique ANSParam			                                                    *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique � partir d'un autre analyseur syntaxique	*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique(CAnalyseurSyntaxique& ANSParam);

	/****************************************************************************************************************
	***** CAnalyseurSyntaxique : constructeur de confort de la classe CAnalyseurSyntaxique						*****
	*****************************************************************************************************************
	***** Entr�e : char * pcANSCheminFichier			                                                        *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique � partir d'une chaine de caract�re			*****
	*****************************************************************************************************************/
	CAnalyseurSyntaxique(const char* pcCheminFichier);

	/****************************************************************************************************************
	***** ~CAnalyseurSyntaxique : destructeur de la classe CAnalyseurSyntaxique									*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction d�salloue l'espace m�moire allou� � un CAnalyseurSyntaxique					*****
	*****************************************************************************************************************/
	~CAnalyseurSyntaxique();


	//Fonctions et m�thodes

	/****************************************************************************************************************
	***** ANSGenererGraphe : Fonction permettant de cr�er un graphe � partir d'un fichier texte 				*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : CGraphe							                                                            *****
	***** Entraine : la fonction renvoie le graphe initialis� � partir du fichier correspondant au chemin de	*****
	*****			 CAnalyseurSyntaxique																	  OU*****
	**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin sp�cifi� n'a pas pus �tre	*****
	**************** ouvert																					  OU*****
	**************** Exception SYNTAXE_INVALIDE : La syntaxe du fichier texte ne respecte pas le format attendu	*****
	*****************************************************************************************************************/
	CGraphe& ANSGenererGraphe();
};