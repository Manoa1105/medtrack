#include <stdio.h>
#include "patient.h"

int main() {
    int choix;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ajouter un patient\n");
        printf("2. Afficher tous les patients\n");
        printf("3. Rechercher un patient\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterPatient(); break;
            case 2: afficherPatients(); break;
            case 3: rechercherPatient(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
