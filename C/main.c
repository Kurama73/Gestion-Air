/**
 * \file     main.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     08/12/23
 */

//définition librairies
#include <stdio.h>
#include <stdlib.h>


//définition fonctions
struct Vol
{
    char compagnie[50];
    char origine[50];
    char destination[50];
    int duree;
};



//fonction pricipale
int main()
{
    char* nom_fichier = "data_vols.csv";
    FILE* pointeur_fichier = NULL;
    char caractere_lu;
    char tab


    //open file
    pointeur_fichier = fopen(nom_fichier, "r");
    if (pointeur_fichier == NULL)
    {
        printf("\n%s Open Failed", nom_fichier);
    }

    //read file
    do
    {
        caractere_lu = fgetc(pointeur_fichier);
        printf("%c", caractere_lu);
    } while (caractere_lu != EOF);




    //close file
    pointeur_fichier = fclose(nom_fichier);

return 0;
}

//fonctions secondaires
