#include "head.h"
void init_tab(char tableau[LARGEUR][LONGUEUR])
{
    int i,j;
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            tableau[0][j]='*';
            tableau[0][0]='1';
            tableau[0][LONGUEUR-1]='o';
            tableau[i][0]='*';
            tableau[i][j]=' ';
            tableau[i][LONGUEUR-1]='o';
            tableau[LARGEUR-1][j]='*';
        }
    }
}

void affiche_tab(char tableau[LARGEUR][LONGUEUR])
{
    int i,j;
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            if(tableau[i][j]=='*'){
                color(13,7);
                printf("* ");
            }
            if(tableau[i][j]=='1'){
                color(13,7);
                printf(" * ");
            }
            if(tableau[i][j]==' '){
                color(0,8);
                printf("  ");
            }
            if(tableau[i][j]=='o'){
                color(13,7);
                printf("* \n ");
            }
            if(tableau[i][j]=='P'){
                color(11,8);
                printf("P ");
                color(15,0);
            }
            color(15,0);
        }
    }
}

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}

void refresh_ecran()
{
    fflush(stdin);
    printf("\nAppuyez sur une touche pour passer a la suite\n");
    getchar();
    system("cls");
}

void nombre_pisteur(int *pPisteur, char tableau[LARGEUR][LONGUEUR])
{
    int nb_pisteur;

    printf("Combien de pisteur voulez-vous?\n");
    scanf("%d",&nb_pisteur);
    if(nb_pisteur<=MAXPISTEUR){
        *pPisteur=nb_pisteur;
    }else{
        printf("Combien de pisteur voulez-vous?\n");
        scanf("%d",&nb_pisteur);
    }
    system("cls");
    affiche_tab(tableau);
}

void placementP(int *pPisteur, char tableau[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR])
{
    int i,hori,verti,j,k;

    for(i=1;i<=*pPisteur;i++)
    {
        printf("\nEntrez la position de l'axe X du pisteur numero %d (Compris 1 et 29): \n",i);
        scanf("%d",&hori);
        printf("\nEntrez la position de l'axe Y du pisteur numero %d (Compris 1 et 14): \n",i);
        scanf("%d",&verti);
        //tableau[verti][hori]=3;//'P'
        tableau[verti][hori]='P';
        positionP[i].x=hori;
        positionP[i].y=verti;

        system("cls");
        affiche_tab(tableau);
    }
}

void placement_monstre()
{
    //Faire un random et TANT QUE le random tombe près d'un pisteur relancer
}
