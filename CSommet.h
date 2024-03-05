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
	***** CSommet : constructeur par d�faut de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entr�e :	Rien							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet														    *****
	*****************************************************************************************************************/
	CSommet();

	/****************************************************************************************************************
	***** CSommet : constructeur de recopie de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entr�e : CSommet SOMParam							                                                    *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet en recopiant le sommet en param�tre					  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec malloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	CSommet(CSommet & SOMParam);

	/****************************************************************************************************************
	***** CSommet : constructeur de confort de la classe CSommet												*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdParam			                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un sommet avec l'identifiant en param�tre						    *****
	*****************************************************************************************************************/
	CSommet(unsigned int uiIdParam);

	/****************************************************************************************************************
	***** CSommet : destructeur de la classe CSommet															*****
	*****************************************************************************************************************
	***** Entr�e :	Rien							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction d�salloue l'espace m�moire attribu� � un CSommet							    *****
	*****************************************************************************************************************/
	~CSommet();


	//M�thodes

	/****************************************************************************************************************
	***** SOMLireId : accesseur en lecture de uiId																*****
	*****************************************************************************************************************
	***** Entr�e :	Rien							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la valeur de l'identifiant du sommet								    *****
	*****************************************************************************************************************/
	unsigned int SOMLireId() const;

	/****************************************************************************************************************
	***** SOMModifierId : accesseur en �criture de uiId															*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdParam							                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie la valeur de l'identifiant du sommet								    *****
	*****************************************************************************************************************/
	void SOMModifierId(unsigned int uiIdParam);

	/****************************************************************************************************************
	***** SOMLireArcEntrant : accesseur en lecture de ppARCArcsEntrants											*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiPosition			                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : CArc																							*****
	***** Entraine : La fonction renvoie l'arc � la position donn�e en param�tre							  OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
	*****************************************************************************************************************/
	CArc & SOMLireArcEntrant(unsigned int uiPosition) const;

	/****************************************************************************************************************
	***** SOMAjouterArcEntrant : accesseur en �criture de ppARCArcsEntrants										*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdDestination	                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction cr�e un arc avec l'identifiant en param�tre et l'ajoute � la liste			    *****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	void SOMAjouterArcEntrant(unsigned int uiIdDestination);

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
	void SOMSupprimerArcEntrant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMChercherArcEntrant : cherche dans la liste ppARCSOMArcsEntrants un arc poss�dant l'identifiant en  *****
	*****						  param�tre																		*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdDestination																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant � la destination	    *****
	*****************************************************************************************************************/
	int SOMChercherArcEntrant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMLireArcSortant : accesseur en lecture de ppARCArcsSortants											*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiPosition			                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : CArc																							*****
	***** Entraine : La fonction renvoie l'arc � la position donn�e en param�tre							  OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
	*****************************************************************************************************************/
	CArc& SOMLireArcSortant(unsigned int uiPosition) const;

	/****************************************************************************************************************
	***** SOMAjouterArcSortant : accesseur en �criture de ppARCArcsSortants										*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdDestination	                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction cr�e un arc avec l'identifiant en param�tre et l'ajoute � la liste			    *****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	void SOMAjouterArcSortant(unsigned int uiIdDestination);

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
	void SOMSupprimerArcSortant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMChercherArcSortant : cherche dans la liste ppARCSOMArcsSortants un arc poss�dant l'identifiant en  *****
	*****						  param�tre																		*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdDestination																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un arc correspondant � la destination	    *****
	*****************************************************************************************************************/
	int SOMChercherArcSortant(unsigned int uiIdDestination);

	/****************************************************************************************************************
	***** SOMLireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants								*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la taille de la liste pcARCArcsEntrants							    *****
	*****************************************************************************************************************/
	unsigned int SOMLireNombreArcsEntrants() const;

	/****************************************************************************************************************
	***** SOMLireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants								*****
	*****************************************************************************************************************
	***** Entr�e : Rien																							*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie la taille de la liste pcARCArcsSortants							    *****
	*****************************************************************************************************************/
	unsigned int SOMLireNombreArcsSortants() const;
};


#include "CSommet.ipp"