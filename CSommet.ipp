#include "CSommet.h"


/****************************************************************************************************************
***** SOMLireId : accesseur en lecture de uiId																*****
*****************************************************************************************************************
***** Entr�e :	Rien							                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie la valeur de l'identifiant du sommet								    *****
*****************************************************************************************************************/

inline unsigned int CSommet::SOMLireId() const
{
	return uiSOMId;
}


/****************************************************************************************************************
***** SOMModifierId : accesseur en �criture de uiId															*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdParam							                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie la valeur de l'identifiant du sommet								    *****
*****************************************************************************************************************/

inline void CSommet::SOMModifierId(unsigned int uiIdParam)
{
	uiSOMId = uiIdParam;
}


/****************************************************************************************************************
***** SOMLireArcEntrant : accesseur en lecture de ppARCArcsEntrants											*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiPosition			                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : CArc																							*****
***** Entraine : La fonction renvoie l'arc � la position donn�e en param�tre							  OU*****
**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
*****************************************************************************************************************/

inline CArc& CSommet::SOMLireArcEntrant(unsigned int uiPosition) const
{
	//Si la position est hors de la liste on l�ve une exception
	if (uiPosition >= uiSOMNombreArcsEntrants)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	return *ppARCSOMArcsEntrants[uiPosition];
}


/****************************************************************************************************************
***** SOMAjouterArcEntrant : accesseur en �criture de ppARCArcsEntrants										*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestination	                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction cr�e un arc avec l'identifiant en param�tre et l'ajoute � la liste			    *****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
*****************************************************************************************************************/

inline void CSommet::SOMAjouterArcEntrant(unsigned int uiIdDestination)
{
	//Sauvegarde du pointeur si le realloc �choue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsEntrants;

	//On met le pointeur � nullptr si la liste est vide
	if (uiSOMNombreArcsEntrants == 0)
	{
		ppARCSOMArcsEntrants = nullptr;
	}

	//On r�alloue la liste, si elle est vide alors elle sera allou�e
	ppARCSOMArcsEntrants = (CArc**)realloc(ppARCSOMArcsEntrants, (uiSOMNombreArcsEntrants+1) * sizeof(CArc*));

	//On v�rifie si le realloc a bien fonctionn�
	if (ppARCSOMArcsEntrants == nullptr)
	{
		free(pARCSauvegardePointeur);
		CException EXCException(MAUVAISE_INITIALISATION);
		throw EXCException;
	}

	uiSOMNombreArcsEntrants++;

	//A la derni�re position que l'on vient d'allouer on ajoute l'arc
	ppARCSOMArcsEntrants[uiSOMNombreArcsEntrants-1] = new CArc(uiIdDestination);
}


/****************************************************************************************************************
***** SOMSupprimerArcEntrant : accesseur en �criture de ppARCArcsEntrants									*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestination	                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction supprime de la liste l'arc avec l'identifiant en param�tre					  OU*****
**************** Exception ARC_INEXISTANT : L'identifiant de destination en param�tre ne correspond � aucun *****
**************** arc de la liste																		  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
*****************************************************************************************************************/

inline void CSommet::SOMSupprimerArcEntrant(unsigned int uiIdDestination)
{
	int iPosition;
	unsigned int uiBoucleArc;

	//On r�cup�re la position du sommet demand�
	iPosition = SOMChercherArcEntrant(uiIdDestination);

	//Si la recherche n'a pas trouv� de sommet on l�ve une exception
	if (iPosition == -1) 
	{
		CException EXCException(ARC_INEXISTANT);
		throw EXCException;
	}

	//Suppression de l'arc � la position trouv�e
	delete ppARCSOMArcsEntrants[iPosition];

	//On d�cale les arcs dans la liste
	for (uiBoucleArc = iPosition; uiBoucleArc < uiSOMNombreArcsEntrants - 1; uiBoucleArc++)
	{
		ppARCSOMArcsEntrants[uiBoucleArc] = ppARCSOMArcsEntrants[uiBoucleArc + 1];
	}

	//Sauvegarde du pointeur si le realloc �choue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsEntrants;

	uiSOMNombreArcsEntrants--;

	//On d�salloue le pointeur si on vient de supprimer le dernier �l�ment
	if (uiSOMNombreArcsEntrants == 0)
	{
		free(ppARCSOMArcsEntrants);
		ppARCSOMArcsEntrants = nullptr;
	}
	else
	{
		ppARCSOMArcsEntrants = (CArc**)realloc(ppARCSOMArcsEntrants, (uiSOMNombreArcsEntrants) * sizeof(CArc*));

		//On v�rifie si le realloc a bien fonctionn�
		if (ppARCSOMArcsEntrants == nullptr)
		{
			free(pARCSauvegardePointeur);
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}

	}
}


/****************************************************************************************************************
***** SOMChercherArcEntrant : cherche dans la liste ppARCSOMArcsEntrants un arc poss�dant l'identifiant en  *****
*****						  param�tre																		*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdDestination																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant � la destination	    *****
*****************************************************************************************************************/

inline int CSommet::SOMChercherArcEntrant(unsigned int uiIdDestination)
{
	unsigned int uiBoucleArc = 0;

	//On parcourt la liste et on retourne la premi�re position de l'identifiant trouv�e
	for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsEntrants; uiBoucleArc++)
	{
		if (ppARCSOMArcsEntrants[uiBoucleArc]->ARCLireIdDestination() == uiIdDestination) {
			return uiBoucleArc;
		}
	}

	return -1;
}


