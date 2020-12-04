#include "define.h"

void iniTab(int tableau[TAILLE][TAILLE])
{
    for (int i=0;i<TAILLE;i++){//lignes
        for (int j=0;j<TAILLE;j++){//Colonnes
            tableau[i][j]=0;
        }
    }
}

void affTab(int tableau[TAILLE][TAILLE])
{
    fflush(stdin);
    int z = 40;
    int w = 10;

    gotoxy(40,9);

    printf("A B C D E F G H I J");
    for(int i=10;i<20;i++){
        gotoxy(36,i);
        printf("%d  ",i-9);
    }
    for(int i=0;i<TAILLE-1;i++){
        gotoxy(z,w++);
        for(int j = 0; j < TAILLE-1;j++){
            if (tableau[i][j]==1)
            {
                 printf("= ");
            }else{
                printf("~ ");
            }

        }
    }
    gotoxy(0,15);
}

void verifPos(char pos,posBat position,int tableau[TAILLE][TAILLE],int longueur_bateau)
{
    int verif =0;

    fflush(stdin);
    if (pos == 'v'){
        for (int i=0;i<longueur_bateau;i++){
            if ((tableau[position.y][position.x +i] != 0) || (position.x + longueur_bateau)>TAILLE ){
                verif = 1;
            }
        }
         if (verif ==0){
                for (int i=0;i<longueur_bateau;i++){
                    for (int j=0;j<longueur_bateau;j++){
                        tableau[position.y][position.x +i] = 1;
                    }
                }
            }

    }
    if (pos == 'h'){
        for (int i=0;i<longueur_bateau;i++){
            if ((tableau[position.y+i][position.x] != 0) || (position.y + longueur_bateau)>TAILLE ){
                verif = 1;
            }
        }
        if (verif ==0){
            for (int i=0;i<longueur_bateau;i++){
                for (int j=0;j<longueur_bateau;j++){
                    tableau[position.y+i][position.x] = 1;
                }
            }
        }
    }
    if (verif==1){
        printf("desole, cette coordonnee n est pas valide\n");
        choixPosBat(longueur_bateau,tableau);
    }
}

void tire(int tableau[TAILLE][TAILLE],int nb)
{
    posBat position;
    char carac;
    int ligne;

    fflush(stdin);

    gotoxy(0,0);
    printf("joueur %d , choisissez une colone (a - j)\n",nb);
    afficheJeu(tableau);

    //choix de la colone
    scanf("%c",&carac);
    system("cls");

    if ((carac < 'a') || (carac > 'j')){
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une colonne (a - j) \n");
            afficheJeu(tableau);
            scanf("%c",&carac);
            system("cls");
        }while((carac < 'a') || (carac > 'j'));

   }
    position.x = conversionCarac(carac);

    //choix de la ligne
    printf("choisissez une ligne (1 - 10)\n");
    afficheJeu(tableau);
    scanf("%d",&ligne);
    system("cls");

    if ((ligne < 1) || (ligne > 10)){
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une ligne (1 - 10) \n");
            afficheJeu(tableau);
            scanf("%d",&ligne);
            system("cls");
        }while((ligne < 1) || (ligne > 10));
    }
    position.y = ligne-1;

    if (tableau[position.y][position.x]==1){
        tableau[position.y][position.x]=3;
        printf("touche\n");
        getchar();
    }else{
        tableau[position.y][position.x]=2;
        printf("rate\n");
        getchar();
    }
}

void afficheJeu(int tableau[TAILLE][TAILLE])
{
    fflush(stdin);
    int z = 40;
    int w = 10;

   gotoxy(40,9);

   printf("A B C D E F G H I J");

    for (int i=10;i<20;i++){
       gotoxy(36,i);
       printf("%d|",i-9);
   }
    for (int i=0;i<TAILLE;i++){
        gotoxy(z,w++);
        for(int j = 0; j < TAILLE;j++)
        {
            if (tableau[i][j]==3)
            {
                 printf("X ");
            }else if (tableau[i][j]==2){
                printf("O ");
            }else{
                printf("~ ");
            }

        }
    }
    gotoxy(0,15);
}
