#include "head.h"
void init_tab(char tableau[LARGEUR][LONGUEUR])
{
    //initialisation du tableau qui sert de plateau
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
    //Traduction des valeurs données dans la fonction init_tab
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
            if(tableau[i][j]=='!'){
                color(12,8);
                printf("! ");
                color(15,0);
            }
            if(tableau[i][j]=='M'){
                color(12,8);
                printf("M ");
                color(15,0);
            }
            if(tableau[i][j]=='?'){
                color(14,8);
                printf("? ");
                color(15,0);
            }
            color(15,0);
        }
    }
}

void color(int t,int f)
{
    //Fonction permettant de changer la couleur de la police et du fond
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void refresh_ecran()
{
    //Fonction vidant l'écran
    fflush(stdin);
    printf("\nAppuyez sur une touche pour passer a la suite\n");
    getchar();
    system("cls");
}

void nombre_pisteur(int *pPisteur, char tableau[LARGEUR][LONGUEUR])
{
    int nb_pisteur=0;

    printf("Combien de pisteur voulez-vous? (entre 1 et 10)\n");
    scanf("%d",&nb_pisteur);
    *pPisteur=nb_pisteur;
    while(nb_pisteur>MAXPISTEUR || nb_pisteur<=0){
        if(nb_pisteur<=MAXPISTEUR && nb_pisteur>0){
            *pPisteur=nb_pisteur;
        }else{
            printf("Le nombre est incorrect combien de pisteur voulez-vous? (entre 1 et 10)\n");
            scanf("%d",&nb_pisteur);
            *pPisteur=nb_pisteur;
        }
    }
    system("cls");
    affiche_tab(tableau);
}

void placementPi(int *pPisteur, char tableau[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR])
{
    int i,hori,verti;

    for(i=1;i<=*pPisteur;i++){
        printf("\nEntrez la position de l'axe X du pisteur numero %d (Compris entre 1 et 29): \n",i);
        scanf("%d",&hori);
        while(hori<1 || hori>LONGMAX){
            hori=0;
            printf("La position de l'axe X du pisteur %d est incorrecte, veuillez en saisir une nouvelle (Compris entre 1 et 29): \n",i);
            scanf("%d",&hori);
        }
        printf("\nEntrez la position de l'axe Y du pisteur numero %d (Compris entre 1 et 14): \n",i);
        scanf("%d",&verti);
        while(verti<1 || verti>LARGMAX){
            verti=0;
            printf("La position de l'axe Y du pisteur %d est incorrecte, veuillez en saisir une nouvelle (Compris entre 1 et 14): \n",i);
            scanf("%d",&verti);
        }
        tableau[verti][hori]='P';
        positionP[i].x=hori;
        positionP[i].y=verti;

        system("cls");
        affiche_tab(tableau);
    }
}

void tracesPi(int *pPisteur, int tracesP[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR])
{
    int i;

    for(i=1;i<=*pPisteur;i++){
        tracesP[positionP[i].y][positionP[i].x]=1;
    }
}

void tracesMo(int tracesM[LARGEUR][LONGUEUR], pos_Monstre *Monstre,int *tour)
{
    int i,j;

    if(*tour>1){
        for(i=0;i<LARGEUR;i++){
            for(j=0;j<LONGUEUR;j++){
                if(tracesM[i][j]>0){
                    tracesM[i][j]=(tracesM[i][j])-1;
                }
            }
        }
    }
    tracesM[Monstre->x][Monstre->y]=16;
}

void placementMo(char tableau[LARGEUR][LONGUEUR], int tracesM[LARGEUR][LONGUEUR], pos_Monstre *Monstre)
{
    int posMonstreX, posMonstreY, i, j, k, l, verif, caseGauche, caseHaute, caseDroite, caseBas;

    /*posMonstreX= 1;
    posMonstreY= 1;*/
    verif=0;
    while(verif>0){
        srand(time(NULL));
        posMonstreX=(rand()%(LONGMAX)+1);
        posMonstreY=(rand()%(LARGMAX)+1);
        i=posMonstreX;
        j=posMonstreY;
        if(tableau[i][j]==' '){
            caseHaute=i-1;
            caseBas=i+1;
            caseGauche=j-1;
            caseDroite=j+1;

            for(k=caseHaute;k<=caseBas;k++){
                for(l=caseGauche;l<=caseDroite;l++){
                    if(tableau[k][l]=='P'){
                        verif++;
                    }
                }
            }
        }
    }
    tracesM[i][j]=16;
    tableau[i][j]='M';
    Monstre->x=j;
    Monstre->y=i;
}

void rapportPi(int *pPisteur, struct pos_Pisteur positionP[MAXPISTEUR], int tracesM[LARGEUR][LONGUEUR], char tableau[LARGEUR][LONGUEUR],int vieMonstre)
{
    int i, j, k, l, m, caze, fraicheur, rien;
    int caseGauche, caseHaute, caseDroite, caseBas;
    char feu;


    for(m=1;m<=*pPisteur;m++){
        caze=0;
        j=positionP[m].x;
        i=positionP[m].y;
        tableau[i][j]='!';
        system("cls");
        affiche_tab(tableau);
        tableau[i][j]='P';

        printf("\nRapport du pisteur %d :\n",m);

        caseHaute=i-1;
        caseBas=i+1;
        caseGauche=j-1;
        caseDroite=j+1;

        rien=0;

        for(k=caseHaute;k<=caseBas;k++){
            for(l=caseGauche;l<=caseDroite;l++){
                caze++;
                if(tracesM[k][l]!=0 && tracesM[k][l]<LARGEUR){
                    fraicheur=tracesM[k][l];
                    printf("traces en %d de valeur %d\n",caze, fraicheur);
                }
                if(tracesM[k][l]==LARGEUR){
                    printf("Je le vois\n");
                    //Proposer le tire
                    printf("Voulez vous tirer? Si oui appuyez sur T\n");
                    scanf("%c",feu);
                    feu=toupper(feu);
                    if(feu=='T'){//Appel fonction de tir
                        boum(vieMonstre);
                    }else{
                        printf("Vous avez choisi de ne pas tirer\n");
                    }
                }
                if(tracesM[k][l]==0){
                    rien++;
                }
                if(rien==9){
                    printf("Rien en 1,2,3,4,5,6,7,8,9\n");
                }
            }
        }
        fflush(stdin);
        printf("Suivant : appuyer sur une touche\n");
        getchar();
    }
}

void init_tab_traces(int tracesM[LARGEUR][LONGUEUR], int tracesP[LARGEUR][LONGUEUR])
{
    int i,j;

    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LARGEUR;j++){
            tracesM[i][j]=0;
            tracesP[i][j]=0;
        }
    }
}

