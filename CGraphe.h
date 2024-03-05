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
	***** CGraphe : constructeur par d�faut de la classe CGraphe												*****
	*****************************************************************************************************************
	***** Entr�e :	Rien			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un graphe															*****
	*****************************************************************************************************************/
	CGraphe();

	/****************************************************************************************************************
	***** CGraphe : constructeur de recopie de la classe CGraphe												*****
	*****************************************************************************************************************
	***** Entr�e :	CGraphe GRAParam			                                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction initialise un graphe � partir d'un autre graphe								*****
	*****************************************************************************************************************/
	CGraphe(CGraphe& GRAParam);

	/****************************************************************************************************************
	***** CGraphe : destructeur de la classe CGraphe															*****
	*****************************************************************************************************************
	***** Entr�e :	Rien																						*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction d�salloue l'espace m�moire attribu� � un CGraphe							    *****
	*****************************************************************************************************************/
	~CGraphe();



	//Accesseurs des sommets

	/****************************************************************************************************************
	***** SOMLireId : accesseur en lecture de uiNombreSommets													*****
	*****************************************************************************************************************
	***** Entr�e :	Rien																						*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre de sommets du graphe										    *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreSommets() const;

	/****************************************************************************************************************
	***** GRAAjouterSommet : ajoute un sommet au graphe															*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiant																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : Ajoute un sommet correspondant � l'identifiant sp�cifi� en param�tre dans le graphe	  OU*****
	**************** Exception IDENTIFIANT_DOUBLE : L'identifiant sp�cifi� existe d�ja dans le graphe			*****
	*****************************************************************************************************************/
	void GRAAjouterSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRASupprimerSommet : supprime un sommet du graphe														*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiant																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : Supprime le sommet correspondant � l'identifiant sp�cifi� en param�tre					  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant sp�cifi� n'existe pas dans le graphe			*****
	*****************************************************************************************************************/
	void GRASupprimerSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRAChercherSommet : cherche dans la liste ppSOMGRAListeSommets un sommet poss�dant l'identifiant en	*****
	*****					  param�tre																			*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdentifiant																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : int																							*****
	***** Entraine : La fonction renvoie la position dans la liste d'un sommet correspondant � l'identifiant	*****
	*****************************************************************************************************************/
	int GRAChercherSommet(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireIdentifiantSommet : lit l'identifiant du sommet dans la liste � la position en param�tre		*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiPosition																		*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction retourne l'identifiant du sommet avec la position sp�cifi�e en param�tre	  OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireIdentifiantSommet(unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRAModifierIdentifiantSommet : modifie l'identifiant d'un sommet du graphe							*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant								*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien																							*****
	***** Entraine : La fonction modifie l'identifiant du sommet avec l'identifiant sp�cifi� en param�tre	  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
	**************** Exception IDENTIFIANT_DOUBLE : Le nouvel identifiant sp�cifi� existe d�j� dans le graphe	*****
	*****************************************************************************************************************/
	void GRAModifierIdentifiantSommet(unsigned int uiIdentifiant, unsigned int uiNouvelIdentifiant);


	//Accesseurs des arcs

	/****************************************************************************************************************
	***** GRAAjouterArc : fonction permettant d'ajouter un arc entre deux sommets du graphe						*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction ajoute un arc entre deux sommets du graphe									  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
	**************** sommet																					  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	void GRAAjouterArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive);

	/****************************************************************************************************************
	***** GRASupprimerArc : fonction permettant de supprimer un arc entre deux sommets du graphe				*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive							*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : void								                                                            *****
	***** Entraine : La fonction supprime un arc entre deux sommets du graphe								  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
	**************** sommet																					  OU*****
	**************** Exception ARC_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun arc	  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	void GRASupprimerArc(unsigned int uiIdentifiantDepart, unsigned int uiIdentifiantArrive);

	/****************************************************************************************************************
	***** GRALireNombreArcsEntrants : accesseur en lecture de uiNombreArcsEntrants du sommet en param�tre		*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdentifiant																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre d'arcs entrants du sommet en param�tre					    *****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet   *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreArcsEntrants(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireNombreArcsSortants : accesseur en lecture de uiNombreArcsSortants du sommet en param�tre		*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdentifiant																	*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int						                                                            *****
	***** Entraine : La fonction renvoie le nombre d'arcs sortants du sommet en param�tre						*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet   *****
	*****************************************************************************************************************/
	unsigned int GRALireNombreArcsSortants(unsigned int uiIdentifiant);

	/****************************************************************************************************************
	***** GRALireArcEntrant : accesseur en lecture de ppARCArcsEntrants du sommet en param�tre					*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'identifiant de destination de l'arc � la position donn�e en			*****
	***** param�tre dans la liste d'arcs entrants du sommet sp�cifi� en param�tre							  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireArcEntrant(unsigned int uiIdentifiant, unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRALireArcSortant : accesseur en lecture de ppARCArcsSortants	du sommet en param�tre					*****
	*****************************************************************************************************************
	***** Entr�e : unsigned int uiIdentifiant, unsigned int uiPosition			                                *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : unsigned int																					*****
	***** Entraine : La fonction renvoie l'identifiant de destination de l'arc � la position donn�e en			*****
	***** param�tre dans la liste d'arcs sortants du sommet sp�cifi� en param�tre							  OU*****
	**************** Exception SOMMET_INEXISTANT : L'identifiant en param�tre ne correspondent � aucun sommet OU*****
	**************** Exception POSITION_INVALIDE : La position sp�cif�e est en dehors de la liste				*****
	*****************************************************************************************************************/
	unsigned int GRALireArcSortant(unsigned int uiIdentifiant, unsigned int uiPosition);

	/****************************************************************************************************************
	***** GRAInverserArc : fonction permettant d'inverser le sens d'un arc du graphe							*****
	*****************************************************************************************************************
	***** Entr�e :	unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel			*****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : Rien								                                                            *****
	***** Entraine : La fonction inverser le sens d'un arc du graphe										  OU*****
	**************** Exception SOMMET_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun		*****
	**************** sommet																					  OU*****
	**************** Exception ARC_INEXISTANT : Les identifiants en param�tres ne correspondent � aucun arc	  OU*****
	**************** Exception MAUVAISE_INITIALISATION : L'initialisation avec realloc n'a pas fonctionn�		*****
	*****************************************************************************************************************/
	void GRAInverserArc(unsigned int uiIdentifiantDepartOriginel, unsigned int uiIdentifiantArriveOriginel);



	/****************************************************************************************************************
	***** GRAAfficherGraphe : fonction permettant l'affichage d'un graphe sur le terminal						*****
	*****************************************************************************************************************
	***** Entr�e :	Rien							                                                            *****
	***** N�cessite : Rien				                                                                        *****
	***** Sortie : void																							*****
	***** Entraine : La fonction affiche un graphe sur le terminal											  OU*****
	**************** Exception POSITION_INVALIDE : exception recontr�e dans la m�thode SOMLireArcSortant		*****
	*****************************************************************************************************************/
	void GRAAfficherGraphe();
};

#include "CGraphe.ipp"