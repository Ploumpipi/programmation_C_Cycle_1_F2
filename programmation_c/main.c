#include <stdio.h>
#include <stdlib.h>
#define TAILLE 11

typedef struct pTab{
    int x;
    int y;
}pTab;
int main()
{
    int MatriceEntiers2[TAILLE][TAILLE];//={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int i=0,j=0,nbx=0,nby=1;
    //Bordure de la zone d'eau
    //Création zone d'eau
    for(i=0;i<TAILLE;i++){//ligne
        for(j=0;j<TAILLE;j++){//colonne
            MatriceEntiers2[i][j]=1;
            MatriceEntiers2[0][j]=2;
            MatriceEntiers2[nby][0]=3;
            if(MatriceEntiers2[i][j]==1){
               printf("X ");
            }
            if(MatriceEntiers2[i][TAILLE-1]==1){
                printf("X \n");
            }
            if(MatriceEntiers2[i][j]==2){
                printf("%d ",nbx);
                nbx++;
            }
            if(MatriceEntiers2[i][TAILLE-1]==2){
                printf("%d \n",nbx);
                nbx++;
            }
            if(MatriceEntiers2[i][j]==3){
                printf("%d ",nby);
                nby++;
            }
        }
    }

}
