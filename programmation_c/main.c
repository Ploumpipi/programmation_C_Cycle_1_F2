#include "head.h"

int main()
{
    char tableau[LARGEUR][LONGUEUR];
    struct pos_Pisteur positionP[MAXPISTEUR];//On définit le tableau des pisteurs
    int Pisteur, tour=1, vieMonstre=4;//Initialisation des tours, des pisteurs et de la vie du monstre
    int *pPisteur=&Pisteur;
    int tracesP[LARGEUR][LONGUEUR];
    int tracesM[LARGEUR][LONGUEUR];
    init_tab_traces(tracesM,tracesP);
    pos_Monstre Monstre;
    init_tab(tableau);
    affiche_tab(tableau);
    refresh_ecran();
    nombre_pisteur(&pPisteur,tableau);

    placementPi(&pPisteur,tableau,positionP);
    placementMo(tableau,tracesM,&Monstre);

    while(&pPisteur>0 || vieMonstre>0){
        tracesPi(&pPisteur, tracesP, positionP);
        tracesMo(tracesM, &Monstre, &tour);
        rapportPi(&pPisteur, positionP, tracesM, tableau, vieMonstre);
        deplacementPi(&pPisteur, positionP, tableau);
        deplacementMo(&Monstre, tableau);
    }


    return 0;
}
