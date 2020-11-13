#include <stdio.h>
#include <stdlib.h>

void fct (int p);
void f1 ();
void f2 (int n);
int f3(int n);

int main()
{

   // int n= 3;
    //fct(n);
    f1();
    f2 (5);
    int res = f3(5);
    return 0;
}


/void fct (int p){
printf ("%d %d",n , p);
}/

void f1 (){
printf ("bonjour");
}

void f2 (int n){
    int i=0;
    for (i=0; i<n; i++){
        printf("Bonjour");
    }
}

int f3(int n){
     int i=0;
    for (i=0; i<n; i++){
        printf("Bonjour");
    }
    return 0;
}
