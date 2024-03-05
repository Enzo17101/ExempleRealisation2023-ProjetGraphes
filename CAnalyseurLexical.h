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
	***** CAnalyseurLexical : constructeur par d�faut de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical												*****
	*****************************************************************************************************************/
	CAnalyseurLexical();

	/****************************************************************************************************************
	***** CAnalyseurLexical : constructeur de recopie de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entr�e :	AnalyseurLexical ANLParam			                                                        *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical � partir d'un autre analyseur lexical			*****
	*****************************************************************************************************************/
	CAnalyseurLexical(CAnalyseurLexical& ANLParam);

	/****************************************************************************************************************
	***** CAnalyseurLexical : constructeur de confort de la classe CAnalyseurLexical							*****
	*****************************************************************************************************************
	***** Entr�e :	char * pcChaineParam			                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un analyseur lexical � partir d'une chaine de caract�re				*****
	*****************************************************************************************************************/
	CAnalyseurLexical(const char * pcChaineParam);

	/****************************************************************************************************************
	***** ~CAnalyseurLexical : destructeur de la classe CAnalyseurLexical										*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction d�salloue l'espace m�moire attribu� � l'analyseur lexical						*****
	*****************************************************************************************************************/
	~CAnalyseurLexical();

	//M�thodes et fonctions

	/****************************************************************************************************************
	***** ARCLireIdDestination : accesseur en �criture de pcANLChaine											*****
	*****************************************************************************************************************
	***** Entr�e :	char * pcNouvelleChaine																		*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie la valeur de pcANLChaine											    *****
	*****************************************************************************************************************/
	void ANLModifierChaine(const char* pcNouvelleChaine);

	/****************************************************************************************************************
	***** ANLLireBalise : fonction renvoyant, s'il en trouve une, la balise lue dans une chaine de caract�re de	*****
	*****				  la forme <Balise>=<reste de la cha�ne>												*****
	*****************************************************************************************************************
	***** Entr�e :	char * pcChaine	                                                                            *****
	***** N�cessite : La d�sallocation de la chaine retourn�e avec delete										*****
	***** Sortie : char *							                                                            *****
	***** Entraine : La fonction initialise un analyseur syntaxique � partir d'une chaine de caract�re		  OU*****
	**************** Exception BALISE_INVALIDE : Le caract�re de d�limitation de la balise (en l'occurence		*****
	**************** le caract�re "=" n'a pas �t� trouv� dans la cha�ne											*****
	*****************************************************************************************************************/
	char* ANLLireBalise();

	/****************************************************************************************************************
	***** ANLLireNaturel : fonction renvoyant l'entier naturel lu � la position donn�e d'une chaine				*****
	*****************************************************************************************************************
	***** Entr�e :unsigned int uiPositionNaturel					                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'entier naturel lu												  OU*****
	**************** Exception POSITION_CHAINE_INVALIDE : La position sp�cifi�e est en dehors de la cha�ne	  OU*****
	**************** Exception ENTIER_INVALIDE : Un des caract�re lu ne correspond pas � un chiffre			    *****
	*****************************************************************************************************************/
	unsigned int ANLLireNaturel(unsigned int uiPositionNaturel);
};

#include "CAnalyseurLexical.ipp"