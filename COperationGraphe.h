#pragma once
#include "CGraphe.h"

class COperationGraphe
{
public:
	//M�thode

	/****************************************************************************************************************
	***** OGRInverserArcsGraphe : inverse tous les arcs d'un graphe												*****
	*****************************************************************************************************************
	***** Entr�e :	CGraphe							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : CGraphe																						*****
	***** Entraine : La fonction retourne un nouveau graphe correspondant au graphe en param�tre mais avec ses  *****
	***** arcs invers�s																						  OU*****
	**************** Exception POSITION_INVALIDE : Exception recontr�e dans la m�thode GRALireArcSortant ou     *****
	**************** GRALireIdentifiantSommet                                                                 OU*****
	**************** Exception SOMMET_INEXISTANT : Exception recontr�e dans la m�thode GRALireArcSortant ou     *****
	**************** GRALireNombreArcsSortants ou GRAInverserArc                                              OU*****
	**************** Exception ARC_INEXISTANT : Exception recontr�e dans la m�thode GRAInverserArc			  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	CGraphe & OGRInverserArcsGraphe(CGraphe & GRAParam);
};

