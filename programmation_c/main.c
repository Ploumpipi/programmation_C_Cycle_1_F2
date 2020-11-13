#include <stdio.h>
#include <stdlib.h>
#define NBI 4

int main()
{
   int i, n, som;
   som = 0;
   for (i=0; i<4; i++){
    printf("donnez un entier\n");
    scanf("%d",&n);
    som += n;
   }
    printf("Somme : %d\n", som);

    //ex 1 while
    i = 0;
    som = 0;
    while(i<4){
        printf("donnez un entier\n");
        scanf("%d",&n);
        som += n;
        i++;
    }
    printf("Somme : %d\n", som);*/

    //ex 1 do while
    i = 0;
    som = 0;
    do{
        printf("donnez un entier\n");
        scanf("%d",&n);
        som += n;
        i++;
    }while(i<4);
    printf("Somme : %d\n", som);

    //exercice 2 : moyenne V1
    int n_note, note, total_note, moy;
    float flt_moy;
    n_note = 0;
    note = 0;
    total_note = 0;
    flt_moy = 0.0;
    printf("Entrez le nombre de note\n");
    scanf("%d",&n_note);
    for(i=0; i<n_note; i++){
        printf("Entrez une note\n");
        scanf("%d",&note);
        total_note += note;
    }
    moy = (total_note/n_note);
    printf("La moyenne est de %d",moy);

    //V2
    do{
        printf("Entre une note, pour terminer entrez une note negative.\n");
        scanf("%d",&note);
        if(note>= 0){
            total_note +=note;
            i++;
        }
    }while(note>=0);
    flt_moy =(float)total_note/i;
    printf("La moyenne des notes entrees est : %.2f.\n",flt_moy);

    //Exercice 3
    int longueur=0, i=0, j=0;
    printf("Entrez la longueur du triangle souhaite\n");
    scanf("%d",&longueur);

    for (i=0;i<longueur;i++){
        while(j<i){
            printf("*");
            j++;
        }
        j=0;
        printf("\n");
    }

    return 0;
}
