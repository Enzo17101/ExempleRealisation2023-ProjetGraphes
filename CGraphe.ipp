#include "CGraphe.h"

/****************************************************************************************************************
***** SOMLireId : accesseur en lecture de uiNombreSommets													*****
*****************************************************************************************************************
***** Entr�e :	Rien																						*****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	unsigned int uiIdentifiant																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : Ajoute un sommet correspondant � l'identifiant sp�cifi� en param�tre dans le graphe	  OU*****
**************** Exception IDENTIFIANT_DOUBLE : L'identifiant sp�cifi� existe d�ja dans le graphe			*****
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

	//Pour faire la r�allocation et ajouter un sommet il faut le d�sallouer et le r�allouer avec new
	for (uiBoucleSommet = 0; uiBoucleSommet < uiGRANombreSommets; uiBoucleSommet++)
	{
		delete ppSOMGRAListeSommets[uiBoucleSommet];
	}

	delete [] ppSOMGRAListeSommets;

	uiGRANombreSommets++;
	
	ppSOMGRAListeSommets = new CSommet*[uiGRANombreSommets];

	//On recopie tous les sommets du graphe sauvegard�
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
***** Entr�e :	unsigned int uiIdentifiant																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction supprime le sommet correspondant � l'identifiant sp�cifi� en param�tre		  OU*****
**************** Exception SOMMET_INEXISTANT : L'identifiant sp�cifi� n'existe pas dans le graphe			*****
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

	//Pour faire la r�allocation et ajouter un sommet il faut le d�sallouer et le r�allouer avec new
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
	
	//Suppression de tous les arcs li�s � ce sommet
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


	//Recopie de tous les sommets sauf celui � supprimer
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
