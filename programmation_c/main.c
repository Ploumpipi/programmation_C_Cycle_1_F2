#include <stdio.h>
#include <stdlib.h>

//Les pointeurs sur fonctions

//Prototypes
void affiche(int n_val);
void affiche2(double n_val);
int somme(int val1, int val2);


//On déclare un pointeur de la fonction affiche
void (*pAffiche)(int);//Int est un argument du pointeur
void (*pAffiche2)(double);
int (*pSomme)(int, int);
//void (*pAffiche2)(void*);
int fctEntier(int (*pnf)(int), int n_val);
int fctE(int n_a);

int main()
{
    //affiche(12);
    pAffiche=&affiche;
    pSomme=&somme;

    printf("somme : %d\n",pSomme(5,4));

    int n_val=0;
    int *p_int=&n_val;

    pAffiche(12);

    int res=fctEntier(&fctE, 2);

    return 0;
}

void affiche(int n_val)
{
    printf("%d\n",n_val);
}

void affiche2(double n_val)
{
    printf("%d\n",n_val);
}

int somme(int val1, int val2)
{
    return val1+val2;
}

int fctEntier(int (*pnf)(int), int n_val)
{
    return (*pnf)(n_val);
}

int fctE(int n_a)
{
    return n_a;
}
