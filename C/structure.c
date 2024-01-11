/**
 * \file     structure.c
 * \brief    Fonction structure
 * \author   Tom FRUMY
 * \version  0.1
 * \date     19/12/23
 */


#include "main.h"


/**
* \fn       structure(struct Vol tableau_vols[], int *nombre_vols)
* \brief    Extrait le contenu du fichier csv dans un tableau de structure
* \param    tableau_vols est un tableau et nombre_vols est un entier
* \return   rien
* \post     rien
*/

// Charger les donnes depuis le CSV
void structure(struct Vol tableau_vols[], int *nombre_vols) //TOM
{
    char nom_fic[CENT]; // Allouer de l'espace pour le nom du fichier
    char ligne[MILLE];
    char *nom_fichier;
    // Allocation de mmoire pour le nom du fichier
    nom_fichier = (char *)malloc(CENT * sizeof(char));

    // Vrifier si l'allocation de mmoire a russi
    if (nom_fichier == NULL)
    {
        printf("Erreur d'allocation de mmoire.\n");
        exit(1);
    }

    FILE *pt_fichier;

    do
    {
        printf("Choisissez un fichier : ");
        scanf("%s", nom_fic);
        strncpy(nom_fichier, nom_fic, sizeof(nom_fic));
        pt_fichier = fopen(nom_fichier, "r");
    } while (pt_fichier == NULL);


    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), pt_fichier) != NULL && *nombre_vols < MAX_FLIGHTS)
    {
        char liste_passagers[MILLE];

        // Utilisation de sscanf pour extraire les donnes de la ligne du CSV
        sscanf(ligne, "%d,%29[^,],%29[^,],%d,%d,%d,%d,%d,%d,%d,%19[^,],\"%999[^\"]\"",
               &tableau_vols[*nombre_vols].numero_vol,
               tableau_vols[*nombre_vols].compagnie,
               tableau_vols[*nombre_vols].destination,
               &tableau_vols[*nombre_vols].numero_comptoir,
               &tableau_vols[*nombre_vols].heure_debut_enregistrement,
               &tableau_vols[*nombre_vols].heure_fin_enregistrement,
               &tableau_vols[*nombre_vols].salle_embarquement,
               &tableau_vols[*nombre_vols].heure_debut_embarquement,
               &tableau_vols[*nombre_vols].heure_fin_embarquement,
               &tableau_vols[*nombre_vols].heure_decollage,
               tableau_vols[*nombre_vols].etat_vol,
               liste_passagers);

        char *passager = strtok(liste_passagers, ";");
        int i = 0;


        // Extraction des informations des passagers
        while (passager != NULL && i < MAX_PASSENGERS_PER_FLIGHT)
        {
            sscanf(passager, "%29[^,],%29[^,],%2d/%2d/%4d,%d,%f",
           tableau_vols[*nombre_vols].passagers[i].nom,
           tableau_vols[*nombre_vols].passagers[i].prenom,
           &tableau_vols[*nombre_vols].passagers[i].jour_naissance,
           &tableau_vols[*nombre_vols].passagers[i].mois_naissance,
           &tableau_vols[*nombre_vols].passagers[i].annee_naissance,
           &tableau_vols[*nombre_vols].passagers[i].numero_siege,
           &tableau_vols[*nombre_vols].passagers[i].prix_billet);


            passager = strtok(NULL, ";");
            i++;
        }

        // Enregistrement du nombre de passagers dans la structure Vol
        tableau_vols[*nombre_vols].nombre_passagers = i;

        // Incrmentation du nombre de vols
        (*nombre_vols)++;
    }

    // Fermeture du fichier aprs lecture
    fclose(pt_fichier);

free(nom_fichier);
}
