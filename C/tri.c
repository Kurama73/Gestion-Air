/**
 * \file     tri_selection.c
 * \brief    Ensemble des fonctions de tri
 * \author   Tom FRUMY et Enzo SACCONE
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn       interclassement_vol(struct Vol tableau_volsA[], const int nombre_volsA, struct Vol tableau_volsB[], const int nombre_volsB)
* \brief    Fonction interclassement pour tri_vol
* \param    tableau_volsA/B sont des tableaux, nombre_volsA/B sont des entiers
* \return   rien
* \post     rien
*/
void interclassement_vol(struct Vol tableau_volsA[], const int nombre_volsA, struct Vol tableau_volsB[], const int nombre_volsB)
{
    int i = 0, j = 0, k = 0;

    const int sizetab = nombre_volsA + nombre_volsB;
    struct Vol *tab_final = (struct Vol *)malloc(sizetab * sizeof(struct Vol));

    while (i < nombre_volsA && j < nombre_volsB)
    {
        // Comparaison basée sur le numéro de vol (du plus tôt au plus tard)
        if (tableau_volsA[i].numero_vol <= tableau_volsB[j].numero_vol)
        {
            tab_final[k] = tableau_volsA[i];
            i++;
        }
        else
        {
            tab_final[k] = tableau_volsB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_volsA)
    {
        tab_final[k] = tableau_volsA[i];
        i++;
        k++;
    }

    while (j < nombre_volsB)
    {
        tab_final[k] = tableau_volsB[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
        tableau_volsA[i] = tab_final[i];
    }

    free(tab_final);
}


/**
* \fn       tri_vol(struct Vol tableau_vols[], const int nombre_vols)
* \brief    Fonction de tri fusion pour les vols par numéro de vol
* \param    tableau_vols est un tableau et nombre_vols est un entier
* \return   rien
* \post     rien
*/
void tri_vol(struct Vol tableau_vols[], const int nombre_vols)
{
    if (nombre_vols > 1)
    {
        const int nombre_volsA = nombre_vols / 2;
        const int nombre_volsB = nombre_vols - nombre_volsA;

        // Tri de la première moitié
        tri_vol(tableau_vols, nombre_volsA);

        // Tri de la deuxième moitié
        tri_vol(tableau_vols + nombre_volsA, nombre_volsB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement_vol(tableau_vols, nombre_volsA, tableau_vols + nombre_volsA, nombre_volsB);
    }
}



/**
* \fn       interclassement_vol(struct Vol tableau_volsA[], const int nombre_volsA, struct Vol tableau_volsB[], const int nombre_volsB)
* \brief    Fonction interclassement pour tri_heure
* \param    tableau_volsA/B sont des tableaux, nombre_volsA/B sont des entiers
* \return   rien
* \post     rien
*/
void interclassement_heure(struct Vol tableau_volsA[], const int nombre_volsA, struct Vol tableau_volsB[], const int nombre_volsB)
{
    int i = 0, j = 0, k = 0;

    const int sizetab = nombre_volsA + nombre_volsB;
    struct Vol *tab_final = (struct Vol *)malloc(sizetab * sizeof(struct Vol));

    while (i < nombre_volsA && j < nombre_volsB)
    {
        // Comparaison basée sur l'heure de décollage (du plus tôt au plus tard)
        if (tableau_volsA[i].heure_decollage <= tableau_volsB[j].heure_decollage)
        {
            tab_final[k] = tableau_volsA[i];
            i++;
        }
        else
        {
            tab_final[k] = tableau_volsB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_volsA)
    {
        tab_final[k] = tableau_volsA[i];
        i++;
        k++;
    }

    while (j < nombre_volsB)
    {
        tab_final[k] = tableau_volsB[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
        tableau_volsA[i] = tab_final[i];
    }

    free(tab_final);
}


/**
* \fn       tri_heure(struct Vol tableau_vols[], const int nombre_vols)
* \brief    Fonction de tri fusion pour les vols par heure de décollage
* \param    tableau_vols est un tableau et nombre_vols est un entier
* \return   rien
* \post     rien
*/
void tri_heure(struct Vol tableau_vols[], const int nombre_vols)
{
    if (nombre_vols > 1)
    {
        const int nombre_volsA = nombre_vols / 2;
        const int nombre_volsB = nombre_vols - nombre_volsA;

        // Tri de la première moitié
        tri_heure(tableau_vols, nombre_volsA);

        // Tri de la deuxième moitié
        tri_heure(tableau_vols + nombre_volsA, nombre_volsB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement_heure(tableau_vols, nombre_volsA, tableau_vols + nombre_volsA, nombre_volsB);
    }
}


/**
* \fn       interclassement_prix(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
* \brief    Fonction interclassement pour tri_prix
* \param    tableau_passagersA/B sont des tableaux, nombre_passagersA/B sont des entiers
* \return   rien
* \post     rien
*/
void interclassement_prix(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
{
    // Initialisation des indices pour les deux tableaux et le tableau final
    int i = 0, j = 0, k = 0;

    // Calcul de la taille totale du tableau fusionné
    const int sizetab = nombre_passagersA + nombre_passagersB;

    // Allocation de mémoire pour le tableau fusionné
    struct Passager *tab_final = (struct Passager *)malloc(sizetab * sizeof(struct Passager));

    // Fusion des deux tableaux triés (tableau_passagersA et tableau_passagersB) dans tab_final
    while (i < nombre_passagersA && j < nombre_passagersB)
    {
        // Comparaison basée sur le prix du billet (du plus bas au plus élevé) puis en cas d'égalité le nom de maniere alphabetique
        if ((tableau_passagersA[i].prix_billet > tableau_passagersB[j].prix_billet) ||
            (tableau_passagersA[i].prix_billet == tableau_passagersB[j].prix_billet && strcmp(tableau_passagersA[i].nom, tableau_passagersB[j].nom) <= 0))
        {
            // Copie de l'élément de tableau_passagersA vers tab_final
            tab_final[k] = tableau_passagersA[i];
            i++;
        }
        else
        {
            // Copie de l'élément de tableau_passagersB vers tab_final
            tab_final[k] = tableau_passagersB[j];
            j++;
        }
        k++;
    }

    // Copie des éléments restants de tableau_passagersA (s'il y en a)
    while (i < nombre_passagersA)
    {
        tab_final[k] = tableau_passagersA[i];
        i++;
        k++;
    }

    // Copie des éléments restants de tableau_passagersB (s'il y en a)
    while (j < nombre_passagersB)
    {
        tab_final[k] = tableau_passagersB[j];
        j++;
        k++;
    }

    // Copie du tableau fusionné (tab_final) vers tableau_passagersA
    for (int i = 0; i < sizetab; i++)
    {
        tableau_passagersA[i] = tab_final[i];
    }

    // Libération de la mémoire allouée pour tab_final
    free(tab_final);
}

/**
* \fn       tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
* \brief    Fonction de tri fusion pour les passagers par prix
* \param    tableau_passagers est un tableau et nombre_passagers est un entier
* \return   rien
* \post     rien
*/
void tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
{
    if (nombre_passagers > 1)
    {
        const int nombre_passagersA = nombre_passagers / 2;
        const int nombre_passagersB = nombre_passagers - nombre_passagersA;

        // Tri de la première moitié
        tri_prix(tableau_passagers, nombre_passagersA);
        // Tri de la deuxieme moitié
        tri_prix(tableau_passagers + nombre_passagersA, nombre_passagersB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement_prix(tableau_passagers, nombre_passagersA, tableau_passagers + nombre_passagersA, nombre_passagersB);
    }
}






