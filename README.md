# MedTrack

**MedTrack** est une application C en ligne de commande permettant de gérer des dossiers de patients (ajout, affichage, recherche).  
C’est un projet personnel conçu pour démontrer mes compétences en programmation C et m'entraîner à structurer des projets professionnels.

---

## Fonctionnalités

- 🔹 Ajouter un patient (nom, prénom, âge, sexe, groupe sanguin, maladie, traitement)
- 🔹 Afficher tous les patients enregistrés
- 🔹 Rechercher un patient par son identifiant (ID)
- 🔹 Sauvegarde dans un fichier texte (`patients.txt`)

---

## Technologies utilisées

- Langage : **C**
- Architecture : `main.c`, `patient.c`, `patient.h`
-  Gestion de fichiers avec `fopen`, `fprintf`, `fscanf`
-  Compilation automatisée avec `Makefile`

---

## Compilation

### ✔️ Prérequis
- GCC (compilateur C)
- Make

### Commandes
```bash
make          # Compile le projet
./medtrack    # Exécute le programme
make clean    # Supprime les fichiers objets et l'exécutable
