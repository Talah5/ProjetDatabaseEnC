#include <stdio.h>
#include "table.h"  // Assure-toi que le nom de ton fichier d'en-tête est correct !

int main() {
    // Créer une nouvelle table d'enregistrements (un arbre binaire ici)
    Table* records = create_table();
    if (records == NULL) {
        fprintf(stderr, "Erreur : Impossible d'initialiser la table.\n");
        return 1; // On arrête le programme en cas d'erreur
    }

    // Ajout de quelques enregistrements à la main
    printf("Insertion de quelques enregistrements...\n");
    insert_row(records, 1001, "Bastien");
    insert_row(records, 1002, "Sebastien");
    insert_row(records, 1003, "Michel");

    // Afficher tout le contenu de la table
    printf("Contenu de la table d'enregistrements :\n");
    print_table(records);

    // Sauvegarder les données dans un fichier binaire
    printf("Sauvegarde des enregistrements dans le fichier 'records.dat'...\n");
    if (!save_table_to_file(records, "records.dat")) {
        fprintf(stderr, "Erreur : Impossible de sauvegarder les enregistrements dans le fichier.\n");
    }

    // Libérer la mémoire de la table actuelle (important pour éviter les fuites mémoire)
    printf("Libération de la mémoire de la table actuelle.\n");
    free_table(records);

    // Charger les enregistrements à partir du fichier
    printf("Chargement des enregistrements depuis 'records.dat'...\n");
    Table* loaded_records = create_table();
    if (loaded_records == NULL) {
        fprintf(stderr, "Erreur : Impossible d'initialiser la table pour le chargement.\n");
        return 1;
    }

    if (!load_table_from_file(loaded_records, "records.dat")) {
        fprintf(stderr, "Erreur : Impossible de charger les enregistrements à partir du fichier.\n");
        free_table(loaded_records);
        return 1;
    }

    printf("\nEnregistrements chargés depuis le fichier :\n");
    print_table(loaded_records);

    // Suppression d'un enregistrement par ID et affichage de la table mise à jour
    printf("Suppression de l'enregistrement avec ID 1002...\n");
    if (!delete_row(loaded_records, 1002)) {
        fprintf(stderr, "Erreur : Enregistrement avec ID 1002 introuvable.\n");
    } else {
        printf("\nTable après suppression de l'enregistrement avec ID 1002 :\n");
        print_table(loaded_records);
    }

    // Libérer la mémoire et quitter
    printf("Libération de la mémoire de la table chargée et fin du programme.\n");
    free_table(loaded_records);

    return 0;
}
