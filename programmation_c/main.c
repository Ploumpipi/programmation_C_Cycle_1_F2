#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Commentaire paragraphe */
    //Commentaire ligne

    //unsigned : non signé, ex : unsigned short sn_entier
    //integer
    short sn_entier;
    int n_entier;
    long l_entier;

    printf("Taille en octet du short : %d\n",sizeof(sn_entier));
    printf("Taille en octet de entier : %d\n",sizeof(n_entier));
    printf("Taille en octet du long : %d\n",sizeof(l_entier));

    //reel
    //unsigned : non signé, ex : unsigned float sn_entier
    float flt_reel;
    double dbl_reel;
    long double ldbl_reel;

    printf("Taille en octet du float : %d\n",sizeof(flt_reel));
    printf("Taille en octet de double : %d\n",sizeof(dbl_reel));
    printf("Taille en octet du long double : %d\n",sizeof(ldbl_reel));

    //caractère
    char c_car;
    printf("Taille en octet du caractere : %d\n",sizeof(c_car));

    //bool bln_booleen;
    //opérateurs
    int n_a=0;
    int n_b=0;

    printf ("%d", (n_a>=n_b));

    //<=
    //>=
    //== égalité
    //!= (pas =)
    //+ addition
    //- soustraction
    /*'/' division*/
    //% (MODULO)
    //=
    //, séquencement
    //& et (&& et logique avec séquencement)
    //| ou (|| ou logique avec séquencement)
    //! (not)
    /*Incrémentation
    //++
    //-- */
    //+= ex : res+=a => res=res+a
    //-=
    //'/='
    //*=

    return 0;
    //void = procédure???
    //int = fonction???
}
