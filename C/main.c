/**
 * \file     main.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn int main()
* \brief affiche les passagers en fonction du vol choisi
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return 0 par convention
* \post rien
*/
int main()
{
    // Déclaration d'un tableau de structures de type Vol
    struct Vol tableau_vols[MAX_FLIGHTS];
    int nombre_vols = 0;
    int nombre_passagers = 0;

    // Charger les données à partir du CSV
    structure(tableau_vols, &nombre_vols);





    // Afficher le menu
    menu(tableau_vols, nombre_vols, nombre_passagers);

    return 0;
}
