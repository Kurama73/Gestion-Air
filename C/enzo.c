/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

void trieprix(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            if (tableau_vols[numero_vol - 1].passagers[j].prix_billet > tableau_vols[numero_vol - 1].passagers[min].prix_billet)
            {
                min = j;
            }
        }

        // Échange des passagers (et non des prix directement)
        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    // Affichage des passagers triés
    printf("\nPassagers du vol %d (tries par prix) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}

void trieage(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            if (tableau_vols[numero_vol - 1].passagers[j].date_naissance < tableau_vols[numero_vol - 1].passagers[min].date_naissance)
            {
                min = j;
            }
        }

        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    printf("\nPassagers du vol %d (tries par age) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}

void trienom(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            // Utilisation de strcmp pour comparer les noms
            if (strcmp(tableau_vols[numero_vol - 1].passagers[j].nom, tableau_vols[numero_vol - 1].passagers[min].nom) > 0)
            {
                min = j;
            }
        }

        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    // Affichage des passagers triés par nom
    printf("\nPassagers du vol %d (tries par nom) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}


