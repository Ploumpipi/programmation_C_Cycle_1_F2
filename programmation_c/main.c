#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Commentaire paragraphe */
    //Commentaire ligne

    //unsigned : non sign�, ex : unsigned short sn_entier
    //integer
    short sn_entier;
    int n_entier;
    long l_entier;

    printf("Taille en octet du short : %d\n",sizeof(sn_entier));
    printf("Taille en octet de entier : %d\n",sizeof(n_entier));
    printf("Taille en octet du long : %d\n",sizeof(l_entier));

    //reel
    //unsigned : non sign�, ex : unsigned float sn_entier
    float flt_reel;
    double dbl_reel;
    long double ldbl_reel;

    printf("Taille en octet du float : %d\n",sizeof(flt_reel));
    printf("Taille en octet de double : %d\n",sizeof(dbl_reel));
    printf("Taille en octet du long double : %d\n",sizeof(ldbl_reel));

    //caract�re
    char c_car;
    printf("Taille en octet du caractere : %d\n",sizeof(c_car));

    //bool bln_booleen;
    //op�rateurs
    int n_a=0;
    int n_b=0;

    printf ("%d", (n_a>=n_b));

    //<=
    //>=
    //== �galit�
    //!= (pas =)
    //+ addition
    //- soustraction
    /*'/' division*/
    //% (MODULO)
    //=
    //, s�quencement
    //& et (&& et logique avec s�quencement)
    //| ou (|| ou logique avec s�quencement)
    //! (not)
    /*Incr�mentation
    //++
    //-- */
    //+= ex : res+=a => res=res+a
    //-=
    //'/='
    //*=

    return 0;
    //void = proc�dure
    //int = fonction
}
