#include "CGraphe.h"


/****************************************************************************************************************
***** CGraphe : constructeur par d�faut de la classe CGraphe												*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un graphe � partir d'un autre graphe								*****
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
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction d�salloue l'espace m�moire attribu� � un CGraphe							    *****
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
***** GRAChercherSommet : cherche dans la liste ppSOMGRAListeSommets un sommet poss�dant l'identifiant en	*****
*****					  param�tre																			*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdentifiant																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un sommet correspondant � l'identifiant	*****
*****************************************************************************************************************/

int CGraphe::GRAChercherSommet(unsigned int uiIdentifiant)
{
	unsigned int uiBoucleSommet = 0;

	//On parcours le graphe jusqu'� trouver le sommet correspondant � l'id en param�tre
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
***** GRALireIdentifiantSommet : lit l'identifiant du sommet dans la liste � la position en param�tre		*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiPosition																		*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction retourne l'identifiant du sommet avec la position sp�cifi�e en param�tre	  OU*****
**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
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
***** Entr�e :	unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant								*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie l'identifiant du sommet avec l'identifiant sp�cifi� en param�tre	  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
**************** Exception IDENTIFIANT_DOUBLE : Le nouvel identifiant sp�cifi� existe d�j� dans le graphe	*****
*****************************************************************************************************************/

void CGraphe::GRAModifierIdentifiantSommet(unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant)
{
	int iPosition = GRAChercherSommet(uiIdentifiant);

	if (iPosition == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	//Possibilit� de modifier l'id avec l'id d�j� existant
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
***** Entr�e :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction ajoute un arc entre deux sommets du graphe									  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
**************** sommet																					  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
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
***** Entr�e :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : void								                                                            *****
***** Entraine : La fonction supprime un arc entre deux sommets du graphe								  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
**************** sommet																					  OU*****
**************** Exception ARC_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun arc	  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
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
***** GRALireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants du sommet en param�tre		*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdentifiant																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie le nombre d'arcs entrants du sommet en param�tre					    *****
**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet   *****
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
***** GRALireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants du sommet en param�tre		*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdentifiant																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie le nombre d'arcs sortants du sommet en param�tre						*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet   *****
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
***** GRALireArcEntrant : accesseur en lecture de ppARCArcsEntrants du sommet en param�tre					*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'identifiant de destination de l'arc � la position donn�e en			*****
***** param�tre dans la liste d'arcs entrants du sommet sp�cifi� en param�tre							  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
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
***** GRALireArcSortant : accesseur en lecture de ppARCArcsSortants	du sommet en param�tre					*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'identifiant de destination de l'arc � la position donn�e en			*****
***** param�tre dans la liste d'arcs sortants du sommet sp�cifi� en param�tre							  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
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
***** Entr�e :	unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel			*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction inverser le sens d'un arc du graphe										  OU*****
**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
**************** sommet																					  OU*****
**************** Exception ARC_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun arc	  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
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
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : void																							*****
***** Entraine : La fonction affiche un graphe sur le terminal											  OU*****
**************** Exception POSITION_INVALIDE : exception recontr�e dans la m�thode SOMLireArcSortant		*****
*****************************************************************************************************************/

void CGraphe::GRAAfficherGraphe()
{
	unsigned int uiBoucleSommet = 0;
	unsigned int uiBoucleArc = 0;
	unsigned int uiIdDestination;
	unsigned int uiNbArcsSortants;

	/*
	* En affichant l'id de chaque sommet et ses arcs sortants (avec le sommet de destination)
	* On obtient un affichage dans le terminal de la totalit� du graphe
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