#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// function to create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find inorder predecessor (largest value in left subtree)
struct node* inOrderPredecessor(struct node* root) {
    root = root->left;                 // Step into left subtree
    while(root->right != NULL) {       // Keep going right until the last node
        root = root->right;
    }
    return root;                       // This is the inorder predecessor
}

// Function to delete a node from BST
struct node* deletenode(struct node* root, int value) {
    // Base case: if tree is empty
    if(root == NULL) return NULL;

    // Step 1: Search for the node
    if(value < root->data) {
        // Value lies in left subtree → recurse left
        root->left = deletenode(root->left, value);
    }
    else if(value > root->data) {
        // Value lies in right subtree → recurse right
        root->right = deletenode(root->right, value);
    }
    else {
        // Step 2: Node found → apply deletion strategy

        // Case A: Node has no children (leaf node)
        if(root->left == NULL && root->right == NULL) {
            free(root);                // Free memory
            return NULL;               // Return NULL to parent
        }

        // Case B: Node has only one child
        else if(root->left == NULL) {
            // Only right child exists
            struct node* temp = root->right;
            free(root);                // Delete current node
            return temp;               // Return right child to parent
        }
        else if(root->right == NULL) {
            // Only left child exists
            struct node* temp = root->left;
            free(root);                // Delete current node
            return temp;               // Return left child to parent
        }

        // Case C: Node has two children
        else {
            // Find inorder predecessor (largest in left subtree)
            struct node* iPre = inOrderPredecessor(root);

            // Copy predecessor's data into current node
            root->data = iPre->data;

            // Delete the predecessor node recursively
            root->left = deletenode(root->left, iPre->data);
        }
    }
    return root;   // Return updated root pointer
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

    //delete a node 
    deletenode(p,19);

    printf("Inorder Traversal (After Deletion): ");
    Inorder(p);
    printf("\n");

    return 0;
}