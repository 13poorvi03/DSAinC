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
int main(){
 
    //constructing the root node - using function 
    // constructing the root node
    struct node *p = createNode(2);
    // constructing the first node
    struct node *p1 = createNode(3);
    //constructing the third node
    struct node *p2 = createNode(4);

    //linking the root node with left and right childeren
    p->left = p1;
    p->right = p2;

   printf("root node of the tree : %d -> %d\n", p->data,p->left->data);
   printf("root node of the tree : %d -> %d\n", p->data,p->right->data);
   printf("first node of the tree : %d\n", p1->data);
   printf("second node of the tree : %d\n", p2->data);
   

    return 0;
}












// #include<stdio.h>
// #include<malloc.h>

// struct node{
//     int data;
//     struct node* left;
//     struct node* right;   
// };

// int main(){

//     // constructing the root node
    
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data = 2;
//     p->left = NULL;
//     p->right =NULL;

//     // constructing the first node
//     struct node *p1;
//     p1 = (struct node *)malloc(sizeof(struct node));
//     p1->data = 6;
//     p1->left = NULL;
//     p1->right =NULL;

//     struct node *p2;
//     p2 = (struct node *)malloc(sizeof(struct node));
//     p2->data = 5;
//     p2->left = NULL;
//     p2->right =NULL;
     

//linking the root node with left and right childeren
    // p->left = p1;
    // p->right = p2;

//     printf("%d %d %d ", p->data ,p1->data ,p2->data);
    
//     return 0;
// }