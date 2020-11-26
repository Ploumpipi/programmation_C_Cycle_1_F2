#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 3


typedef struct tab{
    int num;
    float x;
    float y;
}point;
//Prototypes
void getVal(point tab_val[TAILLE]);
void Affiche(point tab_val[TAILLE]);

int main()
{
    point tab_val[TAILLE];
    getVal(tab_val);
    Affiche(tab_val);
    return 0;
}

void getVal(point tab_val[TAILLE])
{
    for(int i=0; i<TAILLE;i++){

    }
}

void Affiche(point tab_val[TAILLE])
{

}
