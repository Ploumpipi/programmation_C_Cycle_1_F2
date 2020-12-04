#include "define.h"

void initTab(char tableau[TAILLE][TAILLE])
{
    int i,j;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            tableau[i][j]=0;
        }
    }
}

void afficheTab()
{
    int i,j;
    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            printf("X");
        }
    }
}
