#pragma once



#include "CException.h"
#include "CSommet.h"

class CGraphe
{

private :
	//Attributs
	unsigned int uiGRANombreSommets;
	CSommet** ppSOMGRAListeSommets;

public:
	/****************************************************************************************************************
	***** CGraphe : constructeur par défaut de la classe CGraphe												*****
	*****************************************************************************************************************
	***** Entrée :	Rien			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un graphe															*****
	*****************************************************************************************************************/
	CGraphe();

	/****************************************************************************************************************
	***** CGraphe : constructeur de recopie de la classe CGraphe												*****
	*****************************************************************************************************************
	***** Entrée :	CGraphe GRAParam			                                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un graphe à partir d'un autre graphe								*****
	*****************************************************************************************************************/
	CGraphe(CGraphe& GRAParam);

	/****************************************************************************************************************
	***** CGraphe : destructeur de la classe CGraphe															*****
	*****************************************************************************************************************
	***** Entrée :	Rien																						*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction désalloue l'espace mémoire attribué à un CGraphe							    *****
	*****************************************************************************************************************/
	~CGraphe();



	//Accesseurs des sommets

	/****************************************************************************************************************
	***** SOMLireId : accesseur en lecture de uiNombreSommets													*****
	*****************************************************************************************************************
	***** Entrée :	Rien																						*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre de sommets du graphe										    *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreSommets() const;

	/****************************************************************************************************************
	***** GRAAjouterSommet : ajoute un sommet au graphe															*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiant																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : Ajoute un sommet correspondant à l'identifiant spécifié en paramètre dans le graphe	  OU*****
	**************** Exception IDENTIFIANT_DOUBLE : L'identifiant spécifié existe déja dans le graphe			*****
	*****************************************************************************************************************/
	void GRAAjouterSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRASupprimerSommet : supprime un sommet du graphe														*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiant																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : Supprime le sommet correspondant à l'identifiant spécifié en paramètre					  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant spécifié n'existe pas dans le graphe			*****
	*****************************************************************************************************************/
	void GRASupprimerSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRAChercherSommet : cherche dans la liste ppSOMGRAListeSommets un sommet possédant l'identifiant en	*****
	*****					  paramètre																			*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdentifiant																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un sommet correspondant à l'identifiant	*****
	*****************************************************************************************************************/
	int GRAChercherSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireIdentifiantSommet : lit l'identifiant du sommet dans la liste à la position en paramètre		*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiPosition																		*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction retourne l'identifiant du sommet avec la position spécifiée en paramètre	  OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireIdentifiantSommet(unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRAModifierIdentifiantSommet : modifie l'identifiant d'un sommet du graphe							*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant								*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie l'identifiant du sommet avec l'identifiant spécifié en paramètre	  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
	**************** Exception IDENTIFIANT_DOUBLE : Le nouvel identifiant spécifié existe déjà dans le graphe	*****
	*****************************************************************************************************************/
	void GRAModifierIdentifiantSommet(unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant);


	//Accesseurs des arcs

	/****************************************************************************************************************
	***** GRAAjouterArc : fonction permettant d'ajouter un arc entre deux sommets du graphe						*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction ajoute un arc entre deux sommets du graphe									  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
	**************** sommet																					  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	void GRAAjouterArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive);

	/****************************************************************************************************************
	***** GRASupprimerArc : fonction permettant de supprimer un arc entre deux sommets du graphe				*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : void								                                                            *****
	***** Entraine : La fonction supprime un arc entre deux sommets du graphe								  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
	**************** sommet																					  OU*****
	**************** Exception ARC_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun arc	  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	void GRASupprimerArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive);

	/****************************************************************************************************************
	***** GRALireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants du sommet en paramètre		*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdentifiant																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre d'arcs entrants du sommet en paramètre					    *****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet   *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreArcsEntrants(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants du sommet en paramètre		*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdentifiant																	*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre d'arcs sortants du sommet en paramètre						*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet   *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreArcsSortants(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireArcEntrant : accesseur en lecture de ppARCArcsEntrants du sommet en paramètre					*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'identifiant de destination de l'arc à la position donnée en			*****
	***** paramètre dans la liste d'arcs entrants du sommet spécifié en paramètre							  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireArcEntrant(unsigned int uiIdentifiant, unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRALireArcSortant : accesseur en lecture de ppARCArcsSortants	du sommet en paramètre					*****
	*****************************************************************************************************************
	***** Entrée : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'identifiant de destination de l'arc à la position donnée en			*****
	***** paramètre dans la liste d'arcs sortants du sommet spécifié en paramètre							  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en paramètre ne correspondent à aucun sommet OU*****
	**************** Exception POSITION_INVALIDE : La position spécifée est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireArcSortant(unsigned int uiIdentifiant, unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRAInverserArc : fonction permettant d'inverser le sens d'un arc du graphe							*****
	*****************************************************************************************************************
	***** Entrée :	unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel			*****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction inverser le sens d'un arc du graphe										  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun		*****
	**************** sommet																					  OU*****
	**************** Exception ARC_INEXISTANT : Les identifiants en paramètres ne correspondent à aucun arc	  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionné		*****
	*****************************************************************************************************************/
	void GRAInverserArc(unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel);



	/****************************************************************************************************************
	***** GRAAfficherGraphe : fonction permettant l'affichage d'un graphe sur le terminal						*****
	*****************************************************************************************************************
	***** Entrée :	Rien							                                                            *****
	***** Nécessite : Rien				                                                                        *****
	***** Sortie : void																							*****
	***** Entraine : La fonction affiche un graphe sur le terminal											  OU*****
	**************** Exception POSITION_INVALIDE : exception recontrée dans la méthode SOMLireArcSortant		*****
	*****************************************************************************************************************/
	void GRAAfficherGraphe();
};

#include "CGraphe.ipp"