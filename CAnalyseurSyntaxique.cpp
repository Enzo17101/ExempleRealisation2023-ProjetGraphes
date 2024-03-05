#include "CAnalyseurSyntaxique.h"

/****************************************************************************************************************
***** CAnalyseurSyntaxique : constructeur par défaut de la classe CAnalyseurSyntaxique						*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique												*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::CAnalyseurSyntaxique()
{
	pcANSChemin = nullptr;
}


/****************************************************************************************************************
***** CAnalyseurSyntaxique : constructeur de recopie de la classe CAnalyseurSyntaxique						*****
*****************************************************************************************************************
***** Entrée :	CAnalyseurSyntaxique ANSParam			                                                    *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique à partir d'un autre analyseur syntaxique	*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::CAnalyseurSyntaxique(CAnalyseurSyntaxique& ANSParam)
{
	//Longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongueurChemin = strlen(ANSParam.pcANSChemin) + 1;

	pcANSChemin = new char[uiLongueurChemin];

	//Copie de la chaine ANSParam.pcANSChemin dans pcANSChemin
	strcpy_s(pcANSChemin, uiLongueurChemin, ANSParam.pcANSChemin);
}


/****************************************************************************************************************
***** CAnalyseurSyntaxique : constructeur de confort de la classe CAnalyseurSyntaxique						*****
*****************************************************************************************************************
***** Entrée : char * pcANSCheminFichier			                                                        *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique à partir d'une chaine de caractère			*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::CAnalyseurSyntaxique(const char* pcANSCheminFichier)
{
	//Longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcANSCheminFichier) + 1;

	pcANSChemin = new char[uiLongueurChemin];

	//Copie de la chaine pcANSChemin dans pcANSChemin
	strcpy_s(pcANSChemin, uiLongueurChemin, pcANSCheminFichier);
}


/****************************************************************************************************************
***** ~CAnalyseurSyntaxique : destructeur de la classe CAnalyseurSyntaxique									*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction désalloue l'espace mémoire alloué à un CAnalyseurSyntaxique					*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::~CAnalyseurSyntaxique()
{
	delete pcANSChemin;
}


/****************************************************************************************************************
***** ANSGenererGraphe : Fonction permettant de créer un graphe à partir d'un fichier texte 				*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : CGraphe							                                                            *****
***** Entraine : la fonction renvoie le graphe initialisé à partir du fichier correspondant au chemin de	*****
*****			 CAnalyseurSyntaxique																	  OU*****
**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin spécifié n'a pas pus être	*****
**************** ouvert																					  OU*****
**************** Exception SYNTAXE_INVALIDE : La syntaxe du fichier texte ne respecte pas le format attendu	*****
*****************************************************************************************************************/

