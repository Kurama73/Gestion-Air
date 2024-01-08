/**
 * \file     tri_selection.c
 * \brief
 * \author   Tom FRUMY et Enzo SACCONE
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

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

// Fonction de tri fusion pour les vols par numéro de vol
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




// Fonction de fusion pour le tri fusion des vols par heure de décollage
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

// Fonction de tri fusion pour les vols par heure de décollage
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


// TODO enzo
void interclassement_prix(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
{
    int i = 0, j = 0, k = 0;

    // TODO enzo nom explicites et propres
    const int sizetab = nombre_passagersA + nombre_passagersB;
    // TODO enzo to test
    struct Passager tab_final[sizetab];
    //struct Passager *tab_final = (struct Passager *)malloc(sizetab * sizeof(struct Passager));

    while (i < nombre_passagersA && j < nombre_passagersB)
    {
        // TODO enzo tri du plus tot au plus tard et du plus cher au moins cher
       if ((tableau_passagersA[i].annee_naissance > tableau_passagersB[j].annee_naissance)
            || (tableau_passagersA[i].annee_naissance == tableau_passagersB[j].annee_naissance && tableau_passagersA[i].prix_billet >= tableau_passagersB[j].prix_billet))


        {
            tab_final[k] = tableau_passagersA[i];
            i++;
        }
        else
        {
            tab_final[k] = tableau_passagersB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_passagersA)
    {
        tab_final[k] = tableau_passagersA[i];
        i++;
        k++;
    }

    while (j < nombre_passagersB)
    {
        tab_final[k] = tableau_passagersB[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
        tableau_passagersA[i] = tab_final[i];
    }

    //free(tab_final);
}


void tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
{
    if (nombre_passagers > 1)
    {


        const int nombre_passagersA = nombre_passagers / 2;
        const int nombre_passagersB = nombre_passagers - nombre_passagersA;


        tri_prix(tableau_passagers, nombre_passagersA);
        tri_prix(tableau_passagers + nombre_passagersA, nombre_passagersB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement_prix(tableau_passagers, nombre_passagersA, tableau_passagers + nombre_passagersA, nombre_passagersB);

    }
}



void afficherPassagersMoins12ans(struct Vol tableau_vols[], int numero_vol)
{
    // Affichage de l'en-tête
    afficherPassagers_entete(numero_vol);

    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        // Vérifier si le passager a moins de 12 ans
        if (estMoins12ans(tableau_vols[numero_vol - 1].passagers[i]))
        {
            printf("| %-18s | %-18s | %02d/%02d/%4d | %-5d | %-11.2f |\n",
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
