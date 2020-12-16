#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define LONGUEUR 31
#define LONGMAX 29
#define LARGEUR 16
#define LARGMAX 14
#define MAXPISTEUR 10


typedef struct pos_Pisteur{//Tableau mémoire de la position des pisteurs
    int x,y;
}pos_Pisteur;

typedef struct pos_Monstre{//Tableau mémoire de la position des pisteurs
    int x,y;
}pos_Monstre;

extern void init_tab(char tableau[LARGEUR][LONGUEUR]);
extern void init_tab_traces(int tracesM[LARGEUR][LONGUEUR], int tracesP[LARGEUR][LONGUEUR]);
extern void affiche_tab(char tableau[LARGEUR][LONGUEUR]);
extern void refresh_ecran();
extern void nombre_pisteur(int *pPisteur, char tableau[LARGEUR][LONGUEUR]);
extern void placementPi(int *pPisteur, char tableau[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR]);
extern void tracesPi(int *pPisteur, int tracesP[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR]);
extern void tracesMo(int tracesM[LARGEUR][LONGUEUR], pos_Monstre *Monstre,int *tour);
extern void placementMo(char tableau[LARGEUR][LONGUEUR], int tracesM[LARGEUR][LONGUEUR], pos_Monstre *Monstre);
extern void rapportPi(int *pPisteur, struct pos_Pisteur positionP[MAXPISTEUR], int tracesM[LARGEUR][LONGUEUR], char tableau[LARGEUR][LONGUEUR], int vieMonstre);
extern void deplacementPi(int *pPisteur, struct pos_Pisteur positionP[MAXPISTEUR], char tableau[LARGEUR][LONGUEUR]);
extern void deplacementMo(pos_Monstre *Monstre, char tableau[LARGEUR][LONGUEUR]);
extern void boum(int vieMonstre);

extern void color(int t,int f);

#endif // HEAD_H_INCLUDED
