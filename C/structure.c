#include "main.h"

// Charger les données depuis le CSV
void structure(struct Vol tableau_vols[], int *nombre_vols) //TOM
{
    char ligne[1000];
    char *nom_fichier = "data_vols.csv";

    // Ouverture du fichier CSV en mode lecture
    FILE *pt_fichier = fopen(nom_fichier, "r");

    // Gestion d'une erreur d'ouverture du fichier
    if (pt_fichier == NULL)
    {
        printf("\nOuverture de %s impossible", nom_fichier);
        exit(1);
    }

    // Ignorer la première ligne du fichier (en-tête)
    if (fgets(ligne, sizeof(ligne), pt_fichier) == NULL)
    {
        fclose(pt_fichier);
        exit(1);
    }

    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), pt_fichier) != NULL && *nombre_vols < MAX_FLIGHTS)
    {
        char liste_passagers[1000];

        // Utilisation de sscanf pour extraire les données de la ligne du CSV
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
            sscanf(passager, "%29[^,],%29[^,],%10[^,],%d,%f",
                   tableau_vols[*nombre_vols].passagers[i].nom,
                   tableau_vols[*nombre_vols].passagers[i].prenom,
                   tableau_vols[*nombre_vols].passagers[i].date_naissance,
                   &tableau_vols[*nombre_vols].passagers[i].numero_siege,
                   &tableau_vols[*nombre_vols].passagers[i].prix_billet);

            passager = strtok(NULL, ";");
            i++;
        }

        // Enregistrement du nombre de passagers dans la structure Vol
        tableau_vols[*nombre_vols].nombre_passagers = i;

        // Incrémentation du nombre de vols
        (*nombre_vols)++;
    }

    // Fermeture du fichier après lecture
    fclose(pt_fichier);
}
