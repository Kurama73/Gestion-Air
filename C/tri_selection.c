/**
 * \file     tri_selection.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

#define MAX_PASSAGERS 1000


void tri_selection(struct Vol tableau_vols[], int nombre_vols)
{
    int i = 0;
    while (i < nombre_vols - 1)
    {
        int min = i;
        int j = i + 1;
        while (j < nombre_vols)
        {
            // Comparaison basée sur l'heure de décollage
            if (tableau_vols[j].heure_decollage < tableau_vols[min].heure_decollage)
            {
                min = j;
            }
            j = j + 1;
        }

        // Échange des éléments pour effectuer le tri
        struct Vol tmp = tableau_vols[i];
        tableau_vols[i] = tableau_vols[min];
        tableau_vols[min] = tmp;

        i = i + 1;
    }
}



void interclassement(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
{
    int i = 0, j = 0, k = 0;

    const int sizetab = nombre_passagersA + nombre_passagersB;

    struct Passager *tab3 = (struct Passager *)malloc(sizetab * sizeof(struct Passager));

    while (i < nombre_passagersA && j < nombre_passagersB)
    {
        if (tableau_passagersA[i].prix_billet >= tableau_passagersB[j].prix_billet)
        {
            tab3[k] = tableau_passagersA[i];
            i++;
        }
        else
        {
            tab3[k] = tableau_passagersB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_passagersA)
    {
        tab3[k] = tableau_passagersA[i];
        i++;
        k++;
    }

    while (j < nombre_passagersB)
    {
        tab3[k] = tableau_passagersB[j];
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
        tableau_passagersA[i] = tab3[i];
    }

    free(tab3);
}

/*void copie(int tab1[], int n, int tab2[]) {
    for (int i = 0; i < n; i++) {
        tab2[i] = tab1[i];
    }
}
*/


void tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
{
    if (nombre_passagers > 1)
    {


        const int nombre_passagersA = nombre_passagers / 2;
        const int nombre_passagersB = nombre_passagers - nombre_passagersA;


        tri_prix(tableau_passagers, nombre_passagersA);
        tri_prix(tableau_passagers + nombre_passagersA, nombre_passagersB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement(tableau_passagers, nombre_passagersA, tableau_passagers + nombre_passagersA, nombre_passagersB);

        // Copie du tableau temporaire dans le tableau original

    }
}


/*
void tri_prix(struct Vol tableau_vols[], int numero_vol)
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
}
*/


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
        {            if (strcmp(tableau_vols[numero_vol - 1].passagers[j].nom, tableau_vols[numero_vol - 1].passagers[min].nom) > 0)

            // Utilisation de strcmp pour comparer les noms
            {
                min = j;
            }
        }

        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }
}
