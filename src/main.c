#include <stdio.h>
#include "table.h"  // Assure-toi que le nom de ton fichier d'en-tête est correct

int main() {
    // Initialiser une table d'enregistrements vide (arbre binaire)
    Table* records = create_table();

    if (records == NULL) {
        fprintf(stderr, "Erreur : Impossible d'initialiser la table.\n");
        return 1;
    }

    // Insérer des données d'utilisateur
    insert_row(records, 1001, "Bastien");
    insert_row(records, 1002, "Sebastien");
    insert_row(records, 1003, "Michel");

    // Afficher les enregistrements dans la table
    printf("Contenu de la table d'enregistrements :\n");
    print_table(records);

    // Sauvegarder les données dans un fichier binaire
    if (!save_table_to_file(records, "records.dat")) {
        fprintf(stderr, "Erreur : Impossible de sauvegarder les enregistrements dans le fichier.\n");
    }

    // Libérer la mémoire de la table actuelle
    free_table(records);

    // Charger les enregistrements à partir du fichier dans une nouvelle table
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

    // Supprimer un enregistrement par ID et afficher la table mise à jour
    if (!delete_row(loaded_records, 1002)) {
        fprintf(stderr, "Erreur : Enregistrement avec ID 1002 introuvable.\n");
    } else {
        printf("\nTable après suppression de l'enregistrement avec ID 1002 :\n");
        print_table(loaded_records);
    }

    // Libérer la mémoire et quitter
    free_table(loaded_records);

    return 0;
}
