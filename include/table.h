#ifndef TABLE_H
#define TABLE_H

// Structure d'une ligne dans la table
typedef struct {
    int id;
    char name[100];  // Max de 100 caractères 
} Row;

// Structure d'une table
typedef struct {
    Row* rows;       // Tableau dynamique de lignes
    int size;        // Nombre de lignes actuelles
    int capacity;    // Capacité maximale avant réallocation
} Table;

// Prototypes des fonctions
Table* create_table(int capacity);
void free_table(Table* table);
int insert_row(Table* table, int id, const char* name);
void print_table(const Table* table);

#endif
