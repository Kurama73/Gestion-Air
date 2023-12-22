/**
 * \file     thimothee.c
 * \brief
 * \author   Timothée Razafindranary
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"

// Afficher les vols dont l'heure de décollage est proche d'une heure donnée
void afficherVolHeure(struct Vol tableau_vols[], int heure, int nombre_vols) //Timothee
{
    printf("====================================================================================================================================\n");
    printf("| No Vol | Compagnie              | Destination            | Comptoir | Heure debut | Heure fin   | Salle Emb. | Heure debut embarq. | Heure fin embarq. | Heure decollage | Etat vol          | Nombre passagers |\n");
    printf("====================================================================================================================================\n");

    for (int i = 0; i < nombre_vols; i++)
    {
        // Vérifier si l'heure de décollage est proche de l'heure spécifiée
        if ((tableau_vols[i].heure_decollage >= heure - 100) && (tableau_vols[i].heure_decollage <= heure + 100))
        {
            printf("| %-6d | %-22s | %-22s | %-7d | %-11d | %-11d | %-10d | %-19d | %-18d | %-15d | %-18s | %-17d |\n",
                   tableau_vols[i].numero_vol,
                   tableau_vols[i].compagnie,
                   tableau_vols[i].destination,
                   tableau_vols[i].numero_comptoir,
                   tableau_vols[i].heure_debut_enregistrement,
                   tableau_vols[i].heure_fin_enregistrement,
                   tableau_vols[i].salle_embarquement,
                   tableau_vols[i].heure_debut_embarquement,
                   tableau_vols[i].heure_fin_embarquement,
                   tableau_vols[i].heure_decollage,
                   tableau_vols[i].etat_vol,
                   tableau_vols[i].nombre_passagers);
        }
    }
}



void afficherDestination(struct Vol tableau_vols[], int nombre_vols) //Timothee
{
    printf("Entrez la destination : ");
    char destination[50];
    scanf("%s", &destination);

    int destinationTrouvee = 0;
    size_t longueurDestination = strlen(destination);

    for (int i = 0; i < nombre_vols; i++)
    {
        if (strncasecmp(tableau_vols[i].destination, destination, longueurDestination) == 0)
        {
            printf("| %-6d | %-22s | %-22s | %-7d | %-11d | %-11d | %-10d | %-19d | %-18d | %-15d | %-18s | %-17d |\n",
                tableau_vols[i].numero_vol,
                tableau_vols[i].compagnie,
                tableau_vols[i].destination,
                tableau_vols[i].numero_comptoir,
                tableau_vols[i].heure_debut_enregistrement,
                tableau_vols[i].heure_fin_enregistrement,
                tableau_vols[i].salle_embarquement,
                tableau_vols[i].heure_debut_embarquement,
                tableau_vols[i].heure_fin_embarquement,
                tableau_vols[i].heure_decollage,
                tableau_vols[i].etat_vol,
                tableau_vols[i].nombre_passagers);

            destinationTrouvee = 1;

        }
    }

    if (!destinationTrouvee)
        printf("Aucun vol prvu pour cette destination.\n");
}

void afficherCompagnie(struct Vol tableau_vols[], int nombre_vols) //Timothee
{
    printf("Entrez la compagnie : ");
    char compagnie[50];
    scanf("%s", compagnie);

    int compagnieTrouvee = 0;
    size_t longueurCompagnie = strlen(compagnie);

    for (int i = 0; i < nombre_vols; i++)
    {
        if (strncasecmp(tableau_vols[i].compagnie, compagnie, longueurCompagnie) == 0)
        {
            printf("| %-6d | %-22s | %-22s | %-7d | %-11d | %-11d | %-10d | %-19d | %-18d | %-15d | %-18s | %-17d |\n",
                tableau_vols[i].numero_vol,
                tableau_vols[i].compagnie,
                tableau_vols[i].destination,
                tableau_vols[i].numero_comptoir,
                tableau_vols[i].heure_debut_enregistrement,
                tableau_vols[i].heure_fin_enregistrement,
                tableau_vols[i].salle_embarquement,
                tableau_vols[i].heure_debut_embarquement,
                tableau_vols[i].heure_fin_embarquement,
                tableau_vols[i].heure_decollage,
                tableau_vols[i].etat_vol,
                tableau_vols[i].nombre_passagers);

            compagnieTrouvee = 1;

        }
    }

    if (!compagnieTrouvee)
        printf("Aucune compagnie de ce nom.\n");
}

