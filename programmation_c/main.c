#include <stdio.h>
#include <stdlib.h>
#define TAILLE

//prototypes
int somme_int(int, int);
float somme_float(float flt_va, float flt_vb);
void somme_procedure(int n_va,int n_vb);
void init_tabEntier(int n_tabEntier[TAILLE]);
int fctInit_tabEntier(int n_tabEntier[TAILLE]);

int main()
{
    int n_a=0,n_b=0,n_Res=0;
    float flt_Res;
    int n_tabEntier[TAILLE];
    n_a=5;
    n_b=11;

    n_Res=somme_int(n_a,n_b);

    printf("%d\n",n_Res);

    flt_Rest=somme_float(5.0,2.0);
    printf("%f\n",flt_Res);

    somme_procedure(n_a,n_b);

    init_tabEntier(n_tabEntier);
    int result=fctInit_tabEntier(n_tabEntier);

    return 0;
}

//fonction somme entier
int somme_int(int n_a, int n_b)
{
    int som=0;
    som=n_a+n_b;
    return som;
}

int somme_int(int n_va, int n_vb)
{
    int som=0;
    som=nb_a+nb_b;
    return som;
}

float somme_float(float flt_va, float flt_vb)
{
    float som=0;
    som=flt_va+flt_vb;
    return som;
}

//Procedure
void somme_procedure(int n_va,int n_vb)
{
    int n_Som=0;
    n_Som=n_va+n_vb;
    printf("Rest somme : %d",n_Som);
    //printf("Res somme : %d",n_va+n_vb);

}

void init_tabEntier(int n_tabEntier[TAILLE])
{
    int n_i=0;
    for(n_i=0;n_i<TAILLE;n_i++){
        n_tabEntier[n_i]=0;
    }
}

int fctInit_tabEntier(int n_tabEntier[TAILLE])
{
    int n_i=0;
    int n_Result=0;

    for(n_i=0;n_i<TAILLE;n_i++){
        n_tabEntier[n_i]=0;
        if(n_tabEntier)[n_i]==0{
            n_Result=1;
        }else{
        n_Result=0;
        }
    }
    return n_Result;
}
