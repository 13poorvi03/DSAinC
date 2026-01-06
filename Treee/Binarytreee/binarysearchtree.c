#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;   
};

struct node* createNode(int data){
    struct node* n;                     //creating a node pointer 
    n = (struct node *)malloc(sizeof(struct node));   //allocating memory in the heap
    n->data = data;      // setting the data 
    n->left =NULL;       // setting the left child to null
    n->right =NULL;      // setting the right child to null
    return n;            // finally returning the created node
}


void *Inorder(struct node *root) {
    // Step 0: Check if the current node exists (not NULL)
    if (root != NULL) {

        
        Inorder(root->left);

        printf("%d ", root->data);
        
        Inorder(root->right);
    }
}

// Function to check if a binary tree is a valid BST
int isBST(struct node* root) {
    // 'prev' keeps track of the previously visited node in inorder traversal
    // It is declared static so its value persists across recursive calls
    static struct node* prev = NULL;

    // Step 0: Base condition → if current node is not NULL
    if (root != NULL) {

        // Step 1: Recursively check the LEFT subtree
        // If left subtree is not BST, return false (0)
        if (!isBST(root->left)) {
            return 0;
        }

        // Step 2: Check current node with the previously visited node
        // In inorder traversal, values must be strictly increasing
        if (prev != NULL && root->data <= prev->data) {
            // If current node's value is smaller/equal than previous → Not BST
            return 0;
        }

        // Step 3: Update 'prev' to current node before moving to right subtree
        prev = root;

        // Step 4: Recursively check the RIGHT subtree
        return isBST(root->right);
    }
    else {
        // Step 5: If root is NULL → valid (empty subtree is BST)
        return 1;
    }
}


int main(){
 
    //constructing the root node - using function 
    // constructing the root node
    struct node *p = createNode(9);
    // constructing the first node
    struct node *p1 = createNode(4);
    //constructing the third node
    struct node *p2 = createNode(11);

    struct node *p3 = createNode(2);

    struct node *p4 = createNode(7);
    struct node *p5 = createNode(19);
    struct node *p6 = createNode(5);
    struct node *p7 = createNode(8);
    struct node *p8 = createNode(14);
    //linking the root node with left and right childeren
    p->left = p1;
    p->right = p2;
    p1->left= p3;
    p1->right = p4;
    p2->left= NULL;
    p2->right = p5;
    p3->left = NULL;
    p3->right = NULL;
    p4->left = p6;
    p4->right = p7;
    p5->left = p8;
    p5->right = NULL;
   

   
   printf("root node of the tree : %d -> %d\n", p->data,p->left->data);
   printf("root node of the tree : %d -> %d\n", p->data,p->right->data);
   printf("first node of the tree : %d\n", p1->data);
   printf("second node of the tree : %d\n", p2->data);
    
     Inorder(p);
     printf("\n");
    printf("%d",isBST(p));
    
    return 0;
}
