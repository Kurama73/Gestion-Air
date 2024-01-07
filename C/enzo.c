/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

void panneau_passagerp(struct Vol tableau_vols[], int numero_vol)
{
    for (int i = 0; i < numero_vol; i++)
    {
        afficherPassagers_entete(tableau_vols[i].numero_vol);
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

























