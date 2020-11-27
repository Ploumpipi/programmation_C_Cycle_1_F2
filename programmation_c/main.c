#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main()
{
    /*FILE *fSortie=NULL;
    FILE *fEntree=NULL;

    int n_val=0;
    int n_Occurence=0;
    int n_NombreVal=0;
    char str_nomFichier[21];

    //Ecriture dans un fichier de type txt
    printf("Donnez le nom du fichier a creer:\n");
    scanf("%20s",str_nomFichier);
    fflush(stdin);
    if((fSortie=fopen(str_nomFichier,"w"))==NULL){
        fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{
        do{
            printf("Donnez un entier different de 0 :\n");
            scanf("%d",&n_val);
            if(n_val!=0){
                fprintf(fSortie,"%d\n",n_val);
                n_Occurence++;
            }
        }while(n_val!=0);
    }
    fclose(fSortie);//fermeture du descripteur de fichier

    //Lecture dans un fichier de type txt
    printf("Donnez le nom du fichier a lire : \n");
    scanf("%d",str_nomFichier);
    fflush(stdin);
    //ouverture du fichier en lecture
    if((fEntree=fopen(str_nomFichier,"r"))==NULL){
            //Test ouverture
        fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{
        while(n_NombreVal<n_Occurence){
            fscanf(fEntree,"%d",&n_val);
            printf("%d\n",n_val);
            n_NombreVal++;
        }
    }
    fclose(fEntree);//fermeture du descripteur de fichier*/

    FILE *fSortie2=NULL;
    FILE *fEntree2=NULL;

    int n_val2=0;
    int n_Occurence=0;
    int n_NombreVal=0;
    char str_nomFichier2[21];

    //Ecriture dans un fichier de type txt
    printf("Donnez le nom du fichier a creer:\n");
    scanf("%20s",str_nomFichier2);
    fflush(stdin);
    if((fSortie2=fopen(str_nomFichier2,"wb"))==NULL){
        fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{
        do{
            printf("Donnez un entier different de 0 :\n");
            scanf("%d",&n_val2);
            if(n_val2!=0){
                fwrite(&n_val2,sizeof(int),1, fSortie2);
                //fprintf(fSortie,"%d\n",n_val);
                n_Occurence++;
            }
        }while(n_val2!=0);
    }
    fclose(fSortie2);//fermeture du descripteur de fichier

    //Lecture dans un fichier de type txt
    printf("Donnez le nom du fichier a lire : \n");
    scanf("%d",str_nomFichier2);
    fflush(stdin);
    //ouverture du fichier en lecture
    if((fEntree2=fopen(str_nomFichier2,"rb"))==NULL){
            //Test ouverture
        fprintf(stderr,"Erreur ouverture du fichier :%s\n",strerror(errno));
    }else{
        while(n_NombreVal<n_Occurence){
            fscanf(fEntree2,"%d",&n_val2);
            printf("%d\n",n_val2);
            n_NombreVal++;
        }
    }
    fclose(fEntree2);//fermeture du descripteur de fichier

    return 0;
}
