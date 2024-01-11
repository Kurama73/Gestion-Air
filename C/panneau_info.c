/**
 * \file     panneau_info.c
 * \brief    Fonction tableau_information
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

/**
* \fn       tableau_information(struct Vol tableau_vols[], int nombre_vols)
* \brief    affiche le tableau des vols
* \param    tableau_vols est un tableau et nombre_vols est un entier
* \return   rien
* \post     rien
*/

// Fonction pour afficher le tableau d'information
void tableau_information(struct Vol tableau_vols[], int nombre_vols) //TOM
{
    // Définir l'heure actuelle sous forme de chaîne de caractères
    char heureActuelleStr[CINQ];

    do
    {
        printf("Veuillez saisir l'heure actuelle (sous la forme hhmm) : ");
        scanf("%s", heureActuelleStr);
    } while (atoi(heureActuelleStr) < SIX_CENT || atoi(heureActuelleStr) > DEUX_MILLE_DEUX_CENT); //conversion de la chaine de caractere en entier

    int heureActuelle = atoi(heureActuelleStr);

    if (heureActuelle >= SIX_CENT && heureActuelle <= DEUX_MILLE_DEUX_CENT)
    {
        // Tri du tableau en fonction des heures de décollage
        tri_heure(tableau_vols, nombre_vols);


        printf("\nTableau des vols dans les 3 heures suivantes a partir de %02d:%02d :\n", heureActuelle / CENT, heureActuelle % CENT);
        printf("===============================================================================================================================================================\n");
        printf("| Heure Decollage  | No Vol | Compagnie              | Destination            | Comptoir | Enregistrement | Salle Emb. | Embarquement         | Etat vol\n");
        printf("===============================================================================================================================================================\n");

        for (int i = 0; i < nombre_vols; i++)
        {
            // Vérifier si le vol est dans les 3 heures suivantes
            if (tableau_vols[i].heure_decollage >= heureActuelle && tableau_vols[i].heure_decollage <= (heureActuelle + TROIS_CENT))
            {
                printf("| %02d:%02d            | %-6d | %-22s | %-22s |",
                tableau_vols[i].heure_decollage / CENT,
                tableau_vols[i].heure_decollage % CENT,
                tableau_vols[i].numero_vol,
                tableau_vols[i].compagnie,
                tableau_vols[i].destination);

                // Afficher le comptoir et les heures d'enregistrement si dans la plage spécifiée (A partir de 30 minutes avant le debut et jusqu'a 1à min apres la fin)
                if (tableau_vols[i].heure_debut_enregistrement - TRENTE < heureActuelle && heureActuelle < tableau_vols[i].heure_fin_enregistrement)
                {
                    printf(" %-8d | %02d:%02d - %02d:%02d  |",
                    tableau_vols[i].numero_comptoir,
                    tableau_vols[i].heure_debut_enregistrement / CENT ,
                    tableau_vols[i].heure_debut_enregistrement % CENT,
                    tableau_vols[i].heure_fin_enregistrement / CENT,
                    tableau_vols[i].heure_fin_enregistrement % CENT);
                }

                else
                {
                    // Laisser des espaces pour le comptoir et les heures d'enregistrement
                    printf(" %-8s | %-14s |", "", "");
                }

                // Afficher la salle d'embarquement et les heures d'embarquement si dans la plage spécifiée (A partir de 30 minutes avant le debut et jusqu'a 1à min apres la fin)
                if (tableau_vols[i].heure_debut_embarquement - TRENTE <= heureActuelle && heureActuelle <= tableau_vols[i].heure_fin_embarquement)
                {
                    printf(" %-10d | %02d:%02d - %02d:%02d        |",
                    tableau_vols[i].salle_embarquement,
                    tableau_vols[i].heure_debut_embarquement / CENT,
                    tableau_vols[i].heure_debut_embarquement % CENT,
                    tableau_vols[i].heure_fin_embarquement / CENT,
                    tableau_vols[i].heure_fin_embarquement % CENT);
                }

                else
                {
                    // Laisser des espaces pour la salle d'embarquement et les heures d'embarquement
                    printf(" %-10s | %-20s |", "", "");
                }

                // Afficher l'état du vol
                printf(" %-8s\n", tableau_vols[i].etat_vol);
            }
        }
    }
}
