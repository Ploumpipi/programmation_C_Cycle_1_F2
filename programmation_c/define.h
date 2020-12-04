#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>//Besoin de windows pour la fonction gotoxy
#define TAILLE 11
#define PAVION 5
#define CROISEUR 4
#define CTORPILLEUR1 3
#define CTORPILLEUR2 3
#define TORPILLEUR 2
#define NBAT 5

typedef struct posBat{
    int x,y;
}posBat;


void iniTab(int tab[TAILLE][TAILLE]);
extern void initPlat(int tableau[TAILLE][TAILLE], int joueur);
extern void choixPosBat(int longueur_bat, int tableau[TAILLE][TAILLE]);
extern void verifPos(char pos,posBat position,int tableau[TAILLE][TAILLE],int longueur_bateau);
extern int conversionCarac(char carac);
extern void affTab(int tableau[TAILLE][TAILLE]);
extern void gotoxy(short x, short y);
extern void tire(int tableau[TAILLE][TAILLE],int nb);
extern void afficheJeu(int tableau[TAILLE][TAILLE]);
extern int verifVictoire(int tableau[TAILLE][TAILLE],int joueur);


#endif // DEFINE_H_INCLUDED
