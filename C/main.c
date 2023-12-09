#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSENGERS 10
#define MAX_FLIGHTS 100

struct Passager
{
    char nom[20];
    char prenom[20];
    char date_naissance[11];
    int numero_comptoir;
    float prix_ticket;
};

struct Vol
{
    int numero_vol;
    char compagnie[30];
    char destination[30];
    int numero_comptoir;
    int heure_debut_enregistrement;
    int heure_fin_enregistrement;
    int salle_embarquement;
    int heure_debut_embarquement;
    int heure_fin_embarquement;
    int heure_decollage;
    char etat_vol[20];
    struct Passager liste_passagers[MAX_PASSENGERS];
    int nombre_passagers;
};

void afficherVols(struct Vol tableau_vols[], int nombre_vols);
void rechercherVol(struct Vol tableau_vols[], int nombre_vols);
void afficherEmbarquement(struct Vol tableau_vols[], int nombre_vols);

int main()
{
    char* nom_fichier = "data_vols.csv";
    FILE* pointeur_fichier = NULL;
    struct Vol tableau_vols[MAX_FLIGHTS];
    int nombre_vols = 0;

    // Open file
    pointeur_fichier = fopen(nom_fichier, "r");
    if (pointeur_fichier == NULL)
    {
        printf("\n%s Open Failed", nom_fichier);
        return 1; // Exit the program if the file cannot be opened
    }

    // Read file
    char ligne[1024];  // Assumption: Maximum line length is 1024 characters
    while (fgets(ligne, sizeof(ligne), pointeur_fichier) != NULL)
    {
        // Process each line using sscanf
        sscanf(ligne, "%d,%29[^,],%29[^,],%d,%d,%d,%d,%d,%d,%d,%19[^,],%*[^\"\"]\"%*[^\"]\"%[^\"]",
               &tableau_vols[nombre_vols].numero_vol,
               tableau_vols[nombre_vols].compagnie,
               tableau_vols[nombre_vols].destination,
               &tableau_vols[nombre_vols].numero_comptoir,
               &tableau_vols[nombre_vols].heure_debut_enregistrement,
               &tableau_vols[nombre_vols].heure_fin_enregistrement,
               &tableau_vols[nombre_vols].salle_embarquement,
               &tableau_vols[nombre_vols].heure_debut_embarquement,
               &tableau_vols[nombre_vols].heure_fin_embarquement,
               &tableau_vols[nombre_vols].heure_decollage,
               tableau_vols[nombre_vols].etat_vol,
               tableau_vols[nombre_vols].liste_passagers);

        // Extract passenger details separately
        char* passagers = strchr(ligne, '\"');
        if (passagers != NULL)
        {
            sscanf(passagers, "\"%[^\"]\"", tableau_vols[nombre_vols].liste_passagers);
        }

        // Count the number of passengers
        tableau_vols[nombre_vols].nombre_passagers = 0;
        char* passager_token = strtok(tableau_vols[nombre_vols].liste_passagers, ";");
        while (passager_token != NULL && tableau_vols[nombre_vols].nombre_passagers < MAX_PASSENGERS)
        {
            sscanf(passager_token, "%19[^,],%19[^,],%19[^,],%d,%f",
                   tableau_vols[nombre_vols].liste_passagers[tableau_vols[nombre_vols].nombre_passagers].nom,
                   tableau_vols[nombre_vols].liste_passagers[tableau_vols[nombre_vols].nombre_passagers].prenom,
                   tableau_vols[nombre_vols].liste_passagers[tableau_vols[nombre_vols].nombre_passagers].date_naissance,
                   &tableau_vols[nombre_vols].liste_passagers[tableau_vols[nombre_vols].nombre_passagers].numero_comptoir,
                   &tableau_vols[nombre_vols].liste_passagers[tableau_vols[nombre_vols].nombre_passagers].prix_ticket);

            passager_token = strtok(NULL, ";");
            tableau_vols[nombre_vols].nombre_passagers++;
        }

        nombre_vols++;

        if (nombre_vols >= MAX_FLIGHTS)
        {
            printf("Warning: Too many flights in the file. Increase the size of the array if needed.\n");
            break;
        }
    }

    // Close file
    fclose(pointeur_fichier);

    // Menu principal
    int choix;
    do
    {
        printf("\nMenu Principal\n");
        printf("0 - Quitter\n");
        printf("1 - Afficher panneau\n");
        printf("2 - Rechercher un vol\n");
        printf("3 - Afficher panneau embarquement\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            afficherVols(tableau_vols, nombre_vols);
            break;
        case 2:
            rechercherVol(tableau_vols, nombre_vols);
            break;
        case 3:
            afficherEmbarquement(tableau_vols, nombre_vols);
            break;
        case 0:
            printf("Programme terminé.\n");
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

void afficherVols(struct Vol tableau_vols[], int nombre_vols)
{
    for (int i = 0; i < nombre_vols; i++)
    {
        printf("Vol %d\t", tableau_vols[i].numero_vol);
        printf("Compagnie: %s\t", tableau_vols[i].compagnie);
        printf("Destination: %s\t", tableau_vols[i].destination);
        printf("Numero de comptoir: %d\t", tableau_vols[i].numero_comptoir);
        printf("Heure debut enregistrement: %d\t", tableau_vols[i].heure_debut_enregistrement);
        printf("Heure fin enregistrement: %dt", tableau_vols[i].heure_fin_enregistrement);
        printf("Salle embarquement: %d\t", tableau_vols[i].salle_embarquement);
        printf("Heure debut embarquement: %d\t", tableau_vols[i].heure_debut_embarquement);
        printf("Heure fin embarquement: %d\t", tableau_vols[i].heure_fin_embarquement);
        printf("Heure decollage: %d\t", tableau_vols[i].heure_decollage);
        printf("Etat du vol: %s\t", tableau_vols[i].etat_vol);

        printf("Passagers:\n");
        for (int j = 0; j < tableau_vols[i].nombre_passagers; j++)
        {
            printf("  Nom: %s, Prenom: %s, Date de naissance: %s, Numero de comptoir: %d, Prix du ticket: %.2f\n",
                   tableau_vols[i].liste_passagers[j].nom,
                   tableau_vols[i].liste_passagers[j].prenom,
                   tableau_vols[i].liste_passagers[j].date_naissance,
                   tableau_vols[i].liste_passagers[j].numero_comptoir,
                   tableau_vols[i].liste_passagers[j].prix_ticket);
        }

        printf("\n");
    }
}

void rechercherVol(struct Vol tableau_vols[], int nombre_vols)
{

}

void afficherEmbarquement(struct Vol tableau_vols[], int nombre_vols)
{

}
