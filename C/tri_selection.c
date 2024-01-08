/**
 * \file     tri_selection.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"



// TODO enzo renommer nom function
void tri_heure(struct Vol tableau_vols[], int nombre_vols)
{
    int i = 0;
    while (i < nombre_vols - 1)
    {
        int min = i;
        int j = i + 1;
        while (j < nombre_vols)
        {
            // Comparaison bas�e sur l'heure de d�collage
            if (tableau_vols[j].heure_decollage < tableau_vols[min].heure_decollage)
            {
                min = j;
            }
            j = j + 1;
        }

        // �change des �l�ments pour effectuer le tri
        struct Vol tmp = tableau_vols[i];
        tableau_vols[i] = tableau_vols[min];
        tableau_vols[min] = tmp;

        i = i + 1;
    }
}


// TODO enzo
void interclassement_prix(struct Passager tableau_passagersA[], const int nombre_passagersA, struct Passager tableau_passagersB[], const int nombre_passagersB)
{
    int i = 0, j = 0, k = 0;

    // TODO enzo nom explicites et propres
    const int sizetab = nombre_passagersA + nombre_passagersB;
    // TODO enzo to test
    //struct Passager tab3[sizetab];
    struct Passager *tab_final = (struct Passager *)malloc(sizetab * sizeof(struct Passager));

    while (i < nombre_passagersA && j < nombre_passagersB)
    {
        // TODO enzo tri du plus tot au plus tard et du plus cher au moins cher
       if ((tableau_passagersA[i].numero_siege < tableau_passagersB[j].numero_siege)
            || (tableau_passagersA[i].numero_siege == tableau_passagersB[j].numero_siege && tableau_passagersA[i].prix_billet >= tableau_passagersB[j].prix_billet))

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

    free(tab_final);
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
