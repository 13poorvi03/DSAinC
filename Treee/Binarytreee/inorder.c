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
int main(){
 
    //constructing the root node - using function 
    // constructing the root node
    struct node *p = createNode(4);
    // constructing the first node
    struct node *p1 = createNode(1);
    //constructing the third node
    struct node *p2 = createNode(6);

    struct node *p3 = createNode(5);

    struct node *p4 = createNode(2);
    //linking the root node with left and right childeren
    p->left = p1;
    p->right = p2;
    p1->left= p3;
    p1->right =p4;

   

   
   printf("root node of the tree : %d -> %d\n", p->data,p->left->data);
   printf("root node of the tree : %d -> %d\n", p->data,p->right->data);
   printf("first node of the tree : %d\n", p1->data);
   printf("second node of the tree : %d\n", p2->data);

    Inorder(p);
    return 0;
}
