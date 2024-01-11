/**
 * \file     thimothee.c
 * \brief   
 * \author   Timothe Razafindranary
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"



/**
* \fn       afficherVolHeure(tableau_vols[],heure, nombre_vols)
* \brief    Afficher les vols dont l'heure de décollage est proche d'une heure donnée
* \param    tableau_vols est un tableau, heure est un entier saisi et nombre_vols est un entier
* \return   rien
* \post     rien
*/
void afficherVolHeure(struct Vol tableau_vols[], int heure, int nombre_vols) //Timothee
{
    printf("====================================================================================================================================\n");
    printf("| No Vol | Compagnie              | Destination            | Comptoir | Heure debut | Heure fin   | Salle Emb. | Heure debut embarq. | Heure fin embarq. | Heure decollage | Etat vol          | Nombre passagers |\n");
    printf("====================================================================================================================================\n");

    for (int i = 0; i < nombre_vols; i++)
    {
        // Vrifier si l'heure de dcollage est proche de l'heure spcifie
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



/**
* \fn  afficherDestination(struct Vol tableau_vols[], int nombre_vols)
* \brief Afficher les vols en fonction de la compagnie saisi
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
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
        printf("Aucun vol prevu pour cette destination.\n");
}


/**
* \fn  afficherCompagnie(struct Vol tableau_vols[], int nombre_vols)
* \brief Afficher les vols en fonction de la destination saisi
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
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


/**
* \fn  afficherTableauRetards(int *tableau_retard, int taille)
* \brief Affiche tableau_retard
*
* \param tableau_retard est un tableau et taille est un entier
* \return rien
* \post rien
*/
void afficherTableauRetards(int *tableau_retard, int taille) //Timothee
{
    for (int i = 0; i < taille; i++)
    {
        printf("Heure de decollage en retard %d\n", tableau_retard[i]);
    }
}






/**
* \fn  opti(struct Vol tableau_vols[], int nombre_vols)
* \brief Recupere les vols en retard et indique a quel heure ils peuvent dcoller
*
* \param tableau_vols est un tableau et nombre_vols est un entier
* \return rien
* \post rien
*/
void opti(struct Vol tableau_vols[], int nombre_vols) //Timothee
{
    char heure[50] = "a l'heure";
    size_t taille_heure = strlen(heure);
    int tableau_heure[50];
    int taille_tableau_heure = 0;

    for (int i = 0; i < nombre_vols; i++)
    {
        if (strncasecmp(tableau_vols[i].etat_vol, heure, taille_heure) == 0)
        {
            tableau_heure[taille_tableau_heure] = tableau_vols[i].heure_decollage;
            taille_tableau_heure++;
        }
    }
    // Le commentaire ci-dessous permet d'afficher tableau heure

    /*if (taille_tableau_heure > 0)
    {
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

    char retard[50] = "retarde";
    size_t longueurRetard = strlen(retard);
    int tableau_retard[50];
    int taille_retard = 0;

    for (int i = 0; i < nombre_vols; i++)
    {
        if (!strncasecmp(tableau_vols[i].etat_vol, retard, longueurRetard))
        {
            char val[3];
            strncpy(val, tableau_vols[i].etat_vol + 9, 2);
            val[2] = '\0';
            int num = atoi(val);

            int volretard = tableau_vols[i].heure_decollage + num;
            int surplus = volretard % 100;

            if (surplus >= 60)
            {
                volretard = volretard + 40;
            }
            tableau_retard[taille_retard] = volretard;
            taille_retard++;
        }
    }
    for (int i = 0; i < taille_retard - 1; i++)
    {
        for (int j = 0; j < taille_retard - 1 - i; j++)
        {
            if (tableau_retard[j] > tableau_retard[j + 1])
            {
                int temp = tableau_retard[j];
                tableau_retard[j] = tableau_retard[j + 1];
                tableau_retard[j + 1] = temp;
            }
        }
    }

   //afficherTableauRetards(tableau_retard, taille_retard);

    int diff, avant, place,chevauche;



    for (int i = 0; i < taille_retard; i++)
    {
        place = tableau_retard[i];
        bool sortie = false;

        for (int j = 0; j < taille_tableau_heure - 1 && !sortie; j++)
        {

            diff = tableau_heure[j + 1] - tableau_heure[j];
            avant = tableau_heure[j] + 5;
            int ajuste1 = tableau_heure[j] % 100;
            int ajuste2 = tableau_heure[j+1] % 100;

            if (ajuste1 > ajuste2)
            {
                diff = diff - 40;
            }
            if (diff > 60)
            {
                diff = diff - 40;
            }



            if (diff >= 10)
            {
                if ((place <= avant) && (chevauche != avant))
                {

                    chevauche = avant;
                    printf("Le vol prevu a %d decollera a %d\n", place, avant);
                    sortie = true;
                }
            }
        }
    }

}

