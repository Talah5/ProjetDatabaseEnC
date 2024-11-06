#ifndef TABLE_H
#define TABLE_H

// Définition de la structure représentant une ligne dans la table
// Chaque enregistrement contient un identifiant unique et un nom
typedef struct {
    int id;                // Identifiant de l'enregistrement (unique)
    char name[100];        // Nom de l'enregistrement (jusqu'à 100 caractères)
} Record;

// Définition d'un nœud pour notre arbre binaire de recherche
typedef struct Node {
    Record data;           // Les données stockées dans le nœud
    struct Node* left;     // Pointeur vers le sous-arbre gauche
    struct Node* right;    // Pointeur vers le sous-arbre droit
} Node;

// Création d'un nouveau nœud avec l'ID et le nom fourni
Node* create_node(int id, const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node)); // Allouer de la mémoire pour un nouveau nœud
    if (new_node == NULL) {
        printf("Erreur : allocation mémoire échouée\n"); // Message d'erreur si allocation échoue
        return NULL; // On retourne NULL en cas d'erreur
    }
    new_node->data.id = id;
    strncpy(new_node->data.name, name, 100); // Copier le nom dans le champ de données
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insertion d'un nœud dans l'arbre
Node* insert_node(Node* root, int id, const char* name) {
    if (root == NULL) {
        return create_node(id, name); // Si l'arbre est vide, on crée un nouveau nœud
    }
    // On décide où insérer en fonction de l'ID
    if (id < root->data.id) {
        root->left = insert_node(root->left, id, name);
    } else if (id > root->data.id) {
        root->right = insert_node(root->right, id, name);
    } else {
        printf("ID déjà existant dans l'arbre !\n"); // Message pour gérer les doublons
    }
    return root;
}

// Suppression d'un nœud par ID (non implémentée complètement)
Node* delete_node(Node* root, int id) {
    // Pour l'instant, juste une base de suppression
    printf("Suppression pas encore implémentée\n");
    return root; // On retourne la racine inchangée
}

// Affichage en ordre croissant (par ID)
void print_inorder(Node* root) {
    if (root != NULL) {
        print_inorder(root->left);   // Parcours à gauche
        printf("ID: %d, Nom: %s\n", root->data.id, root->data.name); // Affiche le nœud courant
        print_inorder(root->right);  // Parcours à droite
    }
}

// Libérer la mémoire de l'arbre (fonction de libération de mémoire)
void free_tree(Node* root) {
    if (root != NULL) {
        free_tree(root->left);   // Libérer le sous-arbre gauche
        free_tree(root->right);  // Libérer le sous-arbre droit
        free(root);              // Libérer le nœud lui-même
    }
}

#endif
