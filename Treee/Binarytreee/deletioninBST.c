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

// Inorder traversal (Left → Root → Right)
void Inorder(struct node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

// Function to find minimum value node in a subtree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int key) {
    // Base case: empty tree
    if (root == NULL) return root;

    // Step 1: Traverse to find the node
    if (key < root->data) {
        root->left = deleteNode(root->left, key);   // go left
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key); // go right
    }
    else {
        // Found the node to delete

        // Case 1: Node with only one child or no child
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

        // Case 2: Node with two children
        // Find inorder successor (smallest in right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
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

    printf("Inorder Traversal (Initial Tree): ");
    Inorder(p);
    printf("\n");

    // Now test deletion
    printf("Deleting 9 (root)...\n");
    p = deleteNode(p, 9);

    printf("Inorder Traversal (After Deletion of 9): ");
    Inorder(p);
    printf("\n");

    printf("Deleting 4...\n");
    p = deleteNode(p, 4);

    printf("Inorder Traversal (After Deletion of 4): ");
    Inorder(p);
    printf("\n");

    return 0;
}