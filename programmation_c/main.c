#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRIVEE 66
#define EXCEPTION 63
#define MORT 58
#define MULTIPLE 9
#define VALMIN 2
#define VALMAX 12
#define DEPART 0

int main()
{
    int place, jetDeDes;
    srand(time(NULL));
    while(place != ARRIVEE){
        printf("joueur :\n");
        lanceDeDe(&jetDeDes);
        positionJoueur(&place,&jetDeDes);
        printf("Obtient un %d", jetDeDes);
        printf(" et se deplace a la case %d\n", place);
    }
    return 0;
}

void lanceDeDe(int*jetDeDes)
{
    *jetDeDes=(rand()%(12-2+1))+2;
}

void positionJoueur(int *position, int *jetDeDes)
{
    *position = *position + *jetDeDes;
    int nbrcase;
    if(*position%9 == 0)
    {
        *position = *position+*jetDeDes;
        printf("C'est une case oie, le lance compte double\n");
    }
    if (*position == EXCEPTION)
    {
        *position = EXCEPTION;
    }
    if (*position == MORT)
    {
        *position = DEPART;
        printf("C'est la case mort, retour a la case depart\n");
    }
    if (*position>ARRIVEE)
    {
        *position = ARRIVEE - nbrcase;
        nbrcase=*position-ARRIVEE;
    }
}

void victoire (int position)
{
    if (position == ARRIVEE)
        printf("Bravo vous avez gagne\n");
}
