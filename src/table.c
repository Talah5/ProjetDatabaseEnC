#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

// Fonction pour créer un nœud dans l'arbre binaire
Node* create_node(int id, const char* name) {
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Erreur : Impossible d'allouer de la mémoire pour un nouveau nœud.\n");
        exit(1);  // Quitte le programme si allocation échoue
    }
    new_node->data.id = id;
    strncpy(new_node->data.name, name, 100);  // Copie le nom de manière sécurisée
    new_node->left = new_node->right = NULL;  // Pas de sous-arbres au départ
    return new_node;
}

// Fonction pour insérer un nœud dans l'arbre binaire
Node* insert_node(Node* root, int id, const char* name) {
    if (root == NULL) {
        return create_node(id, name);  // Crée un nouveau nœud si arbre vide
    }

    // Place le nœud à gauche ou à droite selon l'ID
    if (id < root->data.id) {
        root->left = insert_node(root->left, id, name);
    } else if (id > root->data.id) {
        root->right = insert_node(root->right, id, name);
    } else {
        printf("Info : ID %d déjà présent, insertion ignorée.\n", id);
    }
    return root;  // Retourne la racine sans modification
}

// Fonction pour insérer une ligne dans la table
int insert_row(Table* table, int id, const char* name) {
    table->root = insert_node(table->root, id, name);
    return 1;  // Indique toujours un succès
}

// Recherche un nœud par ID
Row* search_node(Node* root, int id) {
    if (root == NULL) {
        printf("Info : Nœud non trouvé pour l'ID %d.\n", id);
        return NULL;  // Retourne NULL si non trouvé
    }
    if (id == root->data.id) {
        return &root->data;  // Renvoie les données si l'ID correspond
    }
    if (id < root->data.id) {
        return search_node(root->left, id);  // Recherche à gauche
    } else {
        return search_node(root->right, id);  // Recherche à droite
    }
}

// Fonction pour rechercher une ligne dans la table
Row* select_row(const Table* table, int id) {
    return search_node(table->root, id);  // Lance la recherche depuis la racine
}

// Fonction pour afficher l'arbre en ordre croissant
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);
        printf("ID: %d, Nom: %s\n", root->data.id, root->data.name);
        print_inorder(root->right);
    }
}

// Afficher toutes les lignes de la table
void print_table(const Table* table) {
    printf("Affichage de la table :\n");
    print_inorder(table->root);
}

// Créer une table vide
Table* create_table() {
    Table* table = malloc(sizeof(Table));
    if (!table) {
        printf("Erreur : Impossible d'allouer la mémoire pour la table.\n");
        exit(1);
    }
    table->root = NULL;
    return table;
}

// Fonction pour libérer la mémoire de l'arbre
void free_nodes(Node* root) {
    if (root != NULL) {
        free_nodes(root->left);
        free_nodes(root->right);
        free(root);
    }
}

// Libérer la mémoire allouée pour la table
void free_table(Table* table) {
    if (table) {
        printf("Libération de la mémoire de la table.\n");
        free_nodes(table->root);
        free(table);
    }
}

// Fonction pour supprimer un nœud par ID
Node* delete_node(Node* root, int id) {
    if (root == NULL) return root;

    if (id < root->data.id) {
        root->left = delete_node(root->left, id);
    } else if (id > root->data.id) {
        root->right = delete_node(root->right, id);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data.id);
    }
    return root;
}

// Fonction pour supprimer une ligne de la table
int delete_row(Table* table, int id) {
    printf("Suppression de la ligne avec l'ID %d.\n", id);
    if (select_row(table, id) == NULL) {
        printf("Erreur : Aucun élément trouvé avec l'ID %d\n", id);
        return 0;
    }
    table->root = delete_node(table->root, id);
    return 1;
}

// Fonction pour mettre à jour une ligne dans la table
int update_row(Table* table, int id, const char* new_name) {
    Row* row = select_row(table, id);
    if (row != NULL) {
        strncpy(row->name, new_name, 100);
        printf("Mise à jour : ID %d a maintenant le nom %s.\n", id, new_name);
        return 1;
    }
    printf("Erreur : Aucun élément trouvé avec l'ID %d\n", id);
    return 0;
}
