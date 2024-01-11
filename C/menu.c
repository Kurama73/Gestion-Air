/**
 * \file     menu.c
 * \brief    Fonction menu
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"


/**
* \fn       menu(struct Vol tableau_vols[], int nombre_vols, int nombre_passagers)
* \brief    Affiche le menu de sélection
*
* \param    tableau_vols est un tableau et nombre_vols / nombre_passagers sont des entiers
* \return   rien
* \post     rien
*/

// Afficher le menu principal
void menu(struct Vol tableau_vols[], int nombre_vols, int nombre_passagers) //TOM
{
    int choix,heure;

    // Boucle principale du menu
    do
    {
        // Affichage des options du menu principal
        printf("\n====================== Menu Principal ======================\n");
        printf("|                        0- Quitter                        |\n");
        printf("|               1- Afficher le tableau des vols            |\n");
        printf("|                    2- Rechercher un vol                  |\n");
        printf("|             3- Afficher les passagers d'un vol           |\n");
        printf("|                    4- Optimiser la piste                 |");
        printf("\n============================================================\n");
        printf("Choix : ");


        while (1)
                {
                    if (scanf("%d", &choix) == 1)
                    {
                        break; // Sort de la boucle si la saisie est un entier
                    }
                        else
                    {
                        printf("Erreur. Veuillez entrer un nombre entier valide.\n");
                        while (getchar() != '\n');
                        printf("Choix : ");
                    }
                }




        // Switch pour traiter le choix de l'utilisateur
        switch (choix)
        {
        case 0:
            // Quitter le programme
            break;

        case 1:
            // Afficher le tableau des vols
            tableau_information(tableau_vols, nombre_vols);
            break;

        case 2:
        {
            // Sous-menu "Rechercher un vol"
            int sousChoix = -1;


            // Boucle pour le sous-menu
            do
            {
                // Affichage des options du sous-menu
                printf("\n=================== Rechercher un vol =====================\n");
                printf("|              0- Retour au menu principal                |\n");
                printf("|          1- Rechercher par heures de decollage          |\n");
                printf("|              2- Rechercher par destination              |\n");
                printf("|              3- Rechercher par compagnies               |\n");
                printf("|        4- Rechercher par compagnies et destination      |");
                printf("\n===========================================================\n");
                printf("Choix : ");

                while (1)
                {
                    if (scanf("%d", &sousChoix) == 1)
                    {
                        break; // Sort de la boucle si la saisie est un entier
                    }
                        else
                    {
                        printf("Erreur. Veuillez entrer un nombre entier valide.\n");
                        while (getchar() != '\n');
                        printf("Choix : ");
                    }
                }




                // Switch pour traiter le choix du sous-menu
                switch (sousChoix)
                {
                case 0:
                    // Retour au menu principal
                    break;

                case 1:
                    // Afficher les heures d'un vol
                    do {
                    printf("Entrez l'heure de decollage (hhmm) : ");
                    if (scanf("%d", &heure) == 1)
                    {
                        afficherVolHeure(tableau_vols, heure, nombre_vols);
                        break;
                    }
                    else
                    {
                        while (getchar() != '\n');
                        printf("Erreur. Veuillez entrer une heure valide (entier).\n");
                    }
                    }
                    while (1);
                    break;

                case 2:
                    // Afficher les destinations d'un vol
                    afficherDestination(tableau_vols, nombre_vols);
                    break;

                case 3:
                    // Afficher les compagnies
                    afficherCompagnie(tableau_vols, nombre_vols);
                    break;

                case 4:
                    // Afficher les compagnies et les destination
                    afficherCompagnieDestination(tableau_vols, nombre_vols);
                    break;

                default:
                    printf("Choix non valide. Veuillez reessayer.\n");
                }

            } while (sousChoix != 0);

            break;
        }

        case 3:
            // Afficher les passagers d'un vol
            tri_vol(tableau_vols, nombre_vols);
            panneau_passagerp(tableau_vols, nombre_vols);
            break;

        case 4:
            tri_heure(tableau_vols, nombre_vols);
            opti(tableau_vols, nombre_vols);
            break;

        default:
            printf("Choix non valide. Veuillez reessayer.\n");
        }

    } while (choix != 0);
}

