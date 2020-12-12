#include "head.h"

int main()
{
    char tableau[LARGEUR][LONGUEUR];
    struct pos_Pisteur positionP[MAXPISTEUR];
    int Pisteur;
    int *pPisteur=&Pisteur;
    init_tab(tableau);
    affiche_tab(tableau);
    refresh_ecran();
    nombre_pisteur(&pPisteur,tableau);

    placementP(&pPisteur,tableau,positionP);


    return 0;
}
