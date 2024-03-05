

/****************************************************************************************************************
***** ARCLireIdDestination : accesseur en écriture de pcANLChaine											*****
*****************************************************************************************************************
***** Entrée :	char * pcNouvelleChaine																		*****
***** Nécessite : Rien				                                                                        *****
***** Sortie : Rien																							*****
***** Entraine : La fonction modifie la valeur de pcANLChaine											    *****
*****************************************************************************************************************/

inline void CAnalyseurLexical::ANLModifierChaine(const char* pcNouvelleChaine)
{
	delete pcANLChaine;

	unsigned int uiLongeurChaine = strlen(pcNouvelleChaine) + 1;

	pcANLChaine = new char[uiLongeurChaine];

	//Copie de la chaine pcNouvelleChaine vers pcANLChaine
	strcpy_s(pcANLChaine, uiLongeurChaine, pcNouvelleChaine);
}