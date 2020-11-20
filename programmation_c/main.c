#include <stdio.h>
#include <stdlib.h>

//Exemple un point dans un plan

typedef struct tPoint{
    int x;
    int y;
}tPoint;

int main()
{
    tPoint monPoint;
    tPoint *pMonPoint=NULL;
    pMonPoint=&monPoint;

    monPoint.x=10;
    monPoint.y=5;

    //Pointeur
    pMonPoint->x=12;//pour un pointeur on remplace le point par une flèche
    pMonPoint->y=20;

    //formalisme pointeur
    (*pMonPoint).x=20;
    (*pMonPoint).y=12;

    return 0;
}
