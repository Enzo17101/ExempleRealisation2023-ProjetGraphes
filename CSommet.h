#pragma once


#include "CArc.h"
#include "CException.h"
#include <cstdlib>

class CSommet
{
private:
	//Attributs

	//identifiant du sommet
	unsigned int uiSOMId;

	//listes des arcs du sommet
	CArc** ppARCSOMArcsEntrants;
	CArc** ppARCSOMArcsSortants;

	//tailles des listes des arcs du sommets
	unsigned int uiSOMNombreArcsEntrants;
	unsigned int uiSOMNombreArcsSortants;

public:
	//Constructeurs et destructeur

	/****************************************************************************************************************
	***** CSommet : constructeur par défaut de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entrée :	Rien							                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet														    *****
	*****************************************************************************************************************/
	CSommet();

	/****************************************************************************************************************
	***** CSommet : constructeur de recopie de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entrée : CSommet SOMParam							                                                    *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet en recopiant le sommet en paramètre					  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec malloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	CSommet(CSommet & SOMParam);

	/****************************************************************************************************************
	***** CSommet : constructeur de confort de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdParam			                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet avec l'identifiant en paramètre						    *****
	*****************************************************************************************************************/
	CSommet(unsigned int uiIdParam);

	/****************************************************************************************************************
	***** CSommet : destructeur de la classe CSommet															*****
	*****************************************************************************************************************
	***** Entrée :	Rien							                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction désalloue l'espace mémoire attribué à un CSommet							    *****
	*****************************************************************************************************************/
	~CSommet();


	//Méthodes

	/****************************************************************************************************************
	***** SOMLireId : accesseur en lecture de uiId																*****
	*****************************************************************************************************************
	***** Entrée :	Rien							                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la valeur de l'identifiant du sommet								    *****
	*****************************************************************************************************************/
	unsigned int SOMLireId() const;

	/****************************************************************************************************************
	***** SOMModifierId : accesseur en écriture de uiId															*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdParam							                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie la valeur de l'identifiant du sommet								    *****
	*****************************************************************************************************************/
	void SOMModifierId(unsigned int uiIdParam);

	/****************************************************************************************************************
	***** SOMLireArcEntrant : accesseur en lecture de ppARCArcsEntrants											*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiPosition			                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : CArc																							*****
	***** Entraine : La fonction renvoie l'arc à la position donnée en paramètre							  OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
	*****************************************************************************************************************/
	CArc & SOMLireArcEntrant(unsigned int uiPosition) const;

	/****************************************************************************************************************
	***** SOMAjouterArcEntrant : accesseur en écriture de ppARCArcsEntrants										*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdDestination	                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction crée un arc avec l'identifiant en paramètre et l'ajoute à la liste			    *****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	void SOMAjouterArcEntrant(unsigned int uiIdDestination);

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
	void SOMSupprimerArcEntrant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMChercherArcEntrant : cherche dans la liste ppARCSOMArcsEntrants un arc possédant l'identifiant en  *****
	*****						  paramètre																		*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdDestination																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant à la destination	    *****
	*****************************************************************************************************************/
	int SOMChercherArcEntrant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMLireArcSortant : accesseur en lecture de ppARCArcsSortants											*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiPosition			                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : CArc																							*****
	***** Entraine : La fonction renvoie l'arc à la position donnée en paramètre							  OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
	*****************************************************************************************************************/
	CArc& SOMLireArcSortant(unsigned int uiPosition) const;

	/****************************************************************************************************************
	***** SOMAjouterArcSortant : accesseur en écriture de ppARCArcsSortants										*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdDestination	                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction crée un arc avec l'identifiant en paramètre et l'ajoute à la liste			    *****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	void SOMAjouterArcSortant(unsigned int uiIdDestination);

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
	void SOMSupprimerArcSortant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMChercherArcSortant : cherche dans la liste ppARCSOMArcsSortants un arc possédant l'identifiant en  *****
	*****						  paramètre																		*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdDestination																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant à la destination	    *****
	*****************************************************************************************************************/
	int SOMChercherArcSortant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMLireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants								*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la taille de la liste pcARCArcsEntrants							    *****
	*****************************************************************************************************************/
	unsigned int SOMLireNombreArcsEntrants() const;

	/****************************************************************************************************************
	***** SOMLireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants								*****
	*****************************************************************************************************************
	***** Entrée : Rien																							*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la taille de la liste pcARCArcsSortants							    *****
	*****************************************************************************************************************/
	unsigned int SOMLireNombreArcsSortants() const;
};


#include "CSommet.ipp"