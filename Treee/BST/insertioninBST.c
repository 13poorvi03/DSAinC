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

// Function to insert a new key into a Binary Search Tree (BST)
struct node* insert(struct node* root, int key) {
    
    // Case 1: If the current subtree is empty (root == NULL)
    // → Create a new node with the given key and return it.
    // This new node becomes the root of this subtree.
    if (root == NULL) {
        return createNode(key);
    }

    // Case 2: If the key is smaller than the current node's data
    // → Recursively insert the key into the LEFT subtree.
    // After insertion, update root->left to point to the new subtree.
    // Hinglish: Agar key chhota hai, left side mein jao aur insert karo.
    if (key < root->data) {
        root->left = insert(root->left, key);
    }

    // Case 3: If the key is greater than the current node's data
    // → Recursively insert the key into the RIGHT subtree.
    // After insertion, update root->right to point to the new subtree.
    // Hinglish: Agar key bada hai, right side mein jao aur insert karo.
    else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    // Case 4: If the key is equal to the current node's data
    // → Do nothing (BST does not allow duplicate values).
    // Hinglish: Agar key barabar hai, ignore karo (duplicates not allowed).

    // Finally, return the root pointer (unchanged for this level).
    // This ensures the tree structure is maintained correctly.
    return root;
}


// Inorder traversal
void Inorder(struct node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

int main() {
    // Constructing nodes with names p, p1, p2...
    struct node *p  = createNode(9);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(11);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(7);
    struct node *p5 = createNode(19);
    struct node *p6 = createNode(5);
    struct node *p7 = createNode(8);
    struct node *p8 = createNode(14);

    // Linking manually (like your earlier style)
    p->left  = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p4->left = p6;
    p4->right = p7;
    p2->right = p5;
    p5->left = p8;

    printf("Inorder Traversal (Manual Linking): ");
    Inorder(p);
    printf("\n");

    // Now test insertion
    insert(p, 10);   // Insert new node with value 10
    insert(p, 1);    // Insert new node with value 1

    printf("Inorder Traversal (After Insertion): ");
    Inorder(p);
    printf("\n");

    return 0;
}