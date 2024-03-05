#include "CGraphe.h"


/****************************************************************************************************************
***** CGraphe : constructeur par défaut de la classe CGraphe												*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un graphe															*****
*****************************************************************************************************************/

CGraphe::CGraphe()
{
	uiGRANombreSommets = 0;
	ppSOMGRAListeSommets = nullptr;
}


/****************************************************************************************************************
***** CGraphe : constructeur de recopie de la classe CGraphe												*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un graphe à partir d'un autre graphe								*****
*****************************************************************************************************************/

CGraphe::CGraphe(CGraphe& GRAParam)
{
	unsigned int uiBoucleSommet = 0;

	uiGRANombreSommets = GRAParam.uiGRANombreSommets;

	if (uiGRANombreSommets == 0)
	{
		ppSOMGRAListeSommets = nullptr;
	}
	else
	{
		ppSOMGRAListeSommets = new CSommet*[uiGRANombreSommets];
	}

	for (uiBoucleSommet; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		ppSOMGRAListeSommets[uiBoucleSommet] = new CSommet(*GRAParam.ppSOMGRAListeSommets[uiBoucleSommet]);
	}
}


/****************************************************************************************************************
***** CGraphe : destructeur de la classe CGraphe															*****
*****************************************************************************************************************
***** Entrée :	Rien							                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction désalloue l'espace mémoire attribué à un CGraphe							    *****
*****************************************************************************************************************/

CGraphe::~CGraphe()
{
	unsigned int uiBoucleSommet = 0;

	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		delete ppSOMGRAListeSommets[uiBoucleSommet];
	}
	
	delete[] ppSOMGRAListeSommets;
}


/****************************************************************************************************************
***** GRAChercherSommet : cherche dans la liste ppSOMGRAListeSommets un sommet possédant l'identifiant en	*****
*****					  paramètre																			*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdentifiant																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un sommet correspondant à l'identifiant	*****
*****************************************************************************************************************/

int CGraphe::GRAChercherSommet(unsigned int uiIdentifiant)
{
	unsigned int uiBoucleSommet = 0;

	//On parcours le graphe jusqu'à trouver le sommet correspondant à l'id en paramètre
	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		if (ppSOMGRAListeSommets[uiBoucleSommet]->SOMLireId() == uiIdentifiant) {
			return uiBoucleSommet;
		}
	}

	//-1 correspond au retour d'erreur, autrement dit au retour lorsqu'on ne trouve pas le sommet dans le graphe
	return -1;
}


/****************************************************************************************************************
***** GRALireIdentifiantSommet : lit l'identifiant du sommet dans la liste à la position en paramètre		*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiPosition																		*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction retourne l'identifiant du sommet avec la position spécifiée en paramètre	  OU*****
**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
*****************************************************************************************************************/

unsigned int CGraphe::GRALireIdentifiantSommet(unsigned int uiPosition)
{
	if (uiPosition >= uiGRANombreSommets)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	return ppSOMGRAListeSommets[uiPosition]->SOMLireId();
}


/****************************************************************************************************************
***** GRAModifierIdentifiantSommet : modifie l'identifiant d'un sommet du graphe							*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant								*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie l'identifiant du sommet avec l'identifiant spécifié en paramètre	  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
**************** Exception IDENTIFIANT_DOUBLE : Le nouvel identifiant spécifié existe déjà dans le graphe	*****
*****************************************************************************************************************/

