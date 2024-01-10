/**
 * \file     menu.c
 * \brief
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

// Afficher le menu principal
void menu(struct Vol tableau_vols[], int nombre_vols, int nombre_passagers) //TOM
{
    int choix;

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
        scanf("%d", &choix);


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
                printf("|             3- Rechercher par compagnies                |");
                printf("\n===========================================================\n");
                printf("Choix : ");
                scanf("%d", &sousChoix);

                // Switch pour traiter le choix du sous-menu
                switch (sousChoix)
                {
                case 0:
                    // Retour au menu principal
                    break;

                case 1:
                    // Afficher les heures d'un vol
                    printf("Entrez l'heure de décollage : ");
                    int heure;
                    scanf("%d", &heure);
                    afficherVolHeure(tableau_vols, heure, nombre_vols);
                    break;

                case 2:
                    // Afficher les destinations d'un vol
                    afficherDestination(tableau_vols, nombre_vols);
                    break;

                case 3:
                    // Afficher les compagnies
                    afficherCompagnie(tableau_vols, nombre_vols);
                    break;

                default:
                    printf("Choix non valide. Veuillez réessayer.\n");
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

            opti(tableau_vols, nombre_vols);
            break;

        default:
            printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choix != 0);
}

