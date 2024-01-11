/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn  panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
* \brief affiche les passagers en fonction du vol choisi
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
void panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
{
    int numero_vol;
    do
    {
        printf("Entrez le numero du vol : ");
        scanf("%d", &numero_vol);
    }while (numero_vol < 1 || numero_vol > MAX_FLIGHTS);

        afficherPassagers_entete(numero_vol);
        tri_prix(tableau_vols[numero_vol].passagers, tableau_vols[numero_vol].nombre_passagers);
        afficherPassagersMoins12ans(tableau_vols,numero_vol);
        afficherPassagersPlus12ans(tableau_vols, numero_vol);
}


























