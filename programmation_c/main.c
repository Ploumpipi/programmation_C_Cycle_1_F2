#include <stdio.h>
#include <stdlib.h>


void int_somme(int n_nb1, int n_nb2, int *n_Res);
void init_somme(int n_tabEntier[],int n_taille);


int main()
{
    //Pointeur

    int n_entier=0;
//pointeur sur l'adresse de n_entier //adresse de n_entier
    int *pn_entier=&n_entier;

    *pn_entier=10; //n_entier devient 10 également
    int n_entier2=5;
    pn_entier=&n_entier2;
    *pn_entier=8;

    //Passage par adresse
    int n_nb1=10, n_nb2=5, n_Res=0;
    int_somme(n_nb1, n_nb2,n_Res);

    //Tableaux et pointeur
    //exemple avec char
    char c_tab[10];
    char *pc_char=c_tab;
    int n_i;
    for(n_i=0;n_i<10;n_i++){
        pc_char[n_i]='a';
    }
    pc_char++;

    //exemple avec int
    int n_tab[10];
    int *pn_int=n_tab;
    for(n_i=0;n_i<10;i++){
        pn_int[n_i]=5;
    }
    //incrementation du pointeur d'entier,j'incrémente son espace d'adressage
    pn_int++;//ecriture 1
    *(pn_int)++;//ecriture 2
    //incrementation de la val et non du pointeur
    (*pn_int)++;//*pn_int++
    for(n_i=0;n_i<10;i++){
        //n_tab[n_i]=8; formalisme tableau
        *(n_tab+n_i)=8;//formalisme pointeur
    }
    int n_tab2D[10][10];
    int n_j;
    for(n_i=0;n_i<10;n_i++){
        for(n_j=0;n_j<10;n_j++){
            //n_tab2D[n_i][n_j]
            *(*(n_tab2D+n_i)+n_j)=0;//formalisme pointeur matrice
        }
    }

    //Attention
    //bug
    /*int *pn_entier3;
    *pn_entier3=6;*/

    //fix
    int *pn_entier3=NULL;//0x0
    pn_entier3=&n_entier;
    init_tabEntier(n_tab,10);
    int n_tabEntier2[100];
    init_tabEntier(n_tabEntier2,100);
    char *pc_car=get_tabChar(c_tab, 10);

    return 0;
}

void int_somme(int n_nb1, int n_nb2, int *n_Res)
{
    *n_Res=n_nb1+n_nb2;
}

void init_somme(int n_tabEntier[],int n_taille)
{
    int n_i;
    for(n_i=0;n_i<n_taille;n_i++){
        n_tabEntier[n_i]=0;
    }
}

char *get_tabChar(char c_tabCar[], int n_taille)
{
    int n_i;
    for(n_i=0;n_i<taille;n_i++){
        c_tabCar[n_i]='z'
    }
    return c_tabCar;
}
