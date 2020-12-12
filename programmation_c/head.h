#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LONGUEUR 31
#define LARGEUR 16
#define MAXPISTEUR 10

typedef struct plateau{
    int x,y;
}plateau;
typedef struct pos_Pisteur{
    int x,y;
}pos_Pisteur;

extern void init_tab(char tableau[LARGEUR][LONGUEUR]);
extern void affiche_tab(char tableau[LARGEUR][LONGUEUR]);
extern void refresh_ecran();
extern void nombre_pisteur(int *pPisteur, char tableau[LARGEUR][LONGUEUR]);
extern void placementP(int *pPisteur, char tableau[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR]);

extern void color(int t,int f);

#endif // HEAD_H_INCLUDED
