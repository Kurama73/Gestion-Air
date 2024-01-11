/**
 * \file     afficher_passagers.c
 * \brief
 * \author   Tom FRUMY et Enzo SACCONE
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn  afficherPassagersMoins12ans(struct Vol tableau_vols[], int numero_vol)
* \brief Affiche le tableau des passagers de moins de 12 ans
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
void afficherPassagersMoins12ans(struct Vol tableau_vols[], int numero_vol)
{


    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        // V�rifier si le passager a moins de 12 ans
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

/**
* \fn  afficherPassagersPlus12ans(struct Vol tableau_vols[], int numero_vol)
* \brief Affiche le tableau des passagers de moins de 12 ans
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
void afficherPassagersPlus12ans(struct Vol tableau_vols[], int numero_vol)
{


    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        // V�rifier si le passager a moins de 12 ans
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

/**
* \fn  estMoins12ans(struct Passager passager)
* \brief Fonction pour v�rifier si un passager a moins de 12 ans
*
* \param passager est un tableau
* \return entier
* \post age < 12 si l'age est plus petit que 12
*/

int estMoins12ans(struct Passager passager)
{
    // Supposons que nous sommes en 2024 (vous pouvez ajuster cela en fonction de l'ann�e actuelle)
    int age = 2024 - passager.annee_naissance;

    // V�rifier si le passager a moins de 12 ans
    return age < 12;
}

/**
* \fn  estPLus12ans(struct Passager passager)
* \brief Fonction pour v�rifier si un passager a plus de 12 ans
*
* \param passager est un tableau
* \return entier
* \post age >= 12 si l'age est plus grand que 12
*/
int estPlus12ans(struct Passager passager)
{
    // Supposons que nous sommes en 2024 (vous pouvez ajuster cela en fonction de l'ann�e actuelle)
    int age = 2024 - passager.annee_naissance;

    // V�rifier si le passager a moins de 12 ans
    return age >= 12;
}

/**
* \fn  afficherPassagers_entete(int numero_vol)
* \brief Affiche un ent�te pour une meilleur visibilit�
*
* \param  numero_vols est un entier
* \return rien
* \post rien
*/
void afficherPassagers_entete(int numero_vol)
{
    printf("\nPassagers du vol %d :\n", numero_vol);
    printf("|===================================================================================|\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("|===================================================================================|\n");
}

