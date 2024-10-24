#include <stdio.h>
#include "table.h"

int main() {
    // Créer une table (arbre binaire vide)
    Table* table = create_table();

    // Insérer des lignes
    insert_row(table, 1, "Alice");
    insert_row(table, 2, "Bob");
    insert_row(table, 3, "Charlie");

    // Afficher la table
    printf("Contenu de la table après insertion :\n");
    print_table(table);

    // Sauvegarder les données dans un fichier
    save_table_to_file(table, "data.bin");

    // Libérer la mémoire
    free_table(table);

    // Charger les données depuis le fichier
    Table* new_table = create_table();
    load_table_from_file(new_table, "data.bin");

    printf("\nTable après chargement des données :\n");
    print_table(new_table);

    // Tester la suppression
    delete_row(new_table, 2);
    printf("\nTable après suppression de l'ID = 2 :\n");
    print_table(new_table);

    // Libérer la mémoire
    free_table(new_table);

    return 0;
}
