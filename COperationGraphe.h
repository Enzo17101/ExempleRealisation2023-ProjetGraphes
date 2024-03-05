#pragma once
#include "CGraphe.h"

class COperationGraphe
{
public:
	//Méthode

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
	CGraphe & OGRInverserArcsGraphe(CGraphe & GRAParam);
};

