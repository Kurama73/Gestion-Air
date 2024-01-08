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

        printf("Entrez le numero du vol : ");
            int numero_vol;
            scanf("%d", &numero_vol);
        afficherPassagers_entete(numero_vol);
        afficherPassagersMoins12ans(tableau_vols, numero_vol);

        // Vérifier si l'heure de décollage est proche de l'heure spécifiée

        tri_prix(tableau_vols[numero_vol - 1].passagers, tableau_vols[numero_vol - 1].nombre_passagers);

        afficherPassagersPlus12ans(tableau_vols, numero_vol);



}


/*int age(tableau_vols,date_naissance)
{
    //calucule age
    age=2024-date_naissance
}
*/

























