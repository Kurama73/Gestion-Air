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
    char heureActuelleStr[5];

    do
    {
        printf("Veuillez saisir l'heure actuelle (sous la forme hhmm) : ");
        scanf("%4s", heureActuelleStr);
    } while (atoi(heureActuelleStr) < 600 || atoi(heureActuelleStr) > 2200); //conversion de la chaine de caractere en entier

    int heureActuelle = atoi(heureActuelleStr);

    if (heureActuelle >= 600 && heureActuelle <= 2200)
    {
        // Tri du tableau en fonction des heures de décollage
        tri_heure(tableau_vols, nombre_vols);


        printf("\nTableau des vols dans les 3 heures suivantes a partir de %02d:%02d :\n", heureActuelle / 100, heureActuelle % 100);
        printf("===============================================================================================================================================================\n");
        printf("| Heure Decollage  | No Vol | Compagnie              | Destination            | Comptoir | Enregistrement | Salle Emb. | Embarquement         | Etat vol\n");
        printf("===============================================================================================================================================================\n");

        for (int i = 0; i < nombre_vols; i++)
        {
            // Vérifier si le vol est dans les 3 heures suivantes
            if (tableau_vols[i].heure_decollage >= heureActuelle && tableau_vols[i].heure_decollage <= (heureActuelle + 300))
            {
                printf("| %02d:%02d            | %-6d | %-22s | %-22s |",
                tableau_vols[i].heure_decollage / 100,
                tableau_vols[i].heure_decollage % 100,
                tableau_vols[i].numero_vol,
                tableau_vols[i].compagnie,
                tableau_vols[i].destination);

                // Afficher le comptoir et les heures d'enregistrement si dans la plage spécifiée (A partir de 30 minutes avant le debut et jusqu'a 1à min apres la fin)
                if (tableau_vols[i].heure_debut_enregistrement - 30 < heureActuelle && heureActuelle < tableau_vols[i].heure_fin_enregistrement)
                {
                    printf(" %-8d | %02d:%02d - %02d:%02d  |",
                    tableau_vols[i].numero_comptoir,
                    tableau_vols[i].heure_debut_enregistrement / 100,
                    tableau_vols[i].heure_debut_enregistrement % 100,
                    tableau_vols[i].heure_fin_enregistrement / 100,
                    tableau_vols[i].heure_fin_enregistrement % 100);
                }

                else
                {
                    // Laisser des espaces pour le comptoir et les heures d'enregistrement
                    printf(" %-8s | %-14s |", "", "");
                }

                // Afficher la salle d'embarquement et les heures d'embarquement si dans la plage spécifiée (A partir de 30 minutes avant le debut et jusqu'a 1à min apres la fin)
                if (tableau_vols[i].heure_debut_embarquement - 30 <= heureActuelle && heureActuelle <= tableau_vols[i].heure_fin_embarquement)
                {
                    printf(" %-10d | %02d:%02d - %02d:%02d        |",
                    tableau_vols[i].salle_embarquement,
                    tableau_vols[i].heure_debut_embarquement / 100,
                    tableau_vols[i].heure_debut_embarquement % 100,
                    tableau_vols[i].heure_fin_embarquement / 100,
                    tableau_vols[i].heure_fin_embarquement % 100);
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
