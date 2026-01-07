#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Function to search a key in BST
struct node* search(struct node* root, int key) {
    // Base case: root is NULL or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // If key is smaller than root's data → search in LEFT subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // Else key is greater → search in RIGHT subtree
    return search(root->right, key);
}

int main() {
    // Constructing a small BST
    struct node* root = createNode(9);
    root->left = createNode(4);
    root->right = createNode(11);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    int key = 11;
    struct node* result = search(root, key);

    if (result != NULL) {
        printf("Key %d found in BST!\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    return 0;
}