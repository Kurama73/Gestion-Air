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
            // Comparaison basï¿½e sur l'heure de dï¿½collage
            if (tableau_vols[j].heure_decollage < tableau_vols[min].heure_decollage)
            {
                min = j;
            }
            j = j + 1;
        }

        // ï¿½change des ï¿½lï¿½ments pour effectuer le tri
        struct Vol tmp = tableau_vols[i];
        tableau_vols[i] = tableau_vols[min];
        tableau_vols[min] = tmp;

        i = i + 1;
    }
}


<<<<<<< HEAD
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
=======
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
       if (tableau_passagersA[i].prix_billet >= tableau_passagersB[j].prix_billet)

        {
            tab_final[k] = tableau_passagersA[i];
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
            i++;
        }
        else
        {
<<<<<<< HEAD
            printf("flag5");
            tab3[k] = tableau_volsB[j];
=======
            tab_final[k] = tableau_passagersB[j];
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
            j++;
        }
        k++;
    }

    while (i < nombre_passagersA)
    {
<<<<<<< HEAD
        printf("flag6");
        tab3[k] = tableau_volsA[i];
         i++;
=======
        tab_final[k] = tableau_passagersA[i];
        i++;
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
        k++;
    }

    while (j < nombre_passagersB)
    {
<<<<<<< HEAD
        printf("flag7");
        tab3[k] = tableau_volsB[j];
=======
        tab_final[k] = tableau_passagersB[j];
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
        j++;
        k++;
    }

    for (int i = 0; i < sizetab; i++)
    {
<<<<<<< HEAD
        printf("flag8");
        tableau_volsB[i] = tableau_volsA[i];

    free(tab3);

    }
     int taille = sizeof(tab3) / sizeof(tab3[0]);

    // Boucle pour afficher les éléments du tableau
    for (int i = 0; i < taille; i++) {
        printf("Element %d : %d\n", i, tab3[i]);
=======
        tableau_passagersA[i] = tab_final[i];
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
    }

    free(tab_final);
}
<<<<<<< HEAD
/*void copie(int tab1[], int n, int tab2[]) {
    for (int i = 0; i < n; i++) {
        tab2[i] = tab1[i];
    }
}


/*
void tri_prix(struct Vol tableau_vols[], const int nombre_vols)
=======


void tri_prix(struct Passager tableau_passagers[], const int nombre_passagers)
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
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
<<<<<<< HEAD
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
=======
>>>>>>> c5dad86f17ab04f44ee084a86adcfc416b3e5068
}
