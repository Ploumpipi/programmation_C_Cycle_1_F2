#include <stdio.h>
#include <stdlib.h>
#define TAILLE 100

//const int TAILLE =100;
int main()
{
    //Exemple
    int n_a=0,n_b=0;
    char c_car='a';
    float flt_f=0.0;
    int n_test=0;
    //float flt_test;

    //int n_t=TAILLE;


    printf("Bonjour\n");
    printf("Programme exemple\n");

    printf("n_a : %d\n",n_a);
    printf("n_b : %d\n",n_b);
    printf("c_car : %c\n",c_car);
    printf("flt_f : %f\n",flt_f);
    //printf("flt_test : %d\n",flt_test);

    //printf("Entrez un entier\n");
    //scanf("%d",&n_test);
    printf("n_test : %d\n",n_test);

    putchar(c_car);//affichage non formate

    /*printf("Entrez un entier : \n");
    scanf("%d",&n_a);
    printf("Entrez un entier : \n");
    scanf("%d",&n_b);*/

    printf("Entrez deux entier :\n");
    scanf("%d%d",&n_a,&n_b);

    printf("n_a : %d\n",n_a);
    printf("n_b : %d\n",n_b);

    fflush(stdin);//vider le tampon
    printf("Entrez un caractere : \n");
    scanf("%c",&c_car);

    printf("c_car : %c",c_car);

    fflush(stdin);//vider le tampon
    printf("Entrez un caractere :\n");
    c_car=getchar();//Saisie de format

    printf("c_car : %c", c_car);
    return 0;
}
