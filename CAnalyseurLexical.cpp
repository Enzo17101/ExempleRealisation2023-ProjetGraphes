#include "CAnalyseurLexical.h"


/****************************************************************************************************************
***** CAnalyseurLexical : constructeur par d�faut de la classe CAnalyseurLexical							*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
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
***** Entr�e :	CAnalyseurLexical ANLParam			                                                        *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur lexical � partir d'un autre analyseur lexical			*****
*****************************************************************************************************************/

CAnalyseurLexical::CAnalyseurLexical(CAnalyseurLexical& ANLParam)
{
	//longueur du chemin en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongeurChaine = strlen(ANLParam.pcANLChaine) + 1;

	//on cr�e le chemin
	pcANLChaine = new char[uiLongeurChaine];

	//copie de la chaine ITEParam.pcChemin dans pcChemin
	strcpy_s(pcANLChaine, uiLongeurChaine, ANLParam.pcANLChaine);
}


/****************************************************************************************************************
***** CAnalyseurLexical : constructeur de confort de la classe CAnalyseurLexical							*****
*****************************************************************************************************************
***** Entr�e :	char * pcChaineParam			                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction initialise un analyseur lexical � partir d'une chaine de caract�re				*****
*****************************************************************************************************************/

CAnalyseurLexical::CAnalyseurLexical(const char* pcChaineParam)
{
	//longueur de la chapine en param�tre en comptant le caract�re de fin de chaine
	unsigned int uiLongeurChaine = strlen(pcChaineParam) + 1;

	pcANLChaine = new char[strlen(pcChaineParam) + 1];

	//copie de la chaine pcCheminFichier dans pcChemin
	strcpy_s(pcANLChaine, uiLongeurChaine, pcChaineParam);
}


/****************************************************************************************************************
***** ~CAnalyseurLexical : destructeur de la classe CAnalyseurLexical										*****
*****************************************************************************************************************
***** Entr�e :	Rien			                                                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : Rien								                                                            *****
***** Entraine : La fonction d�salloue l'espace m�moire attribu� � l'analyseur lexical						*****
*****************************************************************************************************************/

CAnalyseurLexical::~CAnalyseurLexical()
{
	delete pcANLChaine;
}


/****************************************************************************************************************
***** ANLLireBalise : fonction renvoyant, s'il en trouve une, la balise lue dans une chaine de caract�re de	*****
*****				  la forme <Balise>=<reste de la cha�ne>												*****
*****************************************************************************************************************
***** Entr�e :	char * pcChaine	                                                                            *****
***** N�cessite : La d�sallocation de la chaine retourn�e avec delete										*****
***** Sortie : char *							                                                            *****
***** Entraine : La fonction initialise un analyseur syntaxique � partir d'une chaine de caract�re		  OU*****
**************** Exception BALISE_INVALIDE : Le caract�re de d�limitation de la balise (en l'occurence		*****
**************** le caract�re "=" n'a pas �t� trouv� dans la cha�ne											*****
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

	//copie de la balise � retourner ensuite
	strncpy_s(pcBalise, uiLongueurBalise + 1, pcANLChaine, uiLongueurBalise);

	return pcBalise;
}


/****************************************************************************************************************
***** ANLLireNaturel : fonction renvoyant l'entier naturel lu � la position donn�e d'une chaine				*****
*****************************************************************************************************************
***** Entr�e :unsigned int uiPositionNaturel					                                            *****
***** N�cessite : Rien				                                                                        *****
***** Sortie : unsigned int																					*****
***** Entraine : La fonction renvoie l'entier naturel lu												  OU*****
**************** Exception POSITION_CHAINE_INVALIDE : La position sp�cifi�e est en dehors de la cha�ne	  OU*****
**************** Exception ENTIER_INVALIDE : Un des caract�re lu ne correspond pas � un chiffre			    *****
*****************************************************************************************************************/

unsigned int CAnalyseurLexical::ANLLireNaturel(unsigned int uiPositionNaturel)
{
	//Variables pour parcourir la chaine caract�res par caract�res, et en extraire les chiffres
	unsigned int uiBoucle = 0;
	unsigned int uiNaturel = 0;
	unsigned int uiDigit;


	//On aura donc un maximum de 254 caract�res pour l'entier saisi dans le fichier
	char pcNaturel[255];

	if (strlen(pcANLChaine) <= uiPositionNaturel)
	{
		CException EXCException(POSITION_CHAINE_INVALIDE);
		throw EXCException;
	}

	_memccpy(pcNaturel, pcANLChaine + uiPositionNaturel, '\0', 255);

	//Extraction des entiers de la cha�ne
	while (pcNaturel[uiBoucle] != '\0')
	{
		uiDigit = (int)pcNaturel[uiBoucle] - 48;
		//V�rification de la syntaxe de la cha�ne
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