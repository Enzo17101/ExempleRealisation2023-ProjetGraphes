#include "COperationGraphe.h"


/****************************************************************************************************************
***** OGRInverserArcsGraphe : inverse tous les arcs d'un graphe												*****
*****************************************************************************************************************
***** Entrée :	CGraphe							                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : CGraphe																						*****
***** Entraine : La fonction retourne un nouveau graphe correspondant au graphe en paramètre mais avec ses  *****
***** arcs inversés																						  OU*****
**************** Exception POSITION_INVALIDE : Exception recontrée dans la méthode GRALireArcSortant ou     *****
**************** GRALireIdentifiantSommet                                                                 OU*****
**************** Exception SOMMET_INEXISTANT : Exception recontrée dans la méthode GRALireArcSortant ou     *****
**************** GRALireNombreArcsSortants ou GRAInverserArc                                              OU*****
**************** Exception ARC_INEXISTANT : Exception recontrée dans la méthode GRAInverserArc			  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

CGraphe& COperationGraphe::OGRInverserArcsGraphe(CGraphe& GRAParam)
{
    CGraphe* pGRAResultat = new CGraphe(GRAParam);

    unsigned int uiBoucleSommet = 0;
    unsigned int uiBoucleArc = 0;
    unsigned int uiId;
    unsigned int uiIdDestination;
    unsigned int uiNbSommet = GRAParam.GRALireNombreSommets();
    unsigned int uiNbArcSortant;
    
    /*En appelant GRAInverserArc sur chaque arc sortant de chaque sommet
    On aura traité tous les arcs du graphe sans risque de traitement en double*/
    for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommet; uiBoucleSommet++)
    {
        uiId = GRAParam.GRALireIdentifiantSommet(uiBoucleSommet);
        uiNbArcSortant = GRAParam.GRALireNombreArcsSortants(uiId);

        for (uiBoucleArc = 0; uiBoucleArc < uiNbArcSortant; uiBoucleArc++)
        {
            uiIdDestination = GRAParam.GRALireArcSortant(uiId, uiBoucleArc);

            pGRAResultat->GRAInverserArc(uiId, uiIdDestination);
        }
    }

    return *pGRAResultat;
}
