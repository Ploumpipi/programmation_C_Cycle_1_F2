#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int n_tabEntier[10000000000000];

    int pn_Entier=(int*)malloc(sizeof(int));//équivalent à : int n_entier
    int *pn_tabEntier=(int*)malloc(10*sizeof(int));
    int *pn_tabEntier2=(int*)calloc(10, sizeof(int));
    int *pn_more_numbers=NULL;
    pn_Entier=10;
    int n_i;
    for(n_i=0;n_i<10;n_i++){
        pn_tabEntier[n_i]=0;
    }
    for(n_i=0;n_i<10;n_i++){
        printf("%d",pn_tabEntier[n_i]);
    }
    /*for(n_i=0;n_i<10;_i++){
        pn_tabEntier2[n_i]=0;
    }
    for(n_i=0;n_i<10;n_i++){
        printf("%d",pn_tabEntier2[n_i]);
    }*/
    pn_more_numbers=(int*)realloc(pn_tabEntier2, 100*sizeof(int));
    free(pn_tabEntier);
    //free(pn_tabEntier2);//Pas besoin de l'écrire vu qu'on libère pn_more_numbers vu qu'ils ont la même adresse
    free(pn_more_numbers);
    free(pn_Entier);

    int **ppn_MatEntier=NULL;
    //Allocation de l'espace mémoire au premier pointeur
    ppn_MatEntier=(int**)malloc(10*sizeof(int));
    int i=0;
    for(i=0;i<10;i++){
    //Allocation de l'espace mémoire au second pointeur
        ppn_MatEntier[i]=(int*)malloc(10*sizeof(int));
    }
    for(i=0;i<10;i++){
        free(ppn_MatEntier[i]);
    }
    free(ppn_MatEntier);
    return 0;
}
