#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

// Créer une table avec une capacité initiale
Table* create_table(int capacity) {
    Table* table = malloc(sizeof(Table));
    if (!table) {
        fprintf(stderr, "Erreur d'allocation mémoire pour la table.\n");
        exit(EXIT_FAILURE);
    }
    table->rows = malloc(capacity * sizeof(Row));
    if (!table->rows) {
        fprintf(stderr, "Erreur d'allocation mémoire pour les lignes.\n");
        free(table);
        exit(EXIT_FAILURE);
    }
    table->size = 0;
    table->capacity = capacity;
    return table;
}

// Libérer la mémoire utilisée par la table
void free_table(Table* table) {
    if (table) {
        free(table->rows);
        free(table);
    }
}

// Insérer une nouvelle ligne dans la table
int insert_row(Table* table, int id, const char* name) {
    if (table->size >= table->capacity) {
        // Redimensionner la table si la capacité est atteinte
        table->capacity *= 2;
        table->rows = realloc(table->rows, table->capacity * sizeof(Row));
        if (!table->rows) {
            fprintf(stderr, "Erreur lors du redimensionnement de la table.\n");
            exit(EXIT_FAILURE);
        }
    }
    // Ajouter la nouvelle ligne
    table->rows[table->size].id = id;
    strncpy(table->rows[table->size].name, name, 100);
    table->size++;
    return 1;  
}

// Afficher la table
void print_table(const Table* table) {
    for (int i = 0; i < table->size; i++) {
        printf("ID: %d, Name: %s\n", table->rows[i].id, table->rows[i].name);
    }
}