void CGraphe::GRAModifierIdentifiantSommet(unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant)
{
	int iPosition = GRAChercherSommet(uiIdentifiant);

	if (iPosition == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	//Possibilité de modifier l'id avec l'id déjà existant
	if (uiIdentifiant != uiNouvelIdentifiant)
	{
		if (GRAChercherSommet(uiNouvelIdentifiant) != -1)
		{
			CException EXCException(IDENTIFIANT_DOUBLE);
			throw EXCException;
		}
	}
	
	ppSOMGRAListeSommets[iPosition]->SOMModifierId(uiNouvelIdentifiant);
}


/****************************************************************************************************************
***** GRAAjouterArc : fonction permettant d'ajouter un arc entre deux sommets du graphe						*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction ajoute un arc entre deux sommets du graphe									  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
**************** sommet																					  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

void CGraphe::GRAAjouterArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive)
{
	int iPositionSommetDepart = GRAChercherSommet(uiIdentifiantDepart);
	int iPositionSommetArrive = GRAChercherSommet(uiIdentifiantArrive);

	if (iPositionSommetDepart == -1 || iPositionSommetArrive == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	//ajout de l'arc dans le sommet de depart
	ppSOMGRAListeSommets[iPositionSommetDepart]->SOMAjouterArcSortant(uiIdentifiantArrive);

	//ajout de l'arc dans le sommet d'arrivee
	ppSOMGRAListeSommets[iPositionSommetArrive]->SOMAjouterArcEntrant(uiIdentifiantDepart);
}


/****************************************************************************************************************
***** GRASupprimerArc : fonction permettant de supprimer un arc entre deux sommets du graphe				*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : void								                                                            *****
***** Entraine : La fonction supprime un arc entre deux sommets du graphe								  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
**************** sommet																					  OU*****
**************** Exception ARC_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun arc	  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

void CGraphe::GRASupprimerArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive)
{
	int iPositionSommetDepart = GRAChercherSommet(uiIdentifiantDepart);
	int iPositionSommetArrive = GRAChercherSommet(uiIdentifiantArrive);

	if (iPositionSommetDepart == -1 || iPositionSommetArrive == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	//Suppression de l'arc dans le sommet de depart
	ppSOMGRAListeSommets[iPositionSommetDepart]->SOMSupprimerArcSortant(uiIdentifiantArrive);

	//Suppression de l'arc dans le sommet d'arrivee
	ppSOMGRAListeSommets[iPositionSommetArrive]->SOMSupprimerArcEntrant(uiIdentifiantDepart);
}


/****************************************************************************************************************
***** GRALireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants du sommet en paramètre		*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdentifiant																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie le nombre d'arcs entrants du sommet en paramètre					    *****
**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet   *****
*****************************************************************************************************************/

unsigned int CGraphe::GRALireNombreArcsEntrants(unsigned int uiIdentifiant)
{
	int iPosition = GRAChercherSommet(uiIdentifiant);

	if (iPosition == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	return ppSOMGRAListeSommets[iPosition]->SOMLireNombreArcsEntrants();
}


/****************************************************************************************************************
***** GRALireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants du sommet en paramètre		*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdentifiant																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie le nombre d'arcs sortants du sommet en paramètre						*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet   *****
*****************************************************************************************************************/

unsigned int CGraphe::GRALireNombreArcsSortants(unsigned int uiIdentifiant)
{
	int iPosition = GRAChercherSommet(uiIdentifiant);

	if (iPosition == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	return ppSOMGRAListeSommets[iPosition]->SOMLireNombreArcsSortants();
}


/****************************************************************************************************************
***** GRALireArcEntrant : accesseur en lecture de ppARCArcsEntrants du sommet en paramètre					*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'identifiant de destination de l'arc à la position donnée en			*****
***** paramètre dans la liste d'arcs entrants du sommet spécifié en paramètre							  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
*****************************************************************************************************************/

unsigned int CGraphe::GRALireArcEntrant(unsigned int uiIdentifiant, unsigned int uiPosition)
{
	int iPositionSommet = GRAChercherSommet(uiIdentifiant);

	if (iPositionSommet == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	return ppSOMGRAListeSommets[iPositionSommet]->SOMLireArcEntrant(uiPosition).ARCLireIdDestination();

}


/****************************************************************************************************************
***** GRALireArcSortant : accesseur en lecture de ppARCArcsSortants	du sommet en paramètre					*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'identifiant de destination de l'arc à la position donnée en			*****
***** paramètre dans la liste d'arcs sortants du sommet spécifié en paramètre							  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
*****************************************************************************************************************/

unsigned int CGraphe::GRALireArcSortant(unsigned int uiIdentifiant, unsigned int uiPosition)
{
	int iPositionSommet = GRAChercherSommet(uiIdentifiant);

	if (iPositionSommet == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	return ppSOMGRAListeSommets[iPositionSommet]->SOMLireArcSortant(uiPosition).ARCLireIdDestination();
}


/****************************************************************************************************************
***** GRAInverserArc : fonction permettant d'inverser le sens d'un arc du graphe							*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel			*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction inverser le sens d'un arc du graphe										  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
**************** sommet																					  OU*****
**************** Exception ARC_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun arc	  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

void CGraphe::GRAInverserArc(unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel)
{
	int iPositionSommetDepart = GRAChercherSommet(uiIdentifiantDepartOriginel);
	int iPositionSommetArrive = GRAChercherSommet(uiIdentifiantArriveOriginel);

	if (iPositionSommetDepart == -1 || iPositionSommetArrive == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	//inversement de l'arc dans le sommet de depart
	ppSOMGRAListeSommets[iPositionSommetDepart]->SOMSupprimerArcSortant(uiIdentifiantArriveOriginel);
	ppSOMGRAListeSommets[iPositionSommetDepart]->SOMAjouterArcEntrant(uiIdentifiantArriveOriginel);

	//inversement de l'arc dans le sommet d'arrivee
	ppSOMGRAListeSommets[iPositionSommetArrive]->SOMSupprimerArcEntrant(uiIdentifiantDepartOriginel);
	ppSOMGRAListeSommets[iPositionSommetArrive]->SOMAjouterArcSortant(uiIdentifiantDepartOriginel);
}


/****************************************************************************************************************
***** GRAAfficherGraphe : fonction permettant l'affichage d'un graphe sur le terminal						*****
*****************************************************************************************************************
***** Entrée :	Rien							                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : void																							*****
***** Entraine : La fonction affiche un graphe sur le terminal											  OU*****
**************** Exception POSITION_INVALIDE : exception recontrée dans la méthode SOMLireArcSortant		*****
*****************************************************************************************************************/

void CGraphe::GRAAfficherGraphe()
{
	unsigned int uiBoucleSommet = 0;
	unsigned int uiBoucleArc = 0;
	unsigned int uiIdDestination;
	unsigned int uiNbArcsSortants;

	/*
	* En affichant l'id de chaque sommet et ses arcs sortants (avec le sommet de destination)
	* On obtient un affichage dans le terminal de la totalité du graphe
	*/
	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		uiNbArcsSortants = ppSOMGRAListeSommets[uiBoucleSommet]->SOMLireNombreArcsSortants();

		if (uiNbArcsSortants == 0) 
		{
			//Affichage du sommet
			cout << ppSOMGRAListeSommets[uiBoucleSommet]->SOMLireId() << '\n';
		}

		for (uiBoucleArc = 0; uiBoucleArc < uiNbArcsSortants; uiBoucleArc++)
		{
			//Affichage des arcs sortants du sommet
			uiIdDestination = ppSOMGRAListeSommets[uiBoucleSommet]->SOMLireArcSortant(uiBoucleArc).ARCLireIdDestination();

			cout << ppSOMGRAListeSommets[uiBoucleSommet]->SOMLireId() << " -> " << uiIdDestination << '\n';
		}
	}
}