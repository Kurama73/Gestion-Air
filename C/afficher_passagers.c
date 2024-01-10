/**
 * \file     afficher_passagers.c
 * \brief
 * \author   Tom FRUMY et Enzo SACCONE
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"


void afficherPassagersMoins12ans(struct Vol tableau_vols[], int numero_vol)
{


    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        // Vérifier si le passager a moins de 12 ans
        if (estMoins12ans(tableau_vols[numero_vol - 1].passagers[i]))
        {
            printf("| %-18s | %-18s | %02d/%02d/%4d        | %-5d | %-11.2f |\n",
                   tableau_vols[numero_vol - 1].passagers[i].nom,
                   tableau_vols[numero_vol - 1].passagers[i].prenom,
                   tableau_vols[numero_vol - 1].passagers[i].jour_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].mois_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].annee_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].numero_siege,
                   tableau_vols[numero_vol - 1].passagers[i].prix_billet);
        }
    }
}

void afficherPassagersPlus12ans(struct Vol tableau_vols[], int numero_vol)
{


    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        // Vérifier si le passager a moins de 12 ans
        if (estPlus12ans(tableau_vols[numero_vol - 1].passagers[i]))
        {
            printf("| %-18s | %-18s | %02d/%02d/%4d        | %-5d | %-11.2f |\n",
                   tableau_vols[numero_vol - 1].passagers[i].nom,
                   tableau_vols[numero_vol - 1].passagers[i].prenom,
                   tableau_vols[numero_vol - 1].passagers[i].jour_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].mois_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].annee_naissance,
                   tableau_vols[numero_vol - 1].passagers[i].numero_siege,
                   tableau_vols[numero_vol - 1].passagers[i].prix_billet);
        }
    }
}

// Fonction pour vérifier si un passager a moins de 12 ans
int estMoins12ans(struct Passager passager)
{
    // Supposons que nous sommes en 2024 (vous pouvez ajuster cela en fonction de l'année actuelle)
    int age = 2024 - passager.annee_naissance;

    // Vérifier si le passager a moins de 12 ans
    return age < 12;
}


int estPlus12ans(struct Passager passager)
{
    // Supposons que nous sommes en 2024 (vous pouvez ajuster cela en fonction de l'année actuelle)
    int age = 2024 - passager.annee_naissance;

    // Vérifier si le passager a moins de 12 ans
    return age >= 12;
}

void afficherPassagers_entete(int numero_vol)
{
    printf("\nPassagers du vol %d :\n", numero_vol);
    printf("|===================================================================================|\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("|===================================================================================|\n");
}

