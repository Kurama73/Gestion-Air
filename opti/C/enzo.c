/**
 * \file     enzo.c
 * \brief
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

void panneau_passagerp(struct Vol tableau_vols[], int numero_vol)
{
<<<<<<< HEAD

=======
    tri_fusion(tableau_vols, numero_vol);
    //age(tableau_vols, tableau_vols[*nombre_vols].passagers[i].date_naissance);
    afficherPassagers_entete(tableau_vols, numero_vol);
    afficherPassagers(tableau_vols, numero_vol);
>>>>>>> b35514c8fd41c6099f7938857afdf52e9482bdf3
}

/*int age(tableau_vols,date_naissance)
{
    //calucule age
}
*/























void panneau_passagera(struct Vol tableau_vols[], int numero_vol)
{
    trieage(tableau_vols, numero_vol);
    afficherPassagers_entete(tableau_vols, numero_vol);
    afficherPassagers(tableau_vols, numero_vol);
}

void panneau_passagern(struct Vol tableau_vols[], int numero_vol)
{
    trienom(tableau_vols, numero_vol);
    afficherPassagers_entete(tableau_vols, numero_vol);
    afficherPassagers(tableau_vols, numero_vol);
}


