#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*FEATURES
-Le mot à deviner est dans le programme
-On verifie combien y a-t-il de lettre
-On entre un caractere
-Vérification du caractere
-Dévoilage ou non de la lettre + affichage du pendu
-Condition de victoire FIN
*/

int victoire(int lettreTrouvee[]);
int rechercheLettre(char lettre, char cacheMot[], int lettreTrouvee[]);
char verifCaractere();
int affichagePendu (int essaies);

int main()
{
    char lettre = 0;
    char cacheMot[] = "cucurbirtace";
    int lettreTrouvee[13] = {NULL};
    int essaies = 10;
    int i = 0;
    do{
        affichagePendu(essaies);
        printf("\n\nVous avez encore %d essaie(s)", essaies);
        printf("\nQuel est le mot secret ? \n\n");
        for (i = 0 ; i < 12 ; i++){
            if (lettreTrouvee[i]){
                printf("%c", cacheMot[i]);
            }else{
                printf("*");
            }
        }
        printf("\n\nVeuillez proposer une lettre: ");
        lettre = verifCaractere();
        if (!rechercheLettre(lettre, cacheMot, lettreTrouvee)){
            essaies --;
        }
    }
    while (essaies > 0 && !victoire (lettreTrouvee));
    if (essaies == 0)
    {
        printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||        /||\n   ||        /|\n   ||\n  /||\n //||\n============");
    }
    if (victoire(lettreTrouvee))
        {
        printf("\n\nBravo !", cacheMot);
        }
    else
        {
        printf("\n\nPERDU");
        printf("\n\nLe mot secret etait : %s", cacheMot);
        printf("\n~ La corde est offerte ~\n\n");
        }
    return 0;
}

//-------------------------------Fonction caractère-------------------------------------------

char verifCaractere()
{
    char caractere = 0;
    do {caractere = getchar();
        caractere = tolower(caractere);} //tolower rend n'importe quelle lettre en minuscule
    while (getchar() != '\n') ;
    return caractere;
}

//------------------------------Fonction condition de victoire--------------------------------------------


int victoire(int lettreTrouvee[])
{
    int i = 0;
    int joueurGagne = 1;
    for (i = 0 ; i < 12 ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }
    return joueurGagne;
}



//-----------------------------Fonction qui détermine si la lettre entrée est juste----------------------------------------------


int rechercheLettre(char lettre, char cacheMot[], int lettreTrouvee[])
{
    int i = 0;
    int LettreJuste = 0;
    for (i = 0 ; cacheMot[i] != '\0' ; i++)
    {
        if (lettre == cacheMot[i])
        {
            LettreJuste = 1;
            lettreTrouvee[i] = 1;
        }
    }

    return LettreJuste;
}

//-------------------------------Fonction qui affiche le pendu-------------------------------------------

int affichagePendu (int essaies)
{
 if (essaies == 9)
{
    printf("\n\n============");
}

if (essaies == 8)
{
    printf("\n\n   ||\n   ||\n   ||\n   ||\n   ||\n   ||\n  /||\n //||\n============");
}

if (essaies == 7)
{
    printf("\n\n   ,==============\n   ||  /\n   || /\n   ||/\n   ||\n   ||\n   ||\n  /||\n //||\n============");
}

if (essaies == 6)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/\n   ||\n   ||\n   ||\n  /||\n //||\n============");
}

if (essaies == 5)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||\n   ||\n   ||\n  /||\n //||\n============");
}

if (essaies == 4)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||         | \n   ||\n   ||\n  /||\n //||\n============");
}

if (essaies == 3)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||         | \n   ||         |\n   ||\n  /||\n //||\n============");
}

if (essaies == 2)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||         | \n   ||        /|\n   ||\n  /||\n //||\n============");
}

if (essaies == 1)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||        /| \n   ||        /|\n   ||\n  /||\n //||\n============");
}

/*
if (essaies == 0)
{
    printf("\n\n   ,==========Y===\n   ||  /      |\n   || /       |\n   ||/        O\n   ||        /||\n   ||        /|\n   ||\n  /||\n //||\n============");
}
*/
}
