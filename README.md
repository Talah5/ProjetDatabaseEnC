# ProjetDBenC

## Description

Ce projet implémente une **base de données simple** en C, avec des fonctionnalités basiques inspirées des commandes SQL telles que `INSERT`, `SELECT`, `DELETE` et `UPDATE`. Les enregistrements sont stockés dans un **arbre binaire de recherche** pour optimiser les opérations de recherche et d'insertion, et les données peuvent être **persistées sur disque** via un fichier binaire.

Ce projet est réalisé dans le cadre du cours de **Langage C et Algorithmie** à l'ESGI.

## Structure du projet

Voici la structure actuelle du projet :

- **src/** : Contient les fichiers source du projet (.c).
- **include/** : Contient les fichiers d'en-tête (.h).
- **tests/** : Contiendra les fichiers de test.
- **Makefile** : Utilisé pour compiler automatiquement le projet.

## Fonctionnalités

- **Insertion** (`INSERT`) : Ajoute des enregistrements avec un identifiant unique et un nom.
- **Sélection** (`SELECT`) : Recherche un enregistrement par identifiant et affiche les résultats.
- **Affichage** : Affiche tous les enregistrements stockés dans l'arbre binaire par ordre croissant d'identifiants.
- **Mise à jour** (`UPDATE`) : Permet de modifier le nom d'un enregistrement existant.
- **Suppression** (`DELETE`) : Supprime un enregistrement par son identifiant.
- **Persistance des données** : Sauvegarde et chargement des enregistrements depuis un fichier binaire pour conserver les données entre les exécutions du programme.
- **Gestion de la mémoire** : Libération automatique de la mémoire allouée aux enregistrements.

## Structure des fichiers

- **table.h** : Déclarations des structures de données et prototypes des fonctions.
- **table.c** : Implémentation des fonctions de gestion de la table et de l'arbre binaire.
- **main.c** : Programme principal pour exécuter les opérations sur la base de données.

## Installation et Compilation

### Prérequis

Assurez-vous d'avoir les outils suivants installés sur votre machine :

- **gcc** : Compilateur C.
- **make** : Utilisé pour automatiser la compilation.

### Étapes

1. **Cloner le dépôt Git** :

   ```bash
   git clone https://github.com/Talah5/ProjetDBenC.git
   cd ProjetDBenC

2. **Compilation** :
   Utilisez `make` pour compiler le projet.

   ```bash
   make
   ```

3. **Exécution** :
   Après compilation, lancez le programme avec :

   ```bash
   ./mydb
   ```

4. **Nettoyage** :
   Pour supprimer les fichiers objets (.o) et l'exécutable, utilisez :

   ```bash
   make clean
   ```

## Exemple d'utilisation

Une fois le programme lancé, vous pouvez :

1. Insérer des enregistrements dans la base de données.
2. Afficher les enregistrements triés par identifiant.
3. Supprimer ou mettre à jour des enregistrements existants.
4. Sauvegarder les enregistrements dans un fichier binaire pour les charger lors de la prochaine exécution.

## Dépendances

Aucune dépendance externe requise. Le projet utilise uniquement le compilateur C (`gcc`) et `make`.

## Tests

Des tests seront implémentés dans le répertoire `tests/`. Pour l'instant, ils ne sont pas encore disponibles.

## Contributeurs

Projet réalisé par **Bastien HOURY** dans le cadre du cours Langage C et Algorithmie à l'ESGI.

## Licence

Ce projet est sous licence libre. Vous êtes libre de le modifier et de le distribuer, mais veuillez respecter les droits d'auteur.
