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

// Inorder Traversal
void Inorder(struct node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

// Function to find minimum value node (used for inorder successor)
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;

    // Case 1: Key is smaller → go LEFT
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    // Case 2: Key is larger → go RIGHT
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    // Case 3: Key matches → delete this node
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children → get inorder successor
        struct node* temp = minValueNode(root->right);

        // Copy inorder successor's data to this node
        root->data = temp->data;

        // Delete inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    // Construct BST
    struct node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);
    root->left->left = createNode(20);
    root->left->right = createNode(40);
    root->right->left = createNode(60);
    root->right->right = createNode(80);

    printf("Inorder before deletion: ");
    Inorder(root);
    printf("\n");

    // Delete node 20 (leaf)
    root = deleteNode(root, 20);

    // Delete node 30 (one child)
    root = deleteNode(root, 30);

    // Delete node 50 (two children)
    root = deleteNode(root, 50);

    printf("Inorder after deletion: ");
    Inorder(root);
    printf("\n");

    return 0;
}