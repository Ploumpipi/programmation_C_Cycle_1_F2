#include <stdio.h>
#include <stdlib.h>
#define TAILLE 11

typedef struct pTab{
    int x;
    int y;
}pTab;
int main()
{
    /*char tabMap[TAILLE1][TAILLE2];
    int x=0,y=0;

    for (x=0;x<TAILLE1;x++){
        for(y=0;y<TAILLE2;y++){
            tabMap[x][y]="X";
        }
    }*/
    int MatriceEntiers2[TAILLE][TAILLE];//={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int i=0,j=0;
    //Bordure de la zone d'eau
    //Création zone d'eau
    for(i=0;i<TAILLE;i++){//ligne
        for(j=0;j<TAILLE;j++){//colonne
            MatriceEntiers2[i][j]=1;
            //printf("%d\n",MatriceEntiers2[n_i][n_j]);
            if(MatriceEntiers2[i][j]==1){
               printf("X");
            }
            if(MatriceEntiers2[i][TAILLE-1]==1){
                printf("X\n");
            }
        }
    }

}
