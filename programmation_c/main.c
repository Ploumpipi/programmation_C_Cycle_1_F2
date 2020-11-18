#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBVIE 5

int main()
{
    char mot, motve, motemp, ccar;
    int vie;

    vie=NBVIE;
    mot = ' ';
    printf("Quel est votre mot?\n");
    scanf("%s",&mot);
    //printf("%s",&mot);
    motve=generec('_',length(mot));
    while((vie>0)&&(motve!=mot)){
        printf("%s",&motve);
        scanf("%c",&ccar);
        motemp=remplace(mot,motve,ccar);
        if(motemp=motve){
            vie=(vie-1);
        }else{
            motve=motemp;
        }
    }
    if (vie=0){
        printf("Perdu");
    }else{
        printf("Gagne");
    }
    return 0;
}

char generec(char carac, int nb)
{
    char mot;
    int i;
    mot=' ';
    for(i=0; i=nb; i++)
    {
        mot=mot+carac;
    }
    return mot;
}

char remplace(char mot1, char mot2, char car)
{
    char temp;
    int i;
    temp=mot2;
    for(i=0; i=length(mot1); i++)
    {
        if(mot1[i]=car)
        {
            temp[i]=car;
        }
        return temp;
    }
}

//Calculer la longueur du mot rentré

