#include <stdio.h>
#include <stdlib.h>



//Corps:
//Initialiser le mot à trouver
//Initialiser l'affichage
//Permettre au joueur d'entré une lettre
//Vérifier si la lettre est présente
//Vérification de victoire



void affichage(int longCh, char c_ChGuess[8]);
void guessChar(char *c_char);
//void checkChar(char c_char,char *c_ChGuess[8],char c_Chaine[8],int longCh,int *nbIncorrect);

void checkChar(char c_char,int longCh, int *nbIncorrect);
void modifAffich(int nbIncorrect);

int VerifVictoire(int nbIncorrect, int longCh);

char c_Chaine[8]={'B','o','n','j','o','u','r'};
char c_ChGuess[8]={'_','_','_','_','_','_','_'};
char c_pendu[7][5]={{'_','_','_','_','_'},
                    {' ','|',' ','|',' '},
                    {' ','|',' ',' ',' '},
                    {' ','|',' ',' ',' '},
                    {' ','|',' ',' ',' '},
                    {' ','|',' ',' ',' '},
                    {'_','|','_',' ',' '}};

int main()
{

    //char c_Chaine[8]={'b','o','n','j','o','u','r'};
    //char c_ChGuess[8]={'_','_','_','_','_','_','_'};
    int longCh = strlen(c_Chaine);
    int nbIncorrect=0;
    int FinDuJeu=0;

    affichage(longCh, c_ChGuess);
    char c_char;


    //checkChar(c_char, &c_ChGuess, c_Chaine, longCh, &nbIncorrect);
    //checkChar(c_char, longCh, &nbIncorrect);
    while(FinDuJeu==0){
        guessChar(&c_char);
        checkChar(c_char,longCh,&nbIncorrect);

        modifAffich(nbIncorrect);
        affichage(longCh, c_ChGuess);
        FinDuJeu = VerifVictoire(nbIncorrect, longCh);
        fflush(stdin);
    }
    return 0;
}

//Affichage du pendu
void affichage(int longCh, char c_ChGuess[8]){
    //Affichage du texte a trouver
    for(int i=0;i<longCh;i++){
        printf("%c ", c_ChGuess[i]);
    }
    printf("\n");
    //Affichage du pendu
    for(int i=0;i<7;i++){
        for(int j=0;j<5;j++){
            printf("%c", c_pendu[i][j]);
        }
        printf("\n");
    }
}

//Demande d'entré
void guessChar(char *c_char){
    printf("Veuillez entrer une lettre\n");
    *c_char=getchar();
}

//Vérification du mot à trouver et du caractère
void checkChar(char c_char,int longCh, int *nbIncorrect){
    int nbCorrecte=0;
    //si une lettre est présente, on l'ajoute dans la chaine à trouver
    for(int i=0;i<longCh;i++){
        if(tolower(c_Chaine[i])==tolower((c_char))){
            c_ChGuess[i]=tolower(c_char);
            nbCorrecte++;
        }
    }
    if(nbCorrecte==0){
        //printf("Salut");
        *nbIncorrect+=1;
    }
}

int VerifVictoire(int nbIncorrect, int longCh){
    int nbCorrect=0;
    if(nbIncorrect==6){
        printf("\nperdu\n");
        printf("La reponse etait : %s", c_Chaine);
        return 2;
    }
    for(int i=0;i<longCh;i++){
        if(tolower(c_Chaine[i])==tolower((c_ChGuess[i]))){
            nbCorrect++;
        }
    }
    if(nbCorrect==longCh){
        printf("\nvictoire");
        return 1;
    }
    return 0;
}

void modifAffich(int nbIncorrect){
    switch(nbIncorrect){
        case 1:
            c_pendu[2][3]='o';
            break;
        case 2:
            c_pendu[3][3]='|';
            break;
        case 3:
            c_pendu[3][2]='/';
            break;
        case 4:
            c_pendu[3][4]='|';
            break;
        case 5:
            c_pendu[4][2]='/';
            break;
        case 6:
            c_pendu[4][4]='|';
            break;
    }
}
