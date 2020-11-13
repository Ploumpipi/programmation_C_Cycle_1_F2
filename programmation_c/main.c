#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10

//const int TAILLE =10;

int main()
{
    int n_tabEntiers[TAILLE];//Les tableaux commencent à 0
    int n_i;
    for(n_i=0;n_i<TAILLE;n_i++){
        n_tabEntiers[n_i]=0;
    }
    for(n_i=0;n_i<TAILLE;n_i++){
        printf("%d\n",n_tabEntiers[n_i]);
    }
    int n_tabEntiers2[TAILLE]={0,10,5,8,9,2,6,8,9,10};
    for(n_i=0;n_i<TAILLE;n_i++){
        printf("%d\n",n_tabEntiers2[n_i]);
    }
    int n_tabEntiers3[TAILLE]={0,10,5};
    for(n_i=0;n_i<TAILLE;n_i++){
            printf("%d\n",n_tabEntiers3[n_i]);
    }
    int n_tabEntiers4[TAILLE]={0};
    for(n_i=0;n_i<TAILLE;n_i++){
            printf("%d\n",n_tabEntiers4[n_i]);
    }
    int n_tabEntiers5[]={1,2,3,4,5,6,7,8,9};
    for(n_i=0;n_i<TAILLE;n_i++){
            printf("%d\n",n_tabEntiers5[n_i]);
    }

    int n_MatriceEntiers[TAILLE] [TAILLE];
    int n_j;
    for(n_i=0;n_i<TAILLE;n_i++){//ligne
        for(n_j=0;n_j<TAILLE;n_j++){//colonne
            n_MatriceEntiers[n_i][n_j]=0;
        }
    }

    int n_MatriceEntiers2[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for(n_i=0;n_i<TAILLE;n_i++){//ligne
        for(n_j=0;n_j<TAILLE;n_j++){//colonne
            printf("%d\n",n_MatriceEntiers2[n_i][n_j]);
        }
    return 0;
}
