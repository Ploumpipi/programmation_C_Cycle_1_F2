#include "define.h"

void initBateau(char MatriceEntiers[TAILLE][TAILLE]);
void debut_partie();
int main()
{
    //debut_partie();
    char PlatJ1[TAILLE][TAILLE]={{"\0"}}, PlatJ2[TAILLE][TAILLE]={{"\0"}};
    int victoireJ1, victoireJ2;

    fflush(stdin);

    initPlat(&PlatJ1,1);//On initialise le plateau du joueur 1
    initPlat(&PlatJ2,2);//On initialise le plateau du joueur 2
    system("cls");

    do{
        tire(&PlatJ2,1);
        victoireJ1 = verifVictoire(&PlatJ2,1);

        tire(&PlatJ1,2);
        victoireJ2 = verifVictoire(&PlatJ1,2);
    }while(victoireJ1 ==1 && victoireJ2==1);

    system("cls");
    if (victoireJ1 == 2)
    {
        printf("felicitation joueur 1, vous avez gagne");
    }else{
        printf("felicitation joueur 2, vous avez gagne");
    }

    return 0;
}
/*void debut_partie()
{
    fflush(stdin);
    char mon_char;
    int verif=0;
    do{
        printf("Voulez vous jouer? O/N\n");
        mon_char=getchar();
        mon_char=toupper(mon_char);
        if(mon_char=='O'){
            printf("Bienvenue dans la bataille navale d'Alexandre !\n");
            verif++;
        }
        if(mon_char=='N'){
            printf("Aurevoir\n");
            verif++;
        }
    }while(verif==0);
}*/
