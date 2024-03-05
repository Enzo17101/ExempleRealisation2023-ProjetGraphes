#include "CAnalyseurSyntaxique.h"

/****************************************************************************************************************
***** CAnalyseurSyntaxique : constructeur par d�faut de la classe CAnalyseurSyntaxique						*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	CAnalyseurSyntaxique ANSParam			                                                    *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique � partir d'un autre analyseur syntaxique	*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::CAnalyseurSyntaxique(CAnalyseurSyntaxique& ANSParam)
{
	//Longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongueurChemin = strlen(ANSParam.pcANSChemin) + 1;

	pcANSChemin = new char[uiLongueurChemin];

	//Copie de la chaine ANSParam.pcANSChemin dans pcANSChemin
	strcpy_s(pcANSChemin, uiLongueurChemin, ANSParam.pcANSChemin);
}


/****************************************************************************************************************
***** CAnalyseurSyntaxique : constructeur de confort de la classe CAnalyseurSyntaxique						*****
*****************************************************************************************************************
***** Entr�e : char * pcANSCheminFichier			                                                        *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique � partir d'une chaine de caract�re			*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::CAnalyseurSyntaxique(const char* pcANSCheminFichier)
{
	//Longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongueurChemin = strlen(pcANSCheminFichier) + 1;

	pcANSChemin = new char[uiLongueurChemin];

	//Copie de la chaine pcANSChemin dans pcANSChemin
	strcpy_s(pcANSChemin, uiLongueurChemin, pcANSCheminFichier);
}


/****************************************************************************************************************
***** ~CAnalyseurSyntaxique : destructeur de la classe CAnalyseurSyntaxique									*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction d�salloue l'espace m�moire allou� � un CAnalyseurSyntaxique					*****
*****************************************************************************************************************/

CAnalyseurSyntaxique::~CAnalyseurSyntaxique()
{
	delete pcANSChemin;
}


/****************************************************************************************************************
***** ANSGenererGraphe : Fonction permettant de cr�er un graphe � partir d'un fichier texte 				*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : CGraphe							                                                            *****
***** Entraine : la fonction renvoie le graphe initialis� � partir du fichier correspondant au chemin de	*****
*****			 CAnalyseurSyntaxique																	  OU*****
**************** Exception CHEMIN_INVALIDE : Le fichier correspondant au chemin sp�cifi� n'a pas pus �tre	*****
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

	//Graphe retourn� en fin de fonction
	CGraphe* pGRAGraphe = new CGraphe();

	//Chaine utilis�e pour parcourir le fichier
	char pcLigne[255];

	//Cha�nes permettant de v�rifier la bonne syntaxe des balises
	
	char ppcBalises[8][32] = { "NBSommets", "NBArcs", "Sommets=[", "Numero", "Arcs=[" , "Debut", "Fin" , "]"};

	//Sous chaines permettant de v�rifier la bonne syntaxe des balises "NbSommets=", "NbArcs=", "Numero=", "Debut=" ou "Fin="
	char* pcBalise;
	//Variable de boucle utilis�e pour :
	//	- Parcours de la liste des sommets dans le fichier
	unsigned int uiBoucleSommet;
	//	- Parcours de la liste des arcs dans le fichier
	unsigned int uiBoucleArc;

	//Variable utilis�e pour stocker le nombre de sommets et d'arcs du graphe
	//ainsi que les num�ros de sommets, et les sommets de d�but et fin d'arc lus dans le fichier
	unsigned int uiNbSommets;
	unsigned int uiNbArcs;
	unsigned int uiNumero;
	unsigned int uiDebutArc;
	unsigned int uiFinArc;


	//V�rification de la premi�re ligne
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
	

	//V�rification de la deuxi�me ligne
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


	//V�rification de la troisi�me ligne
	IFSFichier >> pcLigne;

	//pANLTemp->ANLModifierChaine(pcLigne);

	if (strcmp(pcLigne, ppcBalises[2]) != 0)
	{
		//cout << "Liste sommets KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	//cout << "Liste sommets OK\n";

	
	//V�rification, lecture et ajout des sommets dans le graphe
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
	
	//V�rification de la derni�re ligne
	IFSFichier >> pcLigne;

	pANLTemp->ANLModifierChaine(pcLigne);


	if (strcmp(pcLigne, ppcBalises[7]) != 0)
	{
		//cout << "Fin liste sommets KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}

	//cout << "Fin liste sommets OK\n";


	//V�rification de la troisi�me ligne
	IFSFichier >> pcLigne;

	pANLTemp->ANLModifierChaine(pcLigne);
	if (strcmp(pcLigne, ppcBalises[4]))
	{
		//cout << "Liste arc KO\n";
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}
	//cout << "Liste arc OK\n";

	
	//V�rification, lecture et ajout des arcs dans le graphe

	for (uiBoucleArc = 0; uiBoucleArc < uiNbArcs; uiBoucleArc++)
	{
		//D�but de l'arc
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

		//V�rification de la virgule en fin de chaine
		//L'espace �tant un s�parateur le dernier caract�re de pcLigne est en effet cens� �tre une virgule
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
	
	//V�rification de la derni�re ligne
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