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

// Function to search a key in BST (Iterative version)
struct node* Iter(struct node* root, int key) {
    // Loop until we reach NULL (end of tree) or find the key
    while (root != NULL) {
        
        // Case 1: If key matches current node's data → FOUND
        if (key == root->data) {
            return root;   // Return pointer to the found node
        }

        // Case 2: If key is smaller than current node's data → go LEFT
        else if (key < root->data) {
            root = root->left;   // Move to left child
        }

        // Case 3: If key is larger than current node's data → go RIGHT
        else {
            root = root->right;  // Move to right child
        }
    }

    // If loop ends → key not found in BST
    return NULL;
}

int main() {
    // Constructing a small BST
    struct node* p = createNode(9);
    struct node * p1 = createNode(4);
    struct node *p2 = createNode(11);
    struct node *p3 = createNode(2);
    struct node *p4= createNode(7);
    struct node *p5= createNode(16);
  
    //linking nodes

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left =p5;
    p2->right =NULL;

    int key = 11;
    struct node* result = Iter(p, key);
    
    if (result != NULL) {
        printf("Key %d found in BST!\n", key);
    } else {
        printf("Key %d not found in BST.\n", key);
    }

    return 0;
}