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

    printf("====================================================================================================================================\n");
    printf("| No Vol | Compagnie              | Destination            | Comptoir | Heure debut | Heure fin   | Salle Emb. | Heure debut embarq. | Heure fin embarq. | Heure decollage | Etat vol          | Nombre passagers |\n");
    printf("====================================================================================================================================\n");

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
        printf("Aucun vol prévu pour cette destination.\n");
}

void afficherCompagnie(struct Vol tableau_vols[], int nombre_vols ) //Timothee
{
    printf("Entrez la compagnie : ");
    char compagnie[50];
    scanf("%s", compagnie);

    int compagnieTrouvee = 0;
    size_t longueurCompagnie = strlen(compagnie);

    printf("====================================================================================================================================\n");
    printf("| No Vol | Compagnie              | Destination            | Comptoir | Heure debut | Heure fin   | Salle Emb. | Heure debut embarq. | Heure fin embarq. | Heure decollage | Etat vol          | Nombre passagers |\n");
    printf("====================================================================================================================================\n");

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

void afficherTableauRetards(int *tableau_retard, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("Heure de decollage en retard %d\n", tableau_retard[i]);
    }
}



int* retard(struct Vol tableau_vols[], int nombre_vols)
{
    char retard[50] = "retarde";
    char val[3];
    char heure[50] = "a l'heure";

    size_t taille_heure = strlen(heure);
    int tableau_heure[50];
    int taille_tableau_heure = 0;
    int compagnieTrouvee = 0;
    size_t longueurRetard = strlen(retard);
    int num, volretard, surplus, tableau_retard[50], taille_retard = 0, test;

    for (int i = 0; i < nombre_vols; i++)
    {
        if (!strncasecmp(tableau_vols[i].etat_vol, retard, longueurRetard))
        {
            strncpy(val, tableau_vols[i].etat_vol + 9, 2);
            val[2] = '\0';
            compagnieTrouvee = 1;
            num = atoi(val);
            volretard = tableau_vols[i].heure_decollage + num;
            surplus = volretard % 100;

            if (surplus >= 60)
            {
                volretard = volretard + 40;
            }
            tableau_retard[taille_retard] = volretard;
            taille_retard++;
        }
    }

    //afficherTableauRetards(tableau_retard, taille_retard);




    return tableau_retard;
}

void afficherTableauHeure(int *tableau_heure, int taille)
{
    for (int i = 0; i < taille; i++)
    {
        printf("%d\n", tableau_heure[i]);
    }
}



int* heure(struct Vol tableau_vols[], int nombre_vols)
{

        char heure[50] = "a l'heure";

    size_t taille_heure = strlen(heure);
    int tableau_heure[50];
    int taille_tableau_heure = 0;
    int compagnieTrouvee = 0;
    size_t longueurRetard = strlen(retard);
    int num, volretard, surplus, tableau_retard[50], taille_retard = 0, test;

    for (int i = 0; i < nombre_vols; i++)
    {
        if (strncasecmp(tableau_vols[i].etat_vol, heure, taille_heure) == 0)
        {
            tableau_heure[taille_tableau_heure] = tableau_vols[i].heure_decollage; // Ajouter le numéro du vol annulé
            taille_tableau_heure++;
        }
    }

    /*if (taille_tableau_heure > 0)
    {
        // Afficher les vols a l'heure
        printf("Vols a l'heure :\n");
        for (int i = 0; i < taille_tableau_heure; i++)
        {
            printf("Heure decollage vol a l'heure : %d\n", tableau_heure[i]);
        }
    }
    else
    {
        printf("Aucun vol annule.\n");
    }*/
}




void testtab(int tableau_retard[], int taille_retard, struct Vol tableau_vols[], int nombre_vols,int tableau_heure[])
{
    int diff, avant, val,i;
    int taille_tableau = sizeof(tableau_retard) / sizeof(tableau_retard[0]);


    for (i = 0; i <= 20; i++)
    {
        printf("%d\n",i);

        //diff = (tableau_vols[i + 1].heure_decollage - tableau_vols[i].heure_decollage);
        avant = tableau_vols[i].heure_decollage + 5;
        printf("%d\n", avant);
        val = tableau_retard[i];

        /*if (diff >= 60)
        {
            diff = diff - 40;
            printf("flag3\n");
            printf("%d\n", diff);
        }

        printf("%d\n", avant);

        if (diff >= 10)
        {
            printf("flag4\n");
            printf("L'avion prevu a %d decollera a %d\n",val, avant);
            printf("flag5\n");
        }*/
    }
}

