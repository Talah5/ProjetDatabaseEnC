#ifndef TABLE_H
#define TABLE_H

// Structure représentant une ligne dans la table
typedef struct {
    int id;
    char name[100];  // Un nom avec un maximum de 100 caractères
} Record;

// Structure pour un nœud dans l'arbre binaire
typedef struct Node {
    Record data;
    struct Node* left;
    struct Node* right;
} Node;

// Prototypes des fonctions
Node* create_node(int id, const char* name);
Node* insert_node(Node* root, int id, const char* name);
Node* delete_node(Node* root, int id);
void print_inorder(Node* root);
void free_tree(Node* root);

#endif
