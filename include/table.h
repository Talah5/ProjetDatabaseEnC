#ifndef TABLE_H
#define TABLE_H

// Structure représentant une ligne dans la table
typedef struct {
    int id;
    char name[100];  // Exemple : un nom avec un maximum de 100 caractères
} Row;

// Structure pour un nœud de l'arbre binaire
typedef struct Node {
    Row data;
    struct Node* left;
    struct Node* right;
} Node;

// Structure de la table avec un arbre binaire
typedef struct {
    Node* root;  // Racine de l'arbre binaire
} Table;

// Prototypes des fonctions
Table* create_table();
void free_table(Table* table);
int insert_row(Table* table, int id, const char* name);
Row* select_row(const Table* table, int id);
int delete_row(Table* table, int id);  // Nouveau : suppression de ligne
void print_table(const Table* table);
int save_table_to_file(const Table* table, const char* filename);  // Nouveau : persistance
int load_table_from_file(Table* table, const char* filename);  // Nouveau : recharger la table

#endif
