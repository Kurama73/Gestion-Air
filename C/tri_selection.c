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


/*
void interclassement(struct Vol tableau_volsA[], const int nombre_volsA ,struct Vol tableau_volsB[] , const int nombre_volsB )
{
    int i = 0, j = 0, k = 0;
    const int sizetab = nombre_volsA + nombre_volsB;
    printf("flag1");

    struct Vol *tab3 = (struct Vol *)malloc(sizetab * sizeof(struct Vol));
    printf("flag2");
    while (i < nombre_volsA && j < nombre_volsB)
    {
        printf("flag3");
        if (tableau_volsA[i].passagers[0].prix_billet <= tableau_volsB[j].passagers[0].prix_billet)
        {
            printf("flag4");
            tab3[k] = tableau_volsA[i];
            i++;
        }
        else
        {
            printf("flag5");
            tab3[k] = tableau_volsB[j];
            j++;
        }
        k++;
    }

    while (i < nombre_volsA)
    {
        printf("flag6");
        tab3[k] = tableau_volsA[i];
         i++;
        k++;
    }

    while (j < nombre_volsB)
    {
        printf("flag7");
        tab3[k] = tableau_volsB[j];
        j++;
        k++;
    }


    for (int i = 0; i < sizetab; i++)
    {
        printf("flag8");
        tableau_volsB[i] = tableau_volsA[i];

    free(tab3);

    }
     int taille = sizeof(tab3) / sizeof(tab3[0]);

    // Boucle pour afficher les éléments du tableau
    for (int i = 0; i < taille; i++) {
        printf("Element %d : %d\n", i, tab3[i]);
    }
}
/*void copie(int tab1[], int n, int tab2[]) {
    for (int i = 0; i < n; i++) {
        tab2[i] = tab1[i];
    }
}


/*
void tri_prix(struct Vol tableau_vols[], const int nombre_vols)
{
    if (nombre_vols > 1)
    {


        const int nombre_volsA = nombre_vols / 2;
        const int nombre_volsB = nombre_vols - nombre_volsA;


        tri_prix(tableau_vols, nombre_volsA);
        tri_prix(tableau_vols + nombre_volsA, nombre_volsB);

        // Utilisation d'un tableau temporaire pour l'interclassement
        interclassement( tableau_vols, nombre_volsA, tableau_vols + nombre_volsA, nombre_volsB);

        // Copie du tableau temporaire dans le tableau original

    }
}*/




void tri_prix(struct Vol tableau_vols[], int nombre_vol)
{
    int numero_vol;

    printf("Entrez le numero du vol que vous souhaitez trier : ");
    scanf("%d", &numero_vol);

    if (numero_vol < 1)
    {
        printf("Numero de vol invalide.\n");
        return;
    }

    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
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
