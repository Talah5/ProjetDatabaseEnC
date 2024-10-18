#include <stdio.h>
#include "table.h"

int main() {
    // Créer une table avec une capacité initiale de 2 lignes
    Table* table = create_table(2);

    // Insérer des lignes
    insert_row(table, 1, "Alice");
    insert_row(table, 2, "Bob");

    // Afficher la table
    printf("Contenu de la table après insertion :\n");
    print_table(table);

    // Insérer plus de lignes pour tester le redimensionnement
    insert_row(table, 3, "Charlie");
    insert_row(table, 4, "Diana");

    // Afficher la table après redimensionnement
    printf("\nContenu de la table après redimensionnement :\n");
    print_table(table);

    // Libérer la mémoire allouée pour la table
    free_table(table);

    return 0;
}
