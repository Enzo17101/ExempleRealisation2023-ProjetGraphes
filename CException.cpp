#include "CException.h"
#include "CGraphe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CAnalyseurLexical.h"
#include "CAnalyseurSyntaxique.h"

/****************************************************************************************************************
***** CException : constructeur par d�faut de la classe CException											*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	unsigned int uiValeur																		*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : la fonction initialise une exception � la valeur pass�e en param�tre					    *****
*****************************************************************************************************************/

CException::CException(unsigned int uiValeur)
{
	uiEXCValeur = uiValeur;
}


/****************************************************************************************************************
***** EXCAfficherErreur	: cette m�thode affiche le message correspondant � l'exception						*****
*****************************************************************************************************************
***** Entr�e : CException EXCErreur																			*****
***** N�cessite : Rien																						*****
***** Sortie : Rien																							*****
***** Entra�ne : le message correspondant � l'exception est affich� dans le terminal						*****
*****************************************************************************************************************/

void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur)
	{
		default:
		{
			cout << "Erreur par d�faut de CException.\n";
			break;
		}
		case MAUVAISE_INITIALISATION:
		{
			cout << "L'initialisation avec l'allocation ou reallocation n'a pas fonctionn�.\n";
			break;
		}
		case POSITION_INVALIDE:
		{
			cout << "La position � laquelle vous essayez d'acc�der est en dehors de la liste.\n";
			break;
		}
		case ARC_INEXISTANT:
		{
			cout << "L'arc que vous avez indiqu� n'existe pas dans la liste.\n";
			break;
		}
		case SYNTAXE_INVALIDE:
		{
			cout << "Erreur lors de la lecture du fichier, veuillez v�rifier sa syntaxe.\n";
			break;
		}
		case SOMMET_INEXISTANT :
		{
			cout << "L'identifiant du sommet que vous avez saisi n'existe pas dans le graphe.\n";
			break;	
		}
		case IDENTIFIANT_DOUBLE:
		{
			cout << "L'identifiant de sommet que vous avez saisi existe d�j� dans le graphe.\n";
			break;
		}
		case CHEMIN_INVALIDE:
		{
			cout << "Le chemin fourni ne correspond pas a un fichier valide.\n";
			break;
		}
		case BALISE_INVALIDE :
		{
			cout << "Une de vos balise n'a pas pus �tre lue dans le fichier.\n";
			break;
		}
		case ENTIER_INVALIDE :
		{
			cout << "Un entier n'a pas pus �tre lu dans le fichier.\n";
			break;
		}
	}
}