#include "head.h"
void init_tab(char tableau[LARGEUR][LONGUEUR])
{//initialisation du tableau qui sert de plateau
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
{//Traduction des valeurs données dans la fonction init_tab
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
{//Fonction permettant de changer la couleur de la police et du fond
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}

void refresh_ecran()
{//Fonction vidant l'écran
    fflush(stdin);
    printf("\nAppuyez sur une touche pour passer a la suite\n");
    getchar();
    system("cls");
}

void nombre_pisteur(int *pPisteur, char tableau[LARGEUR][LONGUEUR])
{//On demande le nombre de pisteur
    int nb_pisteur=0;

    printf("Combien de pisteur voulez-vous? (entre 1 et 10)\n");
    scanf("%d",&nb_pisteur);//On récupère le nombre de pisteur voulu
    *pPisteur=nb_pisteur;
    while(nb_pisteur>MAXPISTEUR || nb_pisteur<=0){//Tant que la valeur est mauvaise on boucle
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
{//On place les pisteurs
    int i,hori,verti;

    for(i=1;i<=*pPisteur;i++){//Pour chaque pisteur on fait :
        printf("\nEntrez la position de l'axe X du pisteur numero %d (Compris entre 1 et 29): \n",i);
        scanf("%d",&hori);//On récupère la position en X
        while(hori<1 || hori>LONGMAX){//On vérifie la position, si elle est mauvaise on boucle jusqu'à ce qu'elle soit bonne
            hori=0;
            printf("La position de l'axe X du pisteur %d est incorrecte, veuillez en saisir une nouvelle (Compris entre 1 et 29): \n",i);
            scanf("%d",&hori);
        }
        printf("\nEntrez la position de l'axe Y du pisteur numero %d (Compris entre 1 et 14): \n",i);
        scanf("%d",&verti);//On récupère la position en Y
        while(verti<1 || verti>LARGMAX){//On vérifie la position, si elle est mauvaise on boucle jusqu'à ce qu'elle soit bonne
            verti=0;
            printf("La position de l'axe Y du pisteur %d est incorrecte, veuillez en saisir une nouvelle (Compris entre 1 et 14): \n",i);
            scanf("%d",&verti);
        }
        tableau[verti][hori]='P';//On place les pisteurs aux coordonnées rentrées
        positionP[i].x=hori;
        positionP[i].y=verti;

        system("cls");
        affiche_tab(tableau);
    }
}

void tracesPi(int *pPisteur, int tracesP[LARGEUR][LONGUEUR], struct pos_Pisteur positionP[MAXPISTEUR])
{//On créé les traces des pisteurs pour le monstre
    int i;

    for(i=1;i<=*pPisteur;i++){
        tracesP[positionP[i].y][positionP[i].x]=1;
    }
}

void tracesMo(int tracesM[LARGEUR][LONGUEUR], pos_Monstre *Monstre,int *tour)
{//On crée les traces du monstre
    int i,j;

    if(*tour>1){//On ne place pas le monstre avant le tour 2
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
{//Placement du monstre
    int posMonstreX, posMonstreY, i, j, k, l, verif, caseGauche, caseHaute, caseDroite, caseBas;

    /*posMonstreX= 1;
    posMonstreY= 1;*/
    verif=0;
    while(verif>0){//Tant que les valeurs aléatoires tombent sur une case adjacente d'un pisteur on boucle
        srand(time(NULL));
        posMonstreX=(rand()%(LONGMAX)+1);
        posMonstreY=(rand()%(LARGMAX)+1);
        j=posMonstreX;
        i=posMonstreY;
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
{//Rapport du pisteur après avoir été placé, déplacé
    int i, j, k, l, m, caze, fraicheur, rien;
    int caseGauche, caseHaute, caseDroite, caseBas;
    char feu;


    for(m=1;m<=*pPisteur;m++){//Pour chaque pisteur on fera :
        caze=0;
        j=positionP[m].x;
        i=positionP[m].y;
        tableau[i][j]='!';//On change la valeur P par ! avant d'afficher
        system("cls");
        affiche_tab(tableau);
        tableau[i][j]='P';//Puis on reremplace par P pour éviter que les ! restent

        printf("\nRapport du pisteur %d :\n",m);

        //On définit les cases de détection
        caseHaute=i-1;
        caseBas=i+1;
        caseGauche=j-1;
        caseDroite=j+1;

        rien=0;

        for(k=caseHaute;k<=caseBas;k++){//Pour de haut en bas on fait :
            for(l=caseGauche;l<=caseDroite;l++){//Pour de gauche à droite on fait :
                caze++;
                if(tracesM[k][l]!=0 && tracesM[k][l]<16){
                    fraicheur=tracesM[k][l];
                    printf("traces en %d de valeur %d\n",caze, fraicheur);
                }
                if(tableau[k][l]=='M'){
                //if(tracesM[k][l]==16){
                    printf("Je le vois\n");
                    //Proposer le tire
                    printf("Voulez vous tirer? Si oui appuyez sur T\n");
                    scanf("%c",&feu);
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
{//On initialise les tableaux de traces à 0 pour les pisteurs et le monstre
    int i,j;

    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LARGEUR;j++){
            tracesM[i][j]=0;
            tracesP[i][j]=0;
        }
    }
}

void deplacementPi(int *pPisteur, struct pos_Pisteur positionP[MAXPISTEUR], char tableau[LARGEUR][LONGUEUR])
{//Déplacement des pisteurs
    int i,mouvement,portee;
    for(i=1;i<=*pPisteur;i++){//On fait le déplacement pour chaque pisteur
        system("cls");
        tableau[positionP[i].y][positionP[i].x]='?';//On remplace le P par ? avant d'afficher pour faire comprendre à l'utilisateur
        affiche_tab(tableau);
        tableau[positionP[i].y][positionP[i].x]=' ';//Puis on change par un espace après l'affichage pour éviter d'avoir plusieurs P pour le même pisteur
        printf("\n\nComment voulez-vous deplacer votre pisteur %d ? (1=Haut, 2=Droite, 3=Bas, 4=Gauche)\n",i);
        scanf("%d",&mouvement);//On récupère la direction du déplacement
        while(mouvement<=0 || mouvement>4){//On vérifie la direction donné et si elle est juste on ne boucle pas
            mouvement=0;
            printf("Le nombre saisi est mauvais, veuillez en rentrer un nouveau pour deplacer votre pisteur %d ? (1=Haut, 2=Droite, 3=Bas, 4=Gauche)\n");
            scanf("%d",&mouvement);
        }
        printf("De combien de case voulez vous le deplacer? (1 a 4 cases)\n");
        scanf("%d",&portee);//On fait pareil pour la portée du déplacement
        while(portee<=0 || portee>4){
            portee=0;
            printf("Le nombre saisi est mauvais, veuillez en rentrer un nouveau pour la portee du deplacement (1 a 4 cases)\n");
            scanf("%d",&portee);
        }
        if(mouvement==1){//Si on veut monter
            positionP[i].y=positionP[i].y-portee;
            while(positionP[i].y<1){
                positionP[i].y=positionP[i].y+portee;
                printf("La case de destination n'est pas correcte, veuillez en choisir une autre");
                scanf("%d",&portee);
                positionP[i].y=positionP[i].y-portee;
            }
        }
        if(mouvement==2){//Si on veut aller à droite
            positionP[i].x=positionP[i].x+portee;
            while(positionP[i].x>LONGMAX){
                positionP[i].x=positionP[i].x-portee;
                printf("La case de destination n'est pas correcte, veuillez en choisir une autre");
                scanf("%d",&portee);
                positionP[i].x=positionP[i].x+portee;
            }
        }
        if(mouvement==3){//Si on veut descendre
            positionP[i].y=positionP[i].y+portee;
            while(positionP[i].y>LARGMAX){
                positionP[i].y=positionP[i].y-portee;
                printf("La case de destination n'est pas correcte, veuillez en choisir une autre");
                scanf("%d",&portee);
                positionP[i].y=positionP[i].y+portee;
            }
        }
        if(mouvement==4){//Si on veut aller à gauche
            positionP[i].x=positionP[i].x-portee;
            while(positionP[i].x<1){
                positionP[i].x=positionP[i].x+portee;
                printf("La case de destination n'est pas correcte, veuillez en choisir une autre");
                scanf("%d",&portee);
                positionP[i].x=positionP[i].x-portee;
            }
        }
        tableau[positionP[i].y][positionP[i].x]='P';//On donne P à la nouvelle position du pisteur
        system("cls");
        affiche_tab(tableau);//Puis on affiche le tableau avec seulement P
    }
}

void deplacementMo(pos_Monstre *Monstre, char tableau[LARGEUR][LONGUEUR], int tracesP[LARGEUR][LONGUEUR],int tracesM[LARGEUR][LONGUEUR])
{//Déplacement du monstre
    int deplacementM;
    int caseHaute, caseBas, caseGauche, caseDroite, i,j;

    srand(time(NULL));
    deplacementM=(rand()%4)+1;//Pour le déplacement de base du monstre on fait un lancé de dé entre 1 et 4
    tableau[Monstre->y][Monstre->x]=' ';//On change la valeur par rien pour éviter d'avoir 2 monstres après le déplacement
    if(deplacementM==1){//Pour faire monter le monstre
        Monstre->y=Monstre->y-1;
    }
    if(deplacementM==2){//Pour faire aller à droite le monstre
        Monstre->x=Monstre->x+1;
    }
    if(deplacementM==3){//Pour faire descendre le monstre
        Monstre->y=Monstre->y+1;
    }
    if(deplacementM==4){//Pour faire aller à gauche le monstre
        Monstre->x=Monstre->x-1;
    }

    //Cas où il est à côté d'un pisteur donc il va prendre la place du pisteur et le tuer
    if(tableau[Monstre->y-1][Monstre->x]=='P'){
        Monstre->y=Monstre->y-1;
        tracesM[Monstre->y-1][Monstre->x]=16;
    }
    if(tableau[Monstre->y+1][Monstre->x]=='P'){
        Monstre->y=Monstre->y+1;
        tracesM[Monstre->y+1][Monstre->x]=16;
    }
    if(tableau[Monstre->y][Monstre->x-1]=='P'){
        Monstre->x=Monstre->x-1;
        tracesM[Monstre->y][Monstre->x-1]=16;
    }
    if(tableau[Monstre->y][Monstre->x+1]=='P'){
        Monstre->x=Monstre->x+1;
        tracesM[Monstre->y][Monstre->x+1]=16;
    }
    //Cas de déplacement si le monstre trouve une trace de pisteur
    tableau[Monstre->y][Monstre->x]='M';
    system("cls");
    affiche_tab(tableau);
}

void boum(int vieMonstre)
{//Fonction de tir
    int tire;
    srand(time(NULL));
    tire=(rand()%10)+1;//On demande un chiffre aléatoire allant de 1 à 10
    if(tire<=4){//Si le chiffre aléatoire est inférieur ou égal à 4 on touche (1 chance sur 4)
        vieMonstre--;
        printf("Vous avez touche le monstre il lui reste %d point(s) de vie\n",vieMonstre);
    }else{
        printf("Votre pisteur a loupe le monstre\n");
    }
}

void information(int tour, int *pPisteur, int vieMonstre)
{
    printf("\nVous etes au tour : %d\n Il vous reste %d Pisteur(s)\n Il reste %d point(s) de vie au monstre",tour,pPisteur,vieMonstre);
}

/*void elimination()
{
    int i,j;

    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            if(positionM[i][j])
        }
    }
}*/
