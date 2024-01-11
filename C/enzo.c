/**
 * \file     enzo.c
 * \brief    Ensemble des fonctions de Enzo
 * \author   Enzo Saccone
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn       panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
* \brief    affiche les passagers en fonction du vol choisi
*
* \param    tableau_vols est un tableau et nombre_vols est un entier
* \return   rien
* \post     rien
*/
void panneau_passagerp(struct Vol tableau_vols[], int nombre_vols)
{
    int numero_vol; // Variable pour stocker le numéro du vol

    do
    {
        printf("Entrez le numero du vol : "); // Demande à l'utilisateur d'entrer le numéro du vol

        while (1) // Boucle infinie pour gérer la saisie de l'utilisateur
        {
            if (scanf("%d", &numero_vol) == 1) // Vérifie si la saisie est un entier
            {
                break; // Sort de la boucle si la saisie est un entier valide
            }
            else
            {
                printf("Erreur. Veuillez entrer un nombre entier valide.\n"); // Affiche un message d'erreur
                while (getchar() != '\n'); // Vide le tampon d'entrée en consommant les caractères jusqu'à la nouvelle ligne
                printf("Entrez le numero du vol : "); // Redemande à l'utilisateur de saisir le numéro du vol
            }
        }
    } while (numero_vol < 1 || numero_vol > MAX_FLIGHTS); // Continue tant que le numéro du vol n'est pas dans la plage valide

    // Une fois que le numéro du vol est valide, effectue les opérations suivantes
    afficherPassagers_entete(numero_vol); // Affiche les entêtes des passagers pour le vol donné
    tri_prix(tableau_vols[numero_vol].passagers, tableau_vols[numero_vol].nombre_passagers); // Trie les passagers par prix
    afficherPassagersMoins12ans(tableau_vols, numero_vol); // Affiche les passagers de moins de 12 ans pour le vol donné
    afficherPassagersPlus12ans(tableau_vols, numero_vol); // Affiche les passagers de 12 ans et plus pour le vol donné
}


























