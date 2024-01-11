/**
 * \file     main.c
 * \brief    fonction main servant à démarrer le programme
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn int main()
* \brief apelle la fonction structure puis le menu
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
