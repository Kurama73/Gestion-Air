#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS_PER_FLIGHT 100

struct Passager
{
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    int numero_siege;
    float prix_billet;
};

struct Vol
{
    int numero_vol;
    char compagnie[50];
    char destination[50];
    int numero_comptoir;
    int heure_debut_enregistrement;
    int heure_fin_enregistrement;
    int salle_embarquement;
    int heure_debut_embarquement;
    int heure_fin_embarquement;
    int heure_decollage;
    char etat_vol[20];
    int nombre_passagers;
    struct Passager passagers[MAX_PASSENGERS_PER_FLIGHT];
};

void afficherTableau(struct Vol tableau_vols[], int nombre_vols);
void afficherPassagers(struct Vol tableau_vols[], int numero_vol);

int main()
{
    char ligne[1024];  // Supposons que la longueur maximale d'une ligne est de 1024 caractères
    char* nom_fichier = "data_vols.csv";
    FILE* pt_fichier = fopen(nom_fichier, "r");

    if (pt_fichier == NULL)
    {
        printf("\n%s Open Failed", nom_fichier);
        return 1; // Arrêt en cas d'erreur d'ouverture
    }

    // Ignorer la première ligne (en-têtes)
    if (fgets(ligne, sizeof(ligne), pt_fichier) == NULL) {
        fclose(pt_fichier);
        return 1; // Gérer le cas où le fichier est vide ou ne contient pas d'en-têtes
    }

    struct Vol tableau_vols[MAX_FLIGHTS];

    int nombre_vols = 0;  // Initialiser le nombre de vols

    // Lire le CSV
    while (fgets(ligne, sizeof(ligne), pt_fichier) != NULL && nombre_vols < MAX_FLIGHTS)
    {
        // Lire ligne par ligne
        char liste_passagers[1000];
        sscanf(ligne, "%d,%29[^,],%29[^,],%d,%d,%d,%d,%d,%d,%d,%19[^,],\"%999[^\"]\"",
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
               liste_passagers);

        // Extraire les informations des passagers
        char *passager = strtok(liste_passagers, ";");
        int i = 0;
        while (passager != NULL && i < MAX_PASSENGERS_PER_FLIGHT)
        {
            sscanf(passager, "%29[^,],%29[^,],%10[^,],%d,%f",
                   tableau_vols[nombre_vols].passagers[i].nom,
                   tableau_vols[nombre_vols].passagers[i].prenom,
                   tableau_vols[nombre_vols].passagers[i].date_naissance,
                   &tableau_vols[nombre_vols].passagers[i].numero_siege,
                   &tableau_vols[nombre_vols].passagers[i].prix_billet);

            passager = strtok(NULL, ";");
            i++;
        }

        tableau_vols[nombre_vols].nombre_passagers = i;

        nombre_vols++;
    }

    // Fermer le fichier CSV
    fclose(pt_fichier);

    int choix;
    do {
        // Affichage du menu
        printf("\nMenu:\n");
        printf("0- Quitter\n");
        printf("1- Afficher le tableau des vols\n");
        printf("2- Afficher les passagers d'un vol\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 0:
                // Quitter
                break;
            case 1:
                // Afficher le tableau des vols
                afficherTableau(tableau_vols, nombre_vols);
                break;
            case 2:
                // Afficher les passagers d'un vol
                printf("Entrez le numéro du vol : ");
                int numero_vol;
                scanf("%d", &numero_vol);
                afficherPassagers(tableau_vols, numero_vol);
                break;
            default:
                printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choix != 0);

    return 0;
}

void afficherTableau(struct Vol tableau_vols[], int nombre_vols)
{
    printf("Tableau des vols :\n");
    printf("====================================================================================================================================\n");
    printf("| No Vol | Compagnie              | Destination            | Comptoir | Heure debut | Heure fin   | Salle Emb. | Heure debut embarq. | Heure fin embarq. | Heure decollage | Etat vol          | Nombre passagers |\n");
    printf("====================================================================================================================================\n");

    for (int i = 0; i < nombre_vols; i++)
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

void afficherPassagers(struct Vol tableau_vols[], int numero_vol)
{
    printf("\nPassagers du vol %d :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (int i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}

//faire les fonctions pour le panneau d'information
