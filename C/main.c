#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Déclaration des constantes et structures
#define MAX_FLIGHTS 100
#define MAX_PASSENGERS_PER_FLIGHT 100

// Structure représentant un passager
struct Passager
{
    char nom[50];
    char prenom[50];
    char date_naissance[11];
    int numero_siege;
    float prix_billet;
};

// Structure représentant un vol
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

// Prototypes des fonctions
void structure(struct Vol tableau_vols[], int *nombre_vols);
void menu(struct Vol tableau_vols[], int nombre_vols, int nombre_passagers);
void tableau_information(struct Vol tableau_vols[], int nombre_vols);
void afficherPassagers(struct Vol tableau_vols[], int numero_vol);
void afficherVolHeure(struct Vol tableau_vols[], int heure, int nombre_vols);
void afficherDestination(struct Vol tableau_vols[], int nombre_vols);
void afficherCompagnie(struct Vol tableau_vols[], int nombre_vols);
void trieprix (struct Vol tableau_vols[],int numero_vol);

 void trienom(struct Vol tableau_vols[], int numero_vol);

// Fonction principale
int main()
{
    // Déclaration d'un tableau de structures de type Vol
    struct Vol tableau_vols[MAX_FLIGHTS];
    int nombre_vols = 0;
    int nombre_passagers = 0;

    // Charger les données à partir du CSV
    structure(tableau_vols, &nombre_vols);

    // Afficher le menu
    menu(tableau_vols, nombre_vols, nombre_passagers);

    return 0;
}

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

// Afficher le menu principal
void menu(struct Vol tableau_vols[], int nombre_vols, int nombre_passagers) //TOM
{
    int choix;

    // Boucle principale du menu
    do
    {
        // Affichage des options du menu principal
        printf("\nMenu:\n");
        printf("0- Quitter\n");
        printf("1- Afficher le tableau des vols\n");
        printf("2- Rechercher un vol\n");
        printf("3- Afficher les passagers d'un vol\n");
        printf("4- Trier les billets par prix\n ");

        printf("6- trier alphabetiquement les noms");
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
                printf("\nRechercher un vol:\n");
                printf("0- Retour au menu principal\n");
                printf("1- Afficher les heures d'un vol\n");
                printf("2- Afficher les destinations d'un vol\n");
                printf("3- Afficher les compagnies\n");
                printf("4- Trier les billets par prix\n ");

                printf("6- trier alphabetiquement les noms");
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

                case 4:
                    // Trier les billets
                    trieprix(tableau_vols, nombre_vols);
                    break;




                default:
                    printf("Choix non valide. Veuillez réessayer.\n");
                }

            } while (sousChoix != 0);

            break;
        }

        case 3:
            // Afficher les passagers d'un vol
            printf("Entrez le numéro du vol : ");
            int numero_vol;
            scanf("%d", &numero_vol);
            afficherPassagers(tableau_vols, numero_vol);
            break;

        case 4:
            trieprix(tableau_vols, nombre_vols);
            break;

        case 6:
            // trie alphabetiquement par nom
            trienom(tableau_vols, numero_vol);
            break;


        default:
            printf("Choix non valide. Veuillez réessayer.\n");
        }

    } while (choix != 0);
}



// Fonction pour afficher le tableau d'information
void tableau_information(struct Vol tableau_vols[], int nombre_vols) //TOM
{
    // Définir l'heure actuelle
    int heureActuelle = 1900;

    printf("Tableau des vols dans les 3 heures suivantes à partir de %02d:%02d :\n", heureActuelle / 100, heureActuelle % 100);
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

            // Afficher le comptoir et les heures d'enregistrement si dans la plage spécifiée
            if (tableau_vols[i].heure_debut_enregistrement - 30 < heureActuelle && heureActuelle + 10 >= tableau_vols[i].heure_fin_enregistrement)
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

            // Afficher la salle d'embarquement et les heures d'embarquement si dans la plage spécifiée
            if (tableau_vols[i].heure_debut_embarquement - 30 < heureActuelle && heureActuelle + 10 >= tableau_vols[i].heure_fin_embarquement)
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



// Afficher les passagers d'un vol
void afficherPassagers(struct Vol tableau_vols[], int numero_vol) // A modifier par enzo
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
    char destination;
    scanf("%s", &destination);

    int destinationTrouvee = 0;

    for (int i = 0; i < nombre_vols; i++)
    {
        if (tableau_vols[i].destination[0] == destination)
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

    for (int i = 0; i < nombre_vols; i++)
    {
        if (strcmp(tableau_vols[i].compagnie, compagnie) == 0)
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

void trieprix(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            if (tableau_vols[numero_vol - 1].passagers[j].prix_billet > tableau_vols[numero_vol - 1].passagers[min].prix_billet)
            {
                min = j;
            }
        }

        // Échange des passagers (et non des prix directement)
        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    // Affichage des passagers triés
    printf("\nPassagers du vol %d (triés par prix) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}

/*void trieage(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            if (tableau_vols[numero_vol - 1].passagers[j].date_naissance < tableau_vols[numero_vol - 1].passagers[min].date_naissance)
            {
                min = j;
            }
        }

        // Échange des passagers (et non des prix directement)
        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    // Affichage des passagers triés
    printf("\nPassagers du vol %d (triés par prix) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < tableau_vols[numero_vol - 1].nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}
*/
 void trienom(struct Vol tableau_vols[], int numero_vol)
{
    int i, j, min;
    struct Passager tmp_passager;

    int nombre_passagers = tableau_vols[numero_vol - 1].nombre_passagers;

    for (i = 0; i < nombre_passagers - 1; i++)
    {
        min = i;

        for (j = i + 1; j < nombre_passagers; j++)
        {
            if (tableau_vols[numero_vol - 1].passagers[j].nom > tableau_vols[numero_vol - 1].passagers[min].nom)
            {
                min = j;
            }
        }

        // Échange des passagers (et non des prix directement)
        tmp_passager = tableau_vols[numero_vol - 1].passagers[i];
        tableau_vols[numero_vol - 1].passagers[i] = tableau_vols[numero_vol - 1].passagers[min];
        tableau_vols[numero_vol - 1].passagers[min] = tmp_passager;
    }

    // Affichage des passagers triés
    printf("\nPassagers du vol %d (triés par nom) :\n", numero_vol);
    printf("===========================================================\n");
    printf("| Nom                | Prenom             | Date de naissance | Siege | Prix billet |\n");
    printf("===========================================================\n");

    for (i = 0; i < nombre_passagers; i++)
    {
        printf("| %-18s | %-18s | %-17s | %-5d | %-11.2f |\n",
               tableau_vols[numero_vol - 1].passagers[i].nom,
               tableau_vols[numero_vol - 1].passagers[i].prenom,
               tableau_vols[numero_vol - 1].passagers[i].date_naissance,
               tableau_vols[numero_vol - 1].passagers[i].numero_siege,
               tableau_vols[numero_vol - 1].passagers[i].prix_billet);
    }
}
