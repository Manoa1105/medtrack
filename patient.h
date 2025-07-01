#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int age;
    char sexe[10];
    char groupeSanguin[5];
    char maladie[100];
    char traitement[100];
} Patient;

void ajouterPatient();
void afficherPatients();
void rechercherPatient();
void sauvegarderPatient(Patient p);

#endif
