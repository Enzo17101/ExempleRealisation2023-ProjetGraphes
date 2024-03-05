#include "CException.h"
#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CAnalyseurLexical.h"
#include "CAnalyseurSyntaxique.h"

/****************************************************************************************************************
***** CException : constructeur par défaut de la classe CException											*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception													    *****
*****************************************************************************************************************/

CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}


/****************************************************************************************************************
***** CException : constructeur de confort de la classe CException											*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiValeur																		*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception à la valeur passée en paramètre					    *****
*****************************************************************************************************************/

CException::CException(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


/****************************************************************************************************************
***** EXCAfficherErreur	: cette méthode affiche le message correspondant à l'exception						*****
*****************************************************************************************************************
***** Entrée : CException EXCErreur																			*****
***** Nécessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entraîne : le message correspondant à l'exception est affiché dans le terminal						*****
*****************************************************************************************************************/

void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur)
	{
		default:
		{
			cout << "Erreur par défaut de CException.\n";
			break;
		}
		case MAUVAISE_INITIALISATION:
		{
			cout << "L'initialisation avec l'allocation ou reallocation n'a pas fonctionné.\n";
			break;
		}
		case POSITION_INVALIDE:
		{
			cout << "La position à laquelle vous essayez d'accéder est en dehors de la liste.\n";
			break;
		}
		case ARC_INEXISTANT:
		{
			cout << "L'arc que vous avez indiqué n'existe pas dans la liste.\n";
			break;
		}
		case SYNTAXE_INVALIDE:
		{
			cout << "Erreur lors de la lecture du fichier, veuillez vérifier sa syntaxe.\n";
			break;
		}
		case SOMMET_INEXISTANT :
		{
			cout << "L'identifiant du sommet que vous avez saisi n'existe pas dans le graphe.\n";
			break;	
		}
		case IDENTIFIANT_DOUBLE:
		{
			cout << "L'identifiant de sommet que vous avez saisi existe déjà dans le graphe.\n";
			break;
		}
		case CHEMIN_INVALIDE:
		{
			cout << "Le chemin fourni ne correspond pas a un fichier valide.\n";
			break;
		}
		case BALISE_INVALIDE :
		{
			cout << "Une de vos balise n'a pas pus être lue dans le fichier.\n";
			break;
		}
		case ENTIER_INVALIDE :
		{
			cout << "Un entier n'a pas pus être lu dans le fichier.\n";
			break;
		}
	}
}