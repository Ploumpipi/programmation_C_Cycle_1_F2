#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 11
#define NBAT 5

typedef struct posBat{
    int x;
    int y;
}posBat;

void initBateau(char MatriceEntiers2[TAILLE][TAILLE]);
int main()
{
    char MatriceEntiers2[TAILLE][TAILLE]={{"\0"}};
    initBateau(MatriceEntiers2[TAILLE][TAILLE]);
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
                if(nbx>10){
                    printf("%d",nbx);
                    nbx++;
                }else{
                printf("%d ",nbx);
                nbx++;
                }
            }
            if(MatriceEntiers2[i][TAILLE-1]==2){
                printf("%d \n",nbx);
                nbx++;
            }
            if(MatriceEntiers2[i][j]==3){
                if(nby<10){
                printf("%d  ",nby);
                nby++;
                }else{
                printf("%d ",nby);
                nby++;
                }
            }
        }
    }
return 0;
}
void initBateau(char MatriceEntiers2[TAILLE][TAILLE])
//Porte avion 5 cases, croiseur 4 cases, 2 contre torpilleur 3 cases, 1 torpilleur 2 cases
{
    char memMatriceEntiers2[TAILLE][TAILLE], direction=' ';
    int nBat=NBAT;
    memcpy(&memMatriceEntiers2, &MatriceEntiers2, sizeof(MatriceEntiers2));//Copie de la carte
    posBat posBateau={0,0};
    posBat *pPosBateau=NULL;

    pPosBateau=&posBateau;

    for(int i=0;i<nBat;i++){
        posBateau.x=0;
        posBateau.y=0;
        if(i==0){
        printf("Entrez la position x de votre torpilleur (2 cases de long)\n");
        scanf("%d",&pPosBateau->x);
        memMatriceEntiers2[pPosBateau][0];
        printf("Le voulez vous horizontalement? O/N\n");
        scanf("%c\n",direction);
        if(direction=='O' || direction=='o'){

        }



















        printf("%d\n",posBateau.x);
        printf("Entrez la position y de votre torpilleur (2 cases de long)\n");
        scanf("%d",&pPosBateau->y);
        printf("%d\n",posBateau.y);
        }
        if(i==1){
        printf("Entrez la position x de votre 1er contre-torpilleur (3 cases de long)\n");
        scanf("%d",&pPosBateau->x);
        printf("%d\n",posBateau.x);
        printf("Entrez la position y de votre 1er contre-torpilleur (3 cases de long)\n");
        scanf("%d",&pPosBateau->y);
        printf("%d\n",posBateau.y);
        }
        if(i==2){
        printf("Entrez la position x de votre 2eme contre-torpilleur (3 cases de long)\n");
        scanf("%d",&pPosBateau->x);
        printf("%d\n",posBateau.x);
        printf("Entrez la position y de votre 2eme contre-torpilleur (3 cases de long)\n");
        scanf("%d",&pPosBateau->y);
        printf("%d\n",posBateau.y);
        }
        if(i==3){
        printf("Entrez la position x de votre croiseur (4 cases de long)\n");
        scanf("%d",&pPosBateau->x);
        printf("%d\n",posBateau.x);
        printf("Entrez la position y de votre croiseur (4 cases de long)\n");
        scanf("%d",&pPosBateau->y);
        printf("%d\n",posBateau.y);
        }
        if(i==4){
        printf("Entrez la position x de votre porte avion (5 cases de long)\n");
        scanf("%d",&pPosBateau->x);
        printf("%d\n",posBateau.x);
        printf("Entrez la position y de votre porte avion (5 cases de long)\n");
        scanf("%d",&pPosBateau->y);
        printf("%d\n",posBateau.y);
        }

    }

}
