#include <stdio.h>
#include <stdlib.h>
#define CDEPART 0
#define CFIN 66
#define DMIN 2
#define DMAX 12
#define CMORT 58
#define CMULTIPLE 9
#define EXCEPTION 63

/* FEATURE
-Initialiser la position de la case de départ
-Lancer de dés
-Verification du jet de dés
-Si le jet de dés et bon on se déplace
-Vérification des cases
-Vérification du dépassement de la case 66
-Condition de victoire FIN
*/

int init ();
int jetdedes ();
int verifdes(int, int);
int deplacement(int, int, int);
int Cond_Victoire(int);

int main()
{
    int des1 = 0;
    int des2 = 0;
    int place = init();
    des1 = jetdedes();
    des2 = jetdedes();

    /*printf ("%d", des1);
    printf ("%d", des2);


    if (verifdes(des1,des2))
    {
        place += des1+des2;
    }

    place = depoilacement(9, 4, 5);
    printf ("%d", cplace);*/

        if (Cond_Victoire(66))
        {
         printf("OK!\n");
        }

    return 0;
}

int init (){

   return CDEPART;

}

int jetdedes (){
    int jet;
    printf ("Entrez un entier entre 2 et 12 :");
    scanf ("%d",&jet);
    return jet;
}

int verifdes(int jet1, int jet2)
{
    if ((jet1+jet2)>=DMIN && (jet1+jet2)<=DMAX)
    {
        return 1;
    }else{
        return 0;
    }
}

int deplacement( int place, int jet1, int jet2)
{
    if (place%CMULTIPLE ==0 && place<EXCEPTION)
    {
        place += jet1+jet2;
    }
    if (place > CFIN)
    {
        place = CFIN - (place - CFIN);
    }
    if (place == CMORT)
    {
        place = CDEPART;
    }
    return place;
}

int Cond_Victoire(int place)
{
    if (place == CFIN )
    {
        printf("Bravo ! Vous avez gagne !\n");
        return 1;
    }
    else
    {
        return 0;
    }

}
