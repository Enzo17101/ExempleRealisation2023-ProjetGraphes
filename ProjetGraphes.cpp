#include <iostream>
#include <Windows.h>

#include "CAnalyseurSyntaxique.h"
#include "COperationGraphe.h"
#include "CGraphe.h"

int main(int argc, const char* argv[])
{
    //Permet de d�finir l'encodage utilis� par la console pour l'affichage
    SetConsoleOutputCP(1252);

    //Variable de boucle
    unsigned int uiBoucle;

    //Graphes qui seront utilis�s
    CGraphe* pGRAGraphe;
    CGraphe* pGRANouveauGraphe;


    if (argc < 2)
    {
        cout << "Veuillez entrer un nom de fichier en param�tre de l'ex�cutable.";
        exit(1);
    }
    else if (argc > 2)
    {
        cout << "Veuillez n'entrer qu'un seul nom de fichier en param�tre de l'ex�cutable.";
        exit(1);
    }


    try
    {
        //Cr�ation du graphe

        CAnalyseurSyntaxique* pANSSyntaxique = new CAnalyseurSyntaxique(argv[1]);

        pGRAGraphe = &pANSSyntaxique->ANSGenererGraphe();

        delete pANSSyntaxique;

        //Affichage du graphe
        cout << "Le graphe :\n\n";
        pGRAGraphe->GRAAfficherGraphe();
        cout << '\n';


        //Inversion du graphe

        //Cr�ation du nouveau graphe correspondant au graphe du fichier avec ses arcs retourn�s
        COperationGraphe* OGRoperationGraphe = new COperationGraphe();
        pGRANouveauGraphe = &(OGRoperationGraphe->OGRInverserArcsGraphe(*pGRAGraphe));


        //Affichage du nouveau graphe
        cout << "Le graphe invers� :\n\n";
        pGRANouveauGraphe->GRAAfficherGraphe();

        delete OGRoperationGraphe;
        delete pGRAGraphe;
        delete pGRANouveauGraphe;
    }
    catch (CException EXCErreur)
    {
        EXCErreur.EXCAfficherErreur();
        exit(1);
    }
}