/**
 * \file     afficher_passagers.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

// Afficher les passagers d'un vol
void afficherPassagers(struct Vol tableau_vols[], int numero_vol) // A modifier par enzo
{

    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {

        char date_part[5];
        strncpy(date_part, tableau_vols[numero_vol - 1].passagers[i].date_naissance + 6, 4);
        date_part[4] = '\0';
        printf("Date Part: %s\n", date_part);

        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}

void afficherPassagers_entete(int numero_vol)
{
    printf("\nPassagers du vol %d :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");
}

