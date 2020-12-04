#include "define.h"

void iniTab(int tab[TAILLE][TAILLE])
{
    for (int i=0;i<TAILLE;i++){//lignes
        for (int j=0;j<TAILLE;j++){//Colonnes
            tab[i][j]=0;
        }
    }
}

void initPlat(int tableau[TAILLE][TAILLE], int joueur)
{
    iniTab(tableau);

    gotoxy(0,0);
    printf("joueur %d, placez votre porte avion (5 cases)\n\n",joueur);
    choixPosBat(PAVION,tableau);
    affTab(tableau);

    gotoxy(0,0);
    printf("joueur %d, placez votre croiseur (4 cases)\n\n",joueur);
    choixPosBat(CROISEUR,tableau);
    affTab(tableau);

    gotoxy(0,0);
    printf("joueur %d, placez votre 1er contre-torpilleur (3 cases)\n\n",joueur);
    choixPosBat(CTORPILLEUR1,tableau);
    affTab(tableau);

    gotoxy(0,0);
    printf("joueur %d, placez votre 2eme contre-torpilleur (3 cases)\n\n",joueur);
    choixPosBat(CTORPILLEUR2,tableau);
    affTab(tableau);

    gotoxy(0,0);
    printf("joueur %d, placez votre torpilleur (2 cases)\n\n",joueur);
    choixPosBat(TORPILLEUR,tableau);
    affTab(tableau);
}

void choixPosBat(int longueur_bat, int tableau[TAILLE][TAILLE])
{
    posBat position;
    char carac,pos;
    int nb;

    //choix de la position en vertical ou horizontale
    printf("choisissez H pour horizontal et V pour vertical\n");
    affTab(tableau);
    pos=getchar();
    pos=toupper(pos);
    system("cls");

    if ((pos != 'V') && (pos != 'H')){
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez H pour horizontal et V pour vertical \n");
            affTab(tableau);
            scanf("%c",&pos);
            system("cls");
        }while((pos != 'V') && (pos != 'H'));
    }

    fflush(stdin);

    //choix de la colone
    printf("choisissez une colonne (a - j)\n");
    affTab(tableau);
    carac=getchar();
    carac=tolower(carac);
    system("cls");

    if ((carac < 'a') || (carac > 'j')){
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une colonne (a - j) \n");
            affTab(tableau);
            scanf("%c",&carac);
            system("cls");
        }while((carac < 'a') || (carac > 'j'));

   }
    position.x = conversionCarac(carac);


    //choix de la ligne
    printf("choisissez une ligne (1 - 10)\n");
    affTab(tableau);
    scanf("%d",&nb);
    system("cls");

    if ((nb < 1) || (nb > 10)){
         do{
            fflush(stdin);
            printf("mauvaise coordonnee, choisissez une ligne (1 - 10) \n");
            affTab(tableau);
            scanf("%d",&nb);
            system("cls");
        }while((nb < 1) || (nb > 10));
    }
    position.y = nb-1;

    verifPos(pos,position,tableau,longueur_bat);
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

int conversionCarac(char carac)
{
    int convertion;
    switch (carac){
        case 'a':
            convertion = 0;
        break;

        case 'b':
            convertion = 1;
        break;

        case 'c':
            convertion = 2;
        break;

        case 'd':
            convertion = 3;
        break;

        case 'e':
            convertion = 4;
        break;

        case 'f':
            convertion = 5;
        break;

        case 'g':
            convertion = 6;
        break;

        case 'h':
            convertion = 7;
        break;

        case 'i':
            convertion = 8;
        break;

        case 'j':
            convertion = 9;
        break;
    }
    fflush(stdin);
    return convertion;
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
        printf("%d|",i-9);
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

void gotoxy(short x, short y)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos={x,y};
    SetConsoleCursorPosition(hConsole,Pos);
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

int verifVictoire(int tableau[TAILLE][TAILLE],int joueur)
{
    fflush(stdin);
    int x = 0;

     for (int i=0;i<TAILLE;i++){
        for(int j = 0; j < TAILLE;j++){
            if (tableau[i][j]==1)
            {
                 x =1;
            }
        }
    }
    if ((x == 0) && (joueur==1)){
        x = 2;
    }else if ((x == 0) && (joueur==2)){
       x = 3;
    }
    return x;
}
