#include "CSommet.h"


/****************************************************************************************************************
***** CSommet : constructeur par d�faut de la classe CSommet												*****
*****************************************************************************************************************
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un sommet														    *****
*****************************************************************************************************************/

CSommet::CSommet()
{
	uiSOMId = 0;

	ppARCSOMArcsEntrants = nullptr;
	ppARCSOMArcsSortants = nullptr;

	uiSOMNombreArcsEntrants = 0;
	uiSOMNombreArcsSortants = 0;
}


/****************************************************************************************************************
***** CSommet : constructeur de recopie de la classe CSommet												*****
*****************************************************************************************************************
***** Entr�e : CSommet SOMParam							                                                    *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un sommet en recopiant le sommet en param�tre					  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec malloc n'a pas fonctionn�		*****
*****************************************************************************************************************/

CSommet::CSommet(CSommet& SOMParam)
{
	unsigned int uiBoucleArc = 0;

	uiSOMId = SOMParam.uiSOMId;

	uiSOMNombreArcsEntrants = SOMParam.uiSOMNombreArcsEntrants;
	uiSOMNombreArcsSortants = SOMParam.uiSOMNombreArcsSortants;


	//On ajoute le pointeur � null
	ppARCSOMArcsEntrants = nullptr;

	//Si la liste est � 0 alors on laisse le pointeur � null
	if(uiSOMNombreArcsEntrants != 0)
	{
		ppARCSOMArcsEntrants = (CArc**)malloc(uiSOMNombreArcsEntrants * sizeof(CArc*));

		//On v�rifie si le malloc a bien fonctionn�
		if (ppARCSOMArcsEntrants == nullptr)
		{
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}

		//Ajout de chaque arc dans la liste
		for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsEntrants; uiBoucleArc++)
		{
			ppARCSOMArcsEntrants[uiBoucleArc] = new CArc(*SOMParam.ppARCSOMArcsEntrants[uiBoucleArc]);
		}
	}
	

	ppARCSOMArcsSortants = nullptr;

	//Si la liste est � 0 alors on laisse le pointeur � null
	if (uiSOMNombreArcsSortants != 0)
	{
		ppARCSOMArcsSortants = (CArc**)malloc(uiSOMNombreArcsSortants * sizeof(CArc*));

		//On v�rifie si le malloc a bien fonctionn�
		if (ppARCSOMArcsSortants == nullptr)
		{
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}

		//Ajout de chaque arc dans la liste
		for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsSortants; uiBoucleArc++)
		{
			ppARCSOMArcsSortants[uiBoucleArc] = new CArc(*SOMParam.ppARCSOMArcsSortants[uiBoucleArc]);
		}
	}
}


/****************************************************************************************************************
***** CSommet : constructeur de confort de la classe CSommet												*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdParam			                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un sommet avec l'identifiant en param�tre						    *****
*****************************************************************************************************************/

CSommet::CSommet(unsigned int uiIdParam)
{
	uiSOMId = uiIdParam;

	ppARCSOMArcsEntrants = nullptr;
	ppARCSOMArcsSortants = nullptr;

	uiSOMNombreArcsEntrants = 0;
	uiSOMNombreArcsSortants = 0;
}


/****************************************************************************************************************
***** CSommet : destructeur de la classe CSommet															*****
*****************************************************************************************************************
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction d�salloue l'espace m�moire attribu� � un CSommet							    *****
*****************************************************************************************************************/

CSommet::~CSommet()
{
	unsigned int uiBoucleArc = 0;
	
	//On supprime chaque arc de la liste d'arcs entrants
	for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsEntrants; uiBoucleArc++) 
	{
		delete ppARCSOMArcsEntrants[uiBoucleArc];
	}

	//On supprime chaque arc de la liste d'arcs sortants
	for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsSortants; uiBoucleArc++)
	{
		delete ppARCSOMArcsSortants[uiBoucleArc];
	}

	free(ppARCSOMArcsEntrants);
	free(ppARCSOMArcsSortants);
	
	ppARCSOMArcsEntrants = nullptr;
	ppARCSOMArcsSortants = nullptr;
}