#include "CSommet.h"


/****************************************************************************************************************
***** SOMLireId : accesseur en lecture de uiId																*****
*****************************************************************************************************************
***** Entrée :	Rien							                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie la valeur de l'identifiant du sommet								    *****
*****************************************************************************************************************/

inline unsigned int CSommet::SOMLireId() const
{
	return uiSOMId;
}


/****************************************************************************************************************
***** SOMModifierId : accesseur en écriture de uiId															*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdParam							                                            *****
***** Nécessite : Rien				                                                                        *****
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
***** Entrée :	unsigned int uiPosition			                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : CArc																							*****
***** Entraine : La fonction renvoie l'arc à la position donnée en paramètre							  OU*****
**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
*****************************************************************************************************************/

inline CArc& CSommet::SOMLireArcEntrant(unsigned int uiPosition) const
{
	//Si la position est hors de la liste on lève une exception
	if (uiPosition >= uiSOMNombreArcsEntrants)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	return *ppARCSOMArcsEntrants[uiPosition];
}


/****************************************************************************************************************
***** SOMAjouterArcEntrant : accesseur en écriture de ppARCArcsEntrants										*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestination	                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction crée un arc avec l'identifiant en paramètre et l'ajoute à la liste			    *****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

inline void CSommet::SOMAjouterArcEntrant(unsigned int uiIdDestination)
{
	//Sauvegarde du pointeur si le realloc échoue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsEntrants;

	//On met le pointeur à nullptr si la liste est vide
	if (uiSOMNombreArcsEntrants == 0)
	{
		ppARCSOMArcsEntrants = nullptr;
	}

	//On réalloue la liste, si elle est vide alors elle sera allouée
	ppARCSOMArcsEntrants = (CArc**)realloc(ppARCSOMArcsEntrants, (uiSOMNombreArcsEntrants+1) * sizeof(CArc*));

	//On vérifie si le realloc a bien fonctionné
	if (ppARCSOMArcsEntrants == nullptr)
	{
		free(pARCSauvegardePointeur);
		CException EXCException(MAUVAISE_INITIALISATION);
		throw EXCException;
	}

	uiSOMNombreArcsEntrants++;

	//A la dernière position que l'on vient d'allouer on ajoute l'arc
	ppARCSOMArcsEntrants[uiSOMNombreArcsEntrants-1] = new CArc(uiIdDestination);
}


/****************************************************************************************************************
***** SOMSupprimerArcEntrant : accesseur en écriture de ppARCArcsEntrants									*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestination	                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction supprime de la liste l'arc avec l'identifiant en paramètre					  OU*****
**************** Exception ARC_INEXISTANT : L'identifiant de destination en paramètre ne correspond à aucun *****
**************** arc de la liste																		  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

inline void CSommet::SOMSupprimerArcEntrant(unsigned int uiIdDestination)
{
	int iPosition;
	unsigned int uiBoucleArc;

	//On récupère la position du sommet demandé
	iPosition = SOMChercherArcEntrant(uiIdDestination);

	//Si la recherche n'a pas trouvé de sommet on lève une exception
	if (iPosition == -1) 
	{
		CException EXCException(ARC_INEXISTANT);
		throw EXCException;
	}

	//Suppression de l'arc à la position trouvée
	delete ppARCSOMArcsEntrants[iPosition];

	//On décale les arcs dans la liste
	for (uiBoucleArc = iPosition; uiBoucleArc < uiSOMNombreArcsEntrants - 1; uiBoucleArc++)
	{
		ppARCSOMArcsEntrants[uiBoucleArc] = ppARCSOMArcsEntrants[uiBoucleArc + 1];
	}

	//Sauvegarde du pointeur si le realloc échoue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsEntrants;

	uiSOMNombreArcsEntrants--;

	//On désalloue le pointeur si on vient de supprimer le dernier élément
	if (uiSOMNombreArcsEntrants == 0)
	{
		free(ppARCSOMArcsEntrants);
		ppARCSOMArcsEntrants = nullptr;
	}
	else
	{
		ppARCSOMArcsEntrants = (CArc**)realloc(ppARCSOMArcsEntrants, (uiSOMNombreArcsEntrants) * sizeof(CArc*));

		//On vérifie si le realloc a bien fonctionné
		if (ppARCSOMArcsEntrants == nullptr)
		{
			free(pARCSauvegardePointeur);
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}

	}
}


/****************************************************************************************************************
***** SOMChercherArcEntrant : cherche dans la liste ppARCSOMArcsEntrants un arc possédant l'identifiant en  *****
*****						  paramètre																		*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdDestination																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant à la destination	    *****
*****************************************************************************************************************/

