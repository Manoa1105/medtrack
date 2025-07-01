#include <stdio.h>
#include <string.h>
#include "patient.h"

void sauvegarderPatient(Patient p) {
    FILE *f = fopen("patients.txt", "a");
    if (f == NULL) {
        printf("Erreur ouverture fichier.\n");
        return;
    }
    fprintf(f, "%d;%s;%s;%d;%s;%s;%s;%s\n",
        p.id, p.nom, p.prenom, p.age, p.sexe, p.groupeSanguin, p.maladie, p.traitement);
    fclose(f);
}

void ajouterPatient() {
    Patient p;
    printf("ID patient : "); scanf("%d", &p.id);
    printf("Nom : "); scanf("%s", p.nom);
    printf("Prenom : "); scanf("%s", p.prenom);
    printf("Age : "); scanf("%d", &p.age);
    printf("Sexe (H/F) : "); scanf("%s", p.sexe);
    printf("Groupe sanguin : "); scanf("%s", p.groupeSanguin);
    printf("Maladie : "); scanf(" %[^\n]", p.maladie);
    printf("Traitement : "); scanf(" %[^\n]", p.traitement);
    
    sauvegarderPatient(p);
    printf("Patient ajouté avec succès !\n");
}

void afficherPatients() {
    FILE *f = fopen("patients.txt", "r");
    if (f == NULL) {
        printf("Aucun patient enregistré.\n");
        return;
    }

    Patient p;
    printf("\n--- Liste des patients ---\n");
    while (fscanf(f, "%d;%49[^;];%49[^;];%d;%9[^;];%4[^;];%99[^;];%99[^\n]\n",
                  &p.id, p.nom, p.prenom, &p.age, p.sexe, p.groupeSanguin, p.maladie, p.traitement) == 8) {
        printf("ID: %d | %s %s | %d ans | %s | Groupe: %s\nMaladie: %s\nTraitement: %s\n\n",
               p.id, p.nom, p.prenom, p.age, p.sexe, p.groupeSanguin, p.maladie, p.traitement);
    }

    fclose(f);
}

void rechercherPatient() {
    int idRecherche;
    printf("Entrer l'ID du patient à rechercher : ");
    scanf("%d", &idRecherche);

    FILE *f = fopen("patients.txt", "r");
    if (f == NULL) {
        printf("Fichier introuvable.\n");
        return;
    }

    Patient p;
    int trouve = 0;
    while (fscanf(f, "%d;%49[^;];%49[^;];%d;%9[^;];%4[^;];%99[^;];%99[^\n]\n",
                  &p.id, p.nom, p.prenom, &p.age, p.sexe, p.groupeSanguin, p.maladie, p.traitement) == 8) {
        if (p.id == idRecherche) {
            printf("\n--- Patient trouvé ---\n");
            printf("ID: %d | %s %s | %d ans | %s | Groupe: %s\nMaladie: %s\nTraitement: %s\n\n",
                   p.id, p.nom, p.prenom, p.age, p.sexe, p.groupeSanguin, p.maladie, p.traitement);
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Aucun patient avec l'ID %d.\n", idRecherche);
    }

    fclose(f);
}