void deplacementPi(int *pPisteur, struct pos_Pisteur positionP[MAXPISTEUR], char tableau[LARGEUR][LONGUEUR])
{
    int i,mouvement;
    for(i=1;i<=*pPisteur;i++){
        system("cls");
        tableau[positionP[i].y][positionP[i].x]='?';
        affiche_tab(tableau);
        tableau[positionP[i].y][positionP[i].x]=' ';
        printf("\n\nComment voulez-vous deplacer votre pisteur %d ? (1=Haut, 2=Droite, 3=Bas, 4=Gauche)\n",i);
        scanf("%d",mouvement);
        while(mouvement<=0 || mouvement>4){
            mouvement=0;
            printf("Le nombre saisi est mauvais, veuillez en rentrer un nouveau pour deplacer votre pisteur %d ? (1=Haut, 2=Droite, 3=Bas, 4=Gauche)\n");
            scanf("%d",mouvement);
        }
        if(mouvement==1){
            positionP[i].y=positionP[i].y-1;
        }
        if(mouvement==2){
            positionP[i].x=positionP[i].x+1;
        }
        if(mouvement==3){
            positionP[i].y=positionP[i].y+1;
        }
        if(mouvement==4){
            positionP[i].x=positionP[i].x-1;
        }
        tableau[positionP[i].y][positionP[i].x]='P';
        system("cls");
        affiche_tab(tableau);
    }
}

void deplacementMo(pos_Monstre *Monstre, char tableau[LARGEUR][LONGUEUR])
{
    int deplacementM;

    srand(time(NULL));
    deplacementM=(rand()%4)+1;
    tableau[Monstre->y][Monstre->x]=' ';
    if(deplacementM==1){
        Monstre->y=Monstre->y-1;
    }
    if(deplacementM==2){
        Monstre->x=Monstre->x+1;
    }
    if(deplacementM==3){
        Monstre->y=Monstre->y+1;
    }
    if(deplacementM==4){
        Monstre->x=Monstre->x-1;
    }
    tableau[Monstre->y][Monstre->x]='M';
    system("cls");
    affiche_tab(tableau);
}

void boum(int vieMonstre)
{
    int tire;
    srand(time(NULL));
    tire=(rand()%10)+1;
    if(tire<=4){
        vieMonstre--;
    }
    printf("%d",vieMonstre);
}