inline int CSommet::SOMChercherArcEntrant(unsigned int uiIdDestination)
{
	unsigned int uiBoucleArc = 0;

	//On parcourt la liste et on retourne la première position de l'identifiant trouvée
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
***** Entrée :	unsigned int uiPosition			                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : CArc																							*****
***** Entraine : La fonction renvoie l'arc à la position donnée en paramètre							  OU*****
**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
*****************************************************************************************************************/

inline CArc& CSommet::SOMLireArcSortant(unsigned int uiPosition) const
{
	//Si la position est hors de la liste on lève une exception
	if (uiPosition >= uiSOMNombreArcsSortants)
	{
		CException EXCException(POSITION_INVALIDE);
		throw EXCException;
	}

	return *ppARCSOMArcsSortants[uiPosition];
}


/****************************************************************************************************************
***** SOMAjouterArcSortant : accesseur en écriture de ppARCArcsSortants										*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestination	                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction crée un arc avec l'identifiant en paramètre et l'ajoute à la liste			    *****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

inline void CSommet::SOMAjouterArcSortant(unsigned int uiIdDestination)
{
	//Sauvegarde du pointeur si le realloc échoue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsSortants;

	//On met le pointeur à nullptr si la liste est vide
	if (uiSOMNombreArcsSortants == 0) 
	{
		ppARCSOMArcsSortants = nullptr;
	}

	//On réalloue la liste, si elle est vide alors elle sera allouée
	ppARCSOMArcsSortants = (CArc**)realloc(ppARCSOMArcsSortants, (uiSOMNombreArcsSortants + 1) * sizeof(CArc*));

	//On vérifie si le realloc a bien fonctionné
	if (ppARCSOMArcsSortants == nullptr)
	{
		free(pARCSauvegardePointeur);
		CException EXCException(MAUVAISE_INITIALISATION);
		throw EXCException;
	}

	uiSOMNombreArcsSortants++;

	//A la dernière position que l'on vient d'allouer on ajoute l'arc
	ppARCSOMArcsSortants[uiSOMNombreArcsSortants - 1] = new CArc(uiIdDestination);
}


/****************************************************************************************************************
***** SOMSupprimerArcSortant : accesseur en écriture de ppARCArcsSortants									*****
*****************************************************************************************************************
***** Entrée :	unsigned int uiIdDestination	                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction supprime de la liste l'arc avec l'identifiant en paramètre					  OU*****
**************** Exception ARC_INEXISTANT : L'identifiant de destination en paramètre ne correspond à aucun *****
**************** arc de la liste																		  OU*****
**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
*****************************************************************************************************************/

inline void CSommet::SOMSupprimerArcSortant(unsigned int uiIdDestination)
{
	int iPosition;
	unsigned int uiBoucleArc;

	//On récupère la position du sommet demandé
	iPosition = SOMChercherArcSortant(uiIdDestination);
	
	//Si la recherche n'a pas trouvé de sommet on lève une exception
	if (iPosition == -1)
	{
		CException EXCException(ARC_INEXISTANT);
		throw EXCException;
	}

	//Suppression de l'arc à la position trouvée
	delete ppARCSOMArcsSortants[iPosition];

	//On décale les arcs dans la liste
	for (uiBoucleArc = iPosition; uiBoucleArc < uiSOMNombreArcsSortants - 1; uiBoucleArc++)
	{
		ppARCSOMArcsSortants[uiBoucleArc] = ppARCSOMArcsSortants[uiBoucleArc + 1];
	}

	//Sauvegarde du pointeur si le realloc échoue
	CArc** pARCSauvegardePointeur = ppARCSOMArcsSortants;

	uiSOMNombreArcsSortants--;

	//On désalloue le pointeur si on vient de supprimer le dernier élément
	if (uiSOMNombreArcsSortants == 0)
	{
		free(ppARCSOMArcsSortants);
		ppARCSOMArcsSortants = nullptr;
	}
	else
	{
		ppARCSOMArcsSortants = (CArc**)realloc(ppARCSOMArcsSortants, (uiSOMNombreArcsSortants) * sizeof(CArc*));

		//On vérifie si le realloc a bien fonctionné
		if (ppARCSOMArcsSortants == nullptr)
		{
			free(pARCSauvegardePointeur);
			CException EXCException(MAUVAISE_INITIALISATION);
			throw EXCException;
		}
	}
}


/****************************************************************************************************************
***** SOMChercherArcSortant : cherche dans la liste ppARCSOMArcsSortants un arc possédant l'identifiant en  *****
*****						  paramètre																		*****
*****************************************************************************************************************
***** Entrée : unsigned int uiIdDestination																	*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : int																							*****
***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant à la destination	    *****
*****************************************************************************************************************/

inline int CSommet::SOMChercherArcSortant(unsigned int uiIdDestination)
{
	unsigned int uiBoucleArc = 0;

	//On parcourt la liste et on retourne la première position de l'identifiant trouvée
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
***** Entrée : Rien																							*****
***** Nécessite : Rien				                                                                        *****
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
***** Entrée : Rien																							*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int						                                                            *****
***** Entraine : La fonction renvoie la taille de la liste pcARCArcsSortants							    *****
*****************************************************************************************************************/

inline unsigned int CSommet::SOMLireNombreArcsSortants() const
{
	return uiSOMNombreArcsSortants;
}