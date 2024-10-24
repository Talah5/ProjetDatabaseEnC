#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

// Créer un nœud de l'arbre binaire
Node* create_node(int id, const char* name) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erreur d'allocation mémoire pour un nœud.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data.id = id;
    strncpy(new_node->data.name, name, 100);
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insérer un nœud dans l'arbre binaire
Node* insert_node(Node* root, int id, const char* name) {
    if (root == NULL) {
        return create_node(id, name);
    }
    if (id < root->data.id) {
        root->left = insert_node(root->left, id, name);
    } else if (id > root->data.id) {
        root->right = insert_node(root->right, id, name);
    }
    return root;
}

int insert_row(Table* table, int id, const char* name) {
    table->root = insert_node(table->root, id, name);
    return 1;  // Succès
}

// Rechercher une ligne par ID dans l'arbre binaire
Row* search_node(Node* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root ? &root->data : NULL;
    }
    if (id < root->data.id) {
        return search_node(root->left, id);
    } else {
        return search_node(root->right, id);
    }
}

Row* select_row(const Table* table, int id) {
    return search_node(table->root, id);
}

// Parcours infixe pour afficher les lignes
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("ID: %d, Name: %s\n", root->data.id, root->data.name);
        print_inorder(root->right);
    }
}

void print_table(const Table* table) {
    print_inorder(table->root);
}

// Créer une table (arbre binaire vide)
Table* create_table() {
    Table* table = malloc(sizeof(Table));
    if (!table) {
        fprintf(stderr, "Erreur d'allocation mémoire pour la table.\n");
        exit(EXIT_FAILURE);
    }
    table->root = NULL;
    return table;
}

// Libérer la mémoire allouée à l'arbre binaire
void free_nodes(Node* root) {
    if (root != NULL) {
        free_nodes(root->left);
        free_nodes(root->right);
        free(root);
    }
}

void free_table(Table* table) {
    if (table) {
        free_nodes(table->root);
        free(table);
    }
}

// Sauvegarder l'arbre dans un fichier
void save_nodes_to_file(Node* root, FILE* file) {
    if (root != NULL) {
        fwrite(&root->data, sizeof(Row), 1, file);
        save_nodes_to_file(root->left, file);
        save_nodes_to_file(root->right, file);
    }
}

int save_table_to_file(const Table* table, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier pour écriture.\n");
        return 0;
    }
    save_nodes_to_file(table->root, file);
    fclose(file);
    return 1;
}

// Charger les données à partir d'un fichier
int load_table_from_file(Table* table, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier pour lecture.\n");
        return 0;
    }
    Row temp;
    while (fread(&temp, sizeof(Row), 1, file)) {
        insert_row(table, temp.id, temp.name);
    }
    fclose(file);
    return 1;
}

// Supprimer un nœud dans l'arbre binaire
Node* delete_node(Node* root, int id) {
    if (root == NULL) return root;

    if (id < root->data.id) {
        root->left = delete_node(root->left, id);
    } else if (id > root->data.id) {
        root->right = delete_node(root->right, id);
    } else {
        // Nœud à supprimer trouvé
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Deux enfants
        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data.id);
    }
    return root;
}

int delete_row(Table* table, int id) {
    table->root = delete_node(table->root, id);
    return 1;  // Succès
}