CGraphe& CAnalyseurSyntaxique::ANSGenererGraphe()
{
	ifstream IFSFichier(pcANSChemin);

	//Teste si le fichier est bien ouvert
	if (!IFSFichier)
	{
		CException EXCException(CHEMIN_INVALIDE);
		throw EXCException;
	}

	//Graphe retourné en fin de fonction
	CGraphe* pGRAGraphe = new CGraphe();

	//Chaine utilisée pour parcourir le fichier
	char pcLigne[255];

	//Chaînes permettant de vérifier la bonne syntaxe des balises
	
	char ppcBalises[8][32] = { "NBSommets", "NBArcs", "Sommets=[", "Numero", "Arcs=[" , "Debut", "Fin" , "]"};

	//Sous chaines permettant de vérifier la bonne syntaxe des balises "NbSommets=", "NbArcs=", "Numero=", "Debut=" ou "Fin="
	char* pcBalise;
	//Variable de boucle utilisée pour :
	//	- Parcours de la liste des sommets dans le fichier
	unsigned int uiBoucleSommet;
	//	- Parcours de la liste des arcs dans le fichier
	unsigned int uiBoucleArc;

	//Variable utilisée pour stocker le nombre de sommets et d'arcs du graphe
	//ainsi que les numéros de sommets, et les sommets de début et fin d'arc lus dans le fichier
	unsigned int uiNbSommets;
	unsigned int uiNbArcs;
	unsigned int uiNumero;
	unsigned int uiDebutArc;
	unsigned int uiFinArc;


	//Vérification de la première ligne
	IFSFichier >> pcLigne;

	CAnalyseurLexical * pANLTemp = new CAnalyseurLexical(pcLigne);
	
	pcBalise = pANLTemp->ANLLireBalise();
	
	if (strcmp(pcBalise, ppcBalises[0]) != 0)
	{
		//cout << "Nombre sommets KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	delete pcBalise;
	
	//Lecture de l'entier
	pANLTemp->ANLModifierChaine(pcLigne);

	uiNbSommets = pANLTemp->ANLLireNaturel(strlen(ppcBalises[0]) + 1);
	
	//cout << "Nombre sommets OK\n" << uiNbSommets << '\n';
	

	//Vérification de la deuxième ligne
	IFSFichier >> pcLigne;

	pANLTemp->ANLModifierChaine(pcLigne);

	pcBalise = pANLTemp->ANLLireBalise();

	if (strcmp(pcBalise, ppcBalises[1]) != 0)
	{
		//cout << "Nombre arcs KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	delete pcBalise;

	//Lecture de l'entier
	pANLTemp->ANLModifierChaine(pcLigne);

	uiNbArcs = pANLTemp->ANLLireNaturel(strlen(ppcBalises[1]) + 1);

	//cout << "Nombre arcs OK\n" << uiNbArcs << '\n';


	//Vérification de la troisième ligne
	IFSFichier >> pcLigne;

	//pANLTemp->ANLModifierChaine(pcLigne);

	if (strcmp(pcLigne, ppcBalises[2]) != 0)
	{
		//cout << "Liste sommets KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	//cout << "Liste sommets OK\n";

	
	//Vérification, lecture et ajout des sommets dans le graphe
	for (uiBoucleSommet = 0; uiBoucleSommet < uiNbSommets; uiBoucleSommet++)
	{
		IFSFichier >> pcLigne;

		pANLTemp->ANLModifierChaine(pcLigne);

		pcBalise = pANLTemp->ANLLireBalise();

		if (strcmp(pcBalise, ppcBalises[3]) != 0)
		{
			//cout << "Numero KO\n";
			CException EXCException(SYNTAXE_INVALIDE);
			throw EXCException;
		}
		delete pcBalise;

		//Lecture de l'entier

		//Lecture de l'entier
		pANLTemp->ANLModifierChaine(pcLigne);

		uiNumero = pANLTemp->ANLLireNaturel(strlen(ppcBalises[3]) + 1);


		//cout << "Numero OK\n" << uiNumero << '\n';

		pGRAGraphe->GRAAjouterSommet(uiNumero);
	}
	
	//Vérification de la dernière ligne
	IFSFichier >> pcLigne;

	pANLTemp->ANLModifierChaine(pcLigne);


	if (strcmp(pcLigne, ppcBalises[7]) != 0)
	{
		//cout << "Fin liste sommets KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}

	//cout << "Fin liste sommets OK\n";


	//Vérification de la troisième ligne
	IFSFichier >> pcLigne;

	pANLTemp->ANLModifierChaine(pcLigne);
	if (strcmp(pcLigne, ppcBalises[4]))
	{
		//cout << "Liste arc KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	//cout << "Liste arc OK\n";

	
	//Vérification, lecture et ajout des arcs dans le graphe

	for (uiBoucleArc = 0; uiBoucleArc < uiNbArcs; uiBoucleArc++)
	{
		//Début de l'arc
		IFSFichier >> pcLigne;

		pANLTemp->ANLModifierChaine(pcLigne);

		pcBalise = pANLTemp->ANLLireBalise();

		if (strcmp(pcBalise, ppcBalises[5]) != 0)
		{
			//cout << "Debut arc KO\n";
			CException EXCException(SYNTAXE_INVALIDE);
			throw EXCException;
		}
		delete pcBalise;

		//cout << "Debut arc OK\n";

		//Lecture de l'entier

		//Vérification de la virgule en fin de chaine
		//L'espace étant un séparateur le dernier caractère de pcLigne est en effet censé être une virgule
		if (pcLigne[strlen(pcLigne) - 1] != ',')
		{
			//cout << "Virgule KO\n";

			CException EXCException(SYNTAXE_INVALIDE);
			throw EXCException;
		}

		//cout << "Virgule OK\n";

		pcLigne[strlen(pcLigne) - 1] = '\0';

		pANLTemp->ANLModifierChaine(pcLigne);

		uiDebutArc = pANLTemp->ANLLireNaturel(strlen(ppcBalises[5]) + 1);

		//Fin de l'arc
		IFSFichier >> pcLigne;

		pANLTemp->ANLModifierChaine(pcLigne);

		pcBalise = pANLTemp->ANLLireBalise();

		if (strcmp(pcBalise, ppcBalises[6]) != 0)
		{
			//cout << "Fin arc KO\n";

			CException EXCException(SYNTAXE_INVALIDE);
			throw EXCException;
		}
		delete pcBalise;

		//cout << "Fin arc OK\n";

		//Lecture de l'entier
		pANLTemp->ANLModifierChaine(pcLigne);

		uiFinArc = pANLTemp->ANLLireNaturel(strlen(ppcBalises[6]) + 1);

		//cout << "Debut arc = " << uiDebutArc << " ; Fin Arc = " << uiFinArc << '\n';

		//Ajout de l'arc dans le graphe
		pGRAGraphe->GRAAjouterArc(uiDebutArc, uiFinArc);
	}
	
	//Vérification de la dernière ligne
	IFSFichier >> pcLigne;


	if (strcmp(pcLigne, ppcBalises[7]))
	{
		//cout << "Fin liste arcs KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}

	delete pANLTemp;

	//cout << "Fin liste arcs OK\n";
	
	return *pGRAGraphe;
}