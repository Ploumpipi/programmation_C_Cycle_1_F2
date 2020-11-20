#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VIE 5


char mot[100]={0},memMot[100]={0};
int vie=VIE;

int main()
{
    entreMot();
    changeMot();
    do{
        entreLettre();
    }while(vie>0);
    return 0;
}

void entreMot()
{
    printf("Veuillez entrer le mot a trouver\n");
    scanf("%s",&mot);
    printf("mot vaut : %s\n",mot);
}

void entreLettre()
{
    int i;
    char lettre;
    printf("Choisissez une lettre\n");
    scanf("%c",&lettre);
    for(i=0;i<strlen(mot);i++){
        if(mot[i]==lettre){
            //printf("+1");
            memMot[i]=lettre;
            printf("Vous avez trouvez une lettre il vous reste : %d vie(s)\n",vie);
        }else{
            vie--;
            printf("Mauvaise lettre ! il vous reste %d vie(s)\n",vie);
        }
    }
    printf("%s",memMot);
}

void changeMot()
{
    int i;
    for(i=0;i<strlen(mot);i++){
        memMot[i]='_';
    }
printf("memMot vaut : %s\n",memMot);
}
