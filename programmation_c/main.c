#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "define.h"
#define VIE 9

int main()
{
    char *lettre;
    char motsecret [100];
    char motmodif [100];
    int nbvie = VIE,check;
    printf ("Bienvenue dans le pendu !\n");
    initmotsecret(motsecret);
    cachemotsecret(motsecret,motmodif);
    do{
    fflush(stdin);
    saisilettre (&lettre);
    check = checklettre (lettre, motsecret, motmodif);
    if (check == 0){
        nbvie--;
        printf("Il vous reste :%d vie(s)\n", nbvie);
        }
    }while(nbvie>0);
    if(nbvie==0){
        printf("Vous avez perdu !\n");
    }
    return 0;
}

void initmotsecret(char motsecret []){
    printf("Entrez le mot a deviner\n");
    scanf("%s",motsecret);
}

void cachemotsecret(char motsecret[],char motmodif[]){
    for (int i=0; i<strlen(motsecret); i++){
        motmodif[i]='_';
    }
    printf ("%s\n",motmodif);
}

void saisilettre(char *lettre){
        printf ("\nSaisir un charactere \n");
        *lettre = getchar();

}

int checklettre(char lettre, char motsecret[], char motmodif[]){
    int checked = 0;
    for (int i=0; i<strlen(motsecret); i++){
        if(motsecret[i] == lettre){
            motmodif [i] = lettre;
            printf("Bonne lettre\n");
            checked = 1;
        }
    }
    printf ("%s", motmodif);
    return checked;
}