/****************************************************************************************************************
***** SOMLireArcSortant : accesseur en lecture de ppARCArcsSortants											*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiPosition			                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : CArc																							*****
***** Entraine : La fonction renvoie l'arc � la position donn�e en param�tre							  OU*****
**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
*****************************************************************************************************************/

inline CArc& CSommet::SOMLireArcSortant(unsigned int uiPosition) const
{
	//Si la position est hors de la liste on l�ve une exception
	if (uiPosition >= uiSOMNombreArcsSortants)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	return *ppARCSOMArcsSortants[uiPosition];
}


/****************************************************************************************************************
***** SOMAjouterArcSortant : accesseur en �criture de ppARCArcsSortants										*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestination	                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction cr�e un arc avec l'identifiant en param�tre et l'ajoute � la liste			    *****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
*****************************************************************************************************************/

inline void CSommet::SOMAjouterArcSortant(unsigned int uiIdDestination)
{
	//Sauvegarde du pointeur si le realloc �choue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsSortants;

	//On met le pointeur � nullptr si la liste est vide
	if (uiSOMNombreArcsSortants == 0) 
	{
		ppARCSOMArcsSortants = nullptr;
	}

	//On r�alloue la liste, si elle est vide alors elle sera allou�e
	ppARCSOMArcsSortants = (CArc**)realloc(ppARCSOMArcsSortants, (uiSOMNombreArcsSortants + 1) * sizeof(CArc*));

	//On v�rifie si le realloc a bien fonctionn�
	if (ppARCSOMArcsSortants == nullptr)
	{
		free(pARCSauvegardePointeur);
		CException EXCException(MAUVAISE_INITIALISATION);
		throw EXCException;
	}

	uiSOMNombreArcsSortants++;

	//A la derni�re position que l'on vient d'allouer on ajoute l'arc
	ppARCSOMArcsSortants[uiSOMNombreArcsSortants - 1] = new CArc(uiIdDestination);
}


/****************************************************************************************************************
***** SOMSupprimerArcSortant : accesseur en �criture de ppARCArcsSortants									*****
*****************************************************************************************************************
***** Entr�e :	unsigned int uiIdDestination	                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction supprime de la liste l'arc avec l'identifiant en param�tre					  OU*****
**************** Exception ARC_INEXISTANT : L'identifiant de destination en param�tre ne correspond � aucun *****
**************** arc de la liste																		  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
*****************************************************************************************************************/

inline void CSommet::SOMSupprimerArcSortant(unsigned int uiIdDestination)
{
	int iPosition;
	unsigned int uiBoucleArc;

	//On r�cup�re la position du sommet demand�
	iPosition = SOMChercherArcSortant(uiIdDestination);
	
	//Si la recherche n'a pas trouv� de sommet on l�ve une exception
	if (iPosition == -1)
	{
		CException EXCException(ARC_INEXISTANT);
		throw EXCException;
	}

	//Suppression de l'arc � la position trouv�e
	delete ppARCSOMArcsSortants[iPosition];

	//On d�cale les arcs dans la liste
	for (uiBoucleArc = iPosition; uiBoucleArc < uiSOMNombreArcsSortants - 1; uiBoucleArc++)
	{
		ppARCSOMArcsSortants[uiBoucleArc] = ppARCSOMArcsSortants[uiBoucleArc + 1];
	}

	//Sauvegarde du pointeur si le realloc �choue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsSortants;

	uiSOMNombreArcsSortants--;

	//On d�salloue le pointeur si on vient de supprimer le dernier �l�ment
	if (uiSOMNombreArcsSortants == 0)
	{
		free(ppARCSOMArcsSortants);
		ppARCSOMArcsSortants = nullptr;
	}
	else
	{
		ppARCSOMArcsSortants = (CArc**)realloc(ppARCSOMArcsSortants, (uiSOMNombreArcsSortants) * sizeof(CArc*));

		//On v�rifie si le realloc a bien fonctionn�
		if (ppARCSOMArcsSortants == nullptr)
		{
			free(pARCSauvegardePointeur);
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}
	}
}


/****************************************************************************************************************
***** SOMChercherArcSortant : cherche dans la liste ppARCSOMArcsSortants un arc poss�dant l'identifiant en  *****
*****						  param�tre																		*****
*****************************************************************************************************************
***** Entr�e : unsigned int uiIdDestination																	*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant � la destination	    *****
*****************************************************************************************************************/

inline int CSommet::SOMChercherArcSortant(unsigned int uiIdDestination)
{
	unsigned int uiBoucleArc = 0;

	//On parcourt la liste et on retourne la premi�re position de l'identifiant trouv�e
	for (uiBoucleArc = 0; uiBoucleArc < uiSOMNombreArcsSortants; uiBoucleArc++)
	{
		if (ppARCSOMArcsSortants[uiBoucleArc]->ARCLireIdDestination() == uiIdDestination) {
			return uiBoucleArc;
		}
	}

	return -1;
}


/****************************************************************************************************************
***** SOMLireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants								*****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie la taille de la liste pcARCArcsEntrants							    *****
*****************************************************************************************************************/

inline unsigned int CSommet::SOMLireNombreArcsEntrants() const
{
	return uiSOMNombreArcsEntrants;
}


/****************************************************************************************************************
***** SOMLireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants								*****
*****************************************************************************************************************
***** Entr�e : Rien																							*****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie la taille de la liste pcARCArcsSortants							    *****
*****************************************************************************************************************/

inline unsigned int CSommet::SOMLireNombreArcsSortants() const
{
	return uiSOMNombreArcsSortants;
}