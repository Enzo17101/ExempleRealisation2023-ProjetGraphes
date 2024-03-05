#include "CGraphe.h"

/****************************************************************************************************************
***** SOMLireId : accesseur en lecture de uiNombreSommets													*****
*****************************************************************************************************************
***** Entrée :	Rien																						*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie le nombre de sommets du graphe										    *****
*****************************************************************************************************************/

inline unsigned int CGraphe::GRALireNombreSommets() const
{
	return uiGRANombreSommets;
}

/****************************************************************************************************************
***** GRAAjouterSommet : ajoute un sommet au graphe															*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiant																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : Ajoute un sommet correspondant à l'identifiant spécifié en paramètre dans le graphe	  OU*****
**************** Exception IDENTIFIANT_DOUBLE : L'identifiant spécifié existe déja dans le graphe			*****
*****************************************************************************************************************/

inline void CGraphe::GRAAjouterSommet(unsigned int uiIdentifiant)
{
	unsigned int uiBoucleSommet;

	if (GRAChercherSommet(uiIdentifiant) != -1) 
	{
		CException EXCException(IDENTIFIANT_DOUBLE);
		throw EXCException;
	}

	CGraphe* GRASauvegardeGraphe = new CGraphe(*this);

	//Pour faire la réallocation et ajouter un sommet il faut le désallouer et le réallouer avec new
	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		delete ppSOMGRAListeSommets[uiBoucleSommet];
	}

	delete [] ppSOMGRAListeSommets;

	uiGRANombreSommets++;
	
	ppSOMGRAListeSommets = new CSommet*[uiGRANombreSommets];

	//On recopie tous les sommets du graphe sauvegardé
	for (uiBoucleSommet = 0; uiBoucleSommet < GRASauvegardeGraphe->uiGRANombreSommets; uiBoucleSommet++)
	{
		ppSOMGRAListeSommets[uiBoucleSommet] = new CSommet(*GRASauvegardeGraphe->ppSOMGRAListeSommets[uiBoucleSommet]);
	}

	//Puis on ajoute le nouveau sommet
	ppSOMGRAListeSommets[uiGRANombreSommets - 1] = new CSommet(uiIdentifiant);

	delete GRASauvegardeGraphe;
}


/****************************************************************************************************************
***** GRASupprimerSommet : fonction permettant la suppression d'un sommet du graphe							*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdentifiant																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction supprime le sommet correspondant à l'identifiant spécifié en paramètre		  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant spécifié n'existe pas dans le graphe			*****
*****************************************************************************************************************/

inline void CGraphe::GRASupprimerSommet(unsigned int uiIdentifiant)
{
	unsigned int uiBoucleSommet = 0;
	if (GRAChercherSommet(uiIdentifiant) == -1)
	{
		CException EXCException(SOMMET_INEXISTANT);
		throw EXCException;
	}

	CGraphe* GRASauvegardeGraphe = new CGraphe(*this);

	//Pour faire la réallocation et ajouter un sommet il faut le désallouer et le réallouer avec new
	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		delete ppSOMGRAListeSommets[uiBoucleSommet];
	}

	delete[] ppSOMGRAListeSommets;

	uiGRANombreSommets--;

	ppSOMGRAListeSommets = new CSommet*[uiGRANombreSommets];
	
	unsigned int uiBoucleSommetSauvegarde = 0;

	unsigned int uiBoucleArc = 0;
	unsigned int uiIdDestination = 0;
	unsigned int uiPositionDestination = 0;
	unsigned int uiNombreArcsEntrants = 0;
	unsigned int uiNombreArcsSortants= 0;
	
	//Suppression de tous les arcs liés à ce sommet
	unsigned int uiPositionSommetSupprime = GRASauvegardeGraphe->GRAChercherSommet(uiIdentifiant);

	uiNombreArcsEntrants =  GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionSommetSupprime]->SOMLireNombreArcsEntrants();
	for (uiBoucleArc = 0; uiBoucleArc < uiNombreArcsEntrants; uiBoucleArc++)
	{
		uiIdDestination = GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionSommetSupprime]->SOMLireArcEntrant(uiBoucleArc).ARCLireIdDestination();
		uiPositionDestination = GRASauvegardeGraphe->GRAChercherSommet(uiIdDestination);
		GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionDestination]->SOMSupprimerArcSortant(uiIdentifiant);
	}

	uiNombreArcsSortants = GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionSommetSupprime]->SOMLireNombreArcsSortants();
	for (uiBoucleArc = 0; uiBoucleArc < uiNombreArcsSortants; uiBoucleArc++)
	{
		uiIdDestination = GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionSommetSupprime]->SOMLireArcSortant(uiBoucleArc).ARCLireIdDestination();
		uiPositionDestination = GRASauvegardeGraphe->GRAChercherSommet(uiIdDestination);
		GRASauvegardeGraphe->ppSOMGRAListeSommets[uiPositionDestination]->SOMSupprimerArcEntrant(uiIdentifiant);
	}


	//Recopie de tous les sommets sauf celui à supprimer
	while (uiBoucleSommet < uiGRANombreSommets)
	{
		if (GRASauvegardeGraphe->ppSOMGRAListeSommets[uiBoucleSommetSauvegarde]->SOMLireId() == uiIdentifiant)
		{
			//Pour sauter le sommet que l'on veut supprimer
			uiBoucleSommetSauvegarde++;
		}
		ppSOMGRAListeSommets[uiBoucleSommet] = new CSommet(*GRASauvegardeGraphe->ppSOMGRAListeSommets[uiBoucleSommetSauvegarde]);
		uiBoucleSommet++;
		uiBoucleSommetSauvegarde++;
	}

	delete GRASauvegardeGraphe;
}
