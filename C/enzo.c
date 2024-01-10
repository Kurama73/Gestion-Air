/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

void panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
{
    int numero_vol;
    do
    {
        printf("Entrez le numero du vol : ");
        scanf("%d", &numero_vol);
    }while (numero_vol < 1 || numero_vol > MAX_FLIGHTS);

        afficherPassagers_entete(numero_vol);
        tri_prix(tableau_vols[numero_vol - 1].passagers, tableau_vols[numero_vol - 1].nombre_passagers);
        afficherPassagersMoins12ans(tableau_vols,numero_vol);
        afficherPassagersPlus12ans(tableau_vols, numero_vol);
}


























