#include "define.h"

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

void gotoxy(short x, short y)
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Pos={x,y};
    SetConsoleCursorPosition(hConsole,Pos);
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
