
# ProjetDBenC

## Description

Ce projet consiste à implémenter une base de données simple en C, avec des fonctionnalités basiques comme les commandes SQL `INSERT` et `SELECT`. Le projet utilisera un **arbre binaire** pour stocker les données et permettra une **persistance des données** sur disque.

Ce projet est réalisé dans le cadre du cours de Langage C et Algorithmie à l'ESGI.

## Structure du projet

Voici la structure actuelle du projet :

- **src/** : Contient les fichiers source du projet (.c).
- **include/** : Contient les fichiers d'en-tête (.h).
- **tests/** : Contiendra les fichiers de test.
- **Makefile** : Utilisé pour compiler automatiquement le projet.

## Installation et Compilation

### Prérequis

Assurez-vous d'avoir installé les outils suivants sur votre machine :

- **gcc** : Un compilateur C.
- **make** : Outil pour automatiser la compilation.

### Étapes

1. **Cloner le dépôt Git** :

   ```bash
   git clone https://github.com/Talah5/ProjetDBenC.git
   cd ProjetDBenC
   ```

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

## Fonctionnalités

- Implémentation des structures de données pour les tables et les lignes.
- Commande SQL `INSERT` pour ajouter des données dans la table.
- Commande SQL `SELECT` pour interroger les données dans la table.
- Utilisation d'un **arbre binaire** pour optimiser le stockage et la recherche de données.
- Persistance des données sur disque pour conserver les informations même après l'arrêt du programme.

## Dépendances

Aucune dépendance externe requise. Le projet utilise uniquement le compilateur C (`gcc`) et `make`.

## Tests

Des tests seront implémentés dans le répertoire `tests/`. Pour l'instant, ils ne sont pas encore disponibles.

## Contributeurs

Projet réalisé par **Talah** dans le cadre du cours Langage C et Algorithmie à l'ESGI.

## Licence

Ce projet est sous licence libre. Vous êtes libre de le modifier et de le distribuer, mais veuillez respecter les droits d'auteur.
