#include "CAnalyseurLexical.h"


/****************************************************************************************************************
***** CAnalyseurLexical : constructeur par défaut de la classe CAnalyseurLexical							*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur lexical												*****
*****************************************************************************************************************/

CAnalyseurLexical::CAnalyseurLexical()
{
	pcANLChaine = nullptr;
}


/****************************************************************************************************************
***** CAnalyseurLexical : constructeur de recopie de la classe CAnalyseurLexical							*****
*****************************************************************************************************************
***** Entrée :	CAnalyseurLexical ANLParam			                                                        *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur lexical à partir d'un autre analyseur lexical			*****
*****************************************************************************************************************/

CAnalyseurLexical::CAnalyseurLexical(CAnalyseurLexical& ANLParam)
{
	//longueur du chemin en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongeurChaine = strlen(ANLParam.pcANLChaine) + 1;

	//on crée le chemin
	pcANLChaine = new char[uiLongeurChaine];

	//copie de la chaine ITEParam.pcChemin dans pcChemin
	strcpy_s(pcANLChaine, uiLongeurChaine, ANLParam.pcANLChaine);
}


/****************************************************************************************************************
***** CAnalyseurLexical : constructeur de confort de la classe CAnalyseurLexical							*****
*****************************************************************************************************************
***** Entrée :	char * pcChaineParam			                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur lexical à partir d'une chaine de caractère				*****
*****************************************************************************************************************/

CAnalyseurLexical::CAnalyseurLexical(const char* pcChaineParam)
{
	//longueur de la chapine en paramètre en comptant le caractère de fin de chaine
	unsigned int uiLongeurChaine = strlen(pcChaineParam) + 1;

	pcANLChaine = new char[strlen(pcChaineParam) + 1];

	//copie de la chaine pcCheminFichier dans pcChemin
	strcpy_s(pcANLChaine, uiLongeurChaine, pcChaineParam);
}


/****************************************************************************************************************
***** ~CAnalyseurLexical : destructeur de la classe CAnalyseurLexical										*****
*****************************************************************************************************************
***** Entrée :	Rien			                                                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction désalloue l'espace mémoire attribué à l'analyseur lexical						*****
*****************************************************************************************************************/

CAnalyseurLexical::~CAnalyseurLexical()
{
	delete pcANLChaine;
}


/****************************************************************************************************************
***** ANLLireBalise : fonction renvoyant, s'il en trouve une, la balise lue dans une chaine de caractère de	*****
*****				  la forme <Balise>=<reste de la chaîne>												*****
*****************************************************************************************************************
***** Entrée :	char * pcChaine	                                                                            *****
***** Nécessite : La désallocation de la chaine retournée avec delete										*****
***** Sortie : char *							                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique à partir d'une chaine de caractère		  OU*****
**************** Exception BALISE_INVALIDE : Le caractère de délimitation de la balise (en l'occurence		*****
**************** le caractère "=" n'a pas été trouvé dans la chaîne											*****
*****************************************************************************************************************/

char* CAnalyseurLexical::ANLLireBalise()
{
	const char* pcPositionEgal = strchr(pcANLChaine, '=');
	if (pcPositionEgal == NULL)
	{
		CException EXCException(SYNTAXE_INVALIDE);
		throw EXCException;
	}

	//calcul de la longueur de la balise
	unsigned int uiLongueurBalise = pcPositionEgal - pcANLChaine;

	char* pcBalise = new char[uiLongueurBalise + 2];
	pcBalise[uiLongueurBalise + 1] = '\0';

	//copie de la balise à retourner ensuite
	strncpy_s(pcBalise, uiLongueurBalise + 1, pcANLChaine, uiLongueurBalise);

	return pcBalise;
}


/****************************************************************************************************************
***** ANLLireNaturel : fonction renvoyant l'entier naturel lu à la position donnée d'une chaine				*****
*****************************************************************************************************************
***** Entrée :unsigned int uiPositionNaturel					                                            *****
***** Nécessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'entier naturel lu												  OU*****
**************** Exception POSITION_CHAINE_INVALIDE : La position spécifiée est en dehors de la chaîne	  OU*****
**************** Exception ENTIER_INVALIDE : Un des caractère lu ne correspond pas à un chiffre			    *****
*****************************************************************************************************************/

unsigned int CAnalyseurLexical::ANLLireNaturel(unsigned int uiPositionNaturel)
{
	//Variables pour parcourir la chaine caractères par caractères, et en extraire les chiffres
	unsigned int uiBoucle = 0;
	unsigned int uiNaturel = 0;
	unsigned int uiDigit;


	//On aura donc un maximum de 254 caractères pour l'entier saisi dans le fichier
	char pcNaturel[255];

	if (strlen(pcANLChaine) <= uiPositionNaturel)
	{
		CException EXCException(POSITION_CHAINE_INVALIDE);
		throw EXCException;
	}

	_memccpy(pcNaturel, pcANLChaine + uiPositionNaturel, '\0', 255);

	//Extraction des entiers de la chaîne
	while (pcNaturel[uiBoucle] != '\0')
	{
		uiDigit = (int)pcNaturel[uiBoucle] - 48;
		//Vérification de la syntaxe de la chaîne
		if (uiDigit < 0 || uiDigit > 9)
		{
			CException EXCException(SYNTAXE_INVALIDE);
			throw EXCException;
		}

		uiNaturel = uiNaturel * 10 + uiDigit;
		uiBoucle++;
	}

	return uiNaturel;
}