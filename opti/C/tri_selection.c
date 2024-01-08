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

void tri_fusion(struct Vol tableau_vols[], int numero_vol);

void interclassement(struct Passager tab1[], int n1, struct Passager tab2[], int n2, struct Passager tab3[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (tab1[i].prix_billet <= tab2[j].prix_billet) {
            tab3[k] = tab1[i];
            i++;
        } else {
            tab3[k] = tab2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab3[k] = tab1[i];
        i++;
        k++;
    }

    while (j < n2) {
        tab3[k] = tab2[j];
        j++;
        k++;
    }
}

void copie(struct Passager tab1[], int n1, struct Passager tab2[]) {
    for (int i = 0; i < n1; i++) {
        tab2[i] = tab1[i];
    }
}

void tri_fusion(struct Vol tableau_vols[], int numero_vol) {
    int n = tableau_vols[numero_vol - 1].nombre_passagers;
    struct Passager *tab = tableau_vols[numero_vol - 1].passagers;
    if (n > 1)
    {
        int mid = n / 2;

       // tri_fusion(tableau_vols, numero_vol, tab, mid);
//        tri_fusion(tableau_vols, numero_vol, tab + mid, n - mid);
        // Utilisation d'un tableau temporaire pour l'interclassement
        struct Passager tab3[MAX_PASSAGERS];
        interclassement(tableau_vols[numero_vol - 1].passagers, mid, tableau_vols[numero_vol - 1].passagers + mid, n - mid, tab3);

        // Copie du tableau temporaire dans le tableau original
        copie(tab3, n, tableau_vols[numero_vol - 1].passagers);
    }
}


/*void trieprix(struct Vol tableau_vols[], int numero_vol)
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
}
