/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

void panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
{
    for (int i = 0; i < nombre_vols; i++)
    {
        afficherPassagers_entete(tableau_vols, i + 1);
        tri_prix(tableau_vols[i].passagers, tableau_vols[i].nombre_passagers);
        afficherPassagers(tableau_vols, i + 1);
    }
}
/*int age(tableau_vols,date_naissance)
{
    //calucule age
    age=2024-date_naissance
}
*/























void panneau_passagera(struct Vol tableau_vols[], int numero_vol)
{
    trieage(tableau_vols, numero_vol);
    afficherPassagers_entete(tableau_vols, numero_vol);
    afficherPassagers(tableau_vols, numero_vol);
}

void panneau_passagern(struct Vol tableau_vols[], int numero_vol)
{
    trienom(tableau_vols, numero_vol);
    afficherPassagers_entete(tableau_vols, numero_vol);
    afficherPassagers(tableau_vols, numero_vol);
}


