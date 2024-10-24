#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

// Créer un nœud de l'arbre binaire
Node* create_node(int id, const char* name) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Erreur : Impossible d'allouer de la mémoire.\n");
        exit(1);  // Quitte le programme en cas d'échec
    }
    new_node->data.id = id;
    strncpy(new_node->data.name, name, 100);  // Copie le nom dans la structure
    new_node->left = new_node->right = NULL;  // Pas de sous-arbres pour le moment
    return new_node;
}

// Insérer un nœud dans l'arbre binaire
Node* insert_node(Node* root, int id, const char* name) {
    if (root == NULL) {
        return create_node(id, name);  // Si l'arbre est vide, crée un nouveau nœud
    }

    // Insère à gauche ou à droite selon la valeur de l'ID
    if (id < root->data.id) {
        root->left = insert_node(root->left, id, name);
    } else if (id > root->data.id) {
        root->right = insert_node(root->right, id, name);
    }
    return root;  // Retourne la racine (inchangée)
}

int insert_row(Table* table, int id, const char* name) {
    table->root = insert_node(table->root, id, name);  // Insère dans la racine
    return 1;  // Toujours un succès (dans ce cas)
}

// Rechercher une ligne par ID dans l'arbre binaire
Row* search_node(Node* root, int id) {
    if (root == NULL) {
        return NULL;  // Retourne NULL si la ligne n'est pas trouvée
    }
    if (id == root->data.id) {
        return &root->data;  // Retourne les données si l'ID correspond
    }
    if (id < root->data.id) {
        return search_node(root->left, id);  // Cherche dans le sous-arbre gauche
    } else {
        return search_node(root->right, id);  // Cherche dans le sous-arbre droit
    }
}

Row* select_row(const Table* table, int id) {
    return search_node(table->root, id);  // Recherche une ligne à partir de la racine
}

// Afficher les lignes de l'arbre en ordre croissant
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);  // Affiche le sous-arbre gauche
        printf("ID: %d, Nom: %s\n", root->data.id, root->data.name);  // Affiche le nœud courant
        print_inorder(root->right);  // Affiche le sous-arbre droit
    }
}

void print_table(const Table* table) {
    print_inorder(table->root);  // Affiche toutes les lignes
}

// Créer une table (arbre binaire vide)
Table* create_table() {
    Table* table = malloc(sizeof(Table));  // Alloue de la mémoire pour la table
    if (!table) {
        printf("Erreur : Impossible d'allouer de la mémoire pour la table.\n");
        exit(1);  // Quitte le programme en cas d'échec
    }
    table->root = NULL;  // L'arbre est vide au début
    return table;
}

// Libérer la mémoire allouée à l'arbre binaire
void free_nodes(Node* root) {
    if (root != NULL) {
        free_nodes(root->left);  // Libère le sous-arbre gauche
        free_nodes(root->right);  // Libère le sous-arbre droit
        free(root);  // Libère le nœud courant
    }
}

void free_table(Table* table) {
    if (table) {
        free_nodes(table->root);  // Libère tous les nœuds
        free(table);  // Libère la structure de la table elle-même
    }
}

// Supprimer un nœud dans l'arbre binaire
Node* delete_node(Node* root, int id) {
    if (root == NULL) return root;

    // Cherche le nœud à supprimer
    if (id < root->data.id) {
        root->left = delete_node(root->left, id);
    } else if (id > root->data.id) {
        root->right = delete_node(root->right, id);
    } else {
        // Nœud trouvé
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Nœud avec deux enfants : trouve le plus petit dans le sous-arbre droit
        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;  // Remplace les données par celles du successeur
        root->right = delete_node(root->right, temp->data.id);  // Supprime le successeur
    }
    return root;
}

int delete_row(Table* table, int id) {
    if (select_row(table, id) == NULL) {
        printf("Erreur : Aucun élément trouvé avec l'ID = %d\n", id);
        return 0;  // Échec : ligne non trouvée
    }
    table->root = delete_node(table->root, id);  // Supprime la ligne
    return 1;  // Succès
}

// Mettre à jour une ligne existante
int update_row(Table* table, int id, const char* new_name) {
    Row* row = select_row(table, id);  // Recherche la ligne
    if (row != NULL) {
        strncpy(row->name, new_name, 100);  // Met à jour le nom
        return 1;  // Succès
    }
    printf("Erreur : Aucun élément trouvé avec l'ID = %d\n", id);
    return 0;  // Échec
}
