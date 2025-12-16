// insert at end (C version)

#include <stdio.h>
#include <stdlib.h>

// Node structure: stores data + pointer to next node
struct Node {
    int data;               // data part of node
    struct Node* next;      // link to next node
};

// Global pointers used for operations
struct Node *first = NULL, *temp, *ttemp;

// Create the first node of the linked list
void createFirst(int x) {
    first = (struct Node*)malloc(sizeof(struct Node));   // allocate memory
    first->data = x;                                     // store value
    first->next = NULL;                                  // first node points to NULL
}

// Insert a new node at the end of the list
void addNodeAtEnd(int x) {

    temp = first;                // start from head

    // move temp to the last node
    while (temp->next != NULL) {
        temp = temp->next;   // temp->next contains the address of the next node, so temp moves forward to that node  
    }

    // create new node
    ttemp = (struct Node*)malloc(sizeof(struct Node));
    ttemp->data = x;             // assign value
    ttemp->next = NULL;          // new node becomes last node

    temp->next = ttemp;          // link last node to new node
}

// Print all nodes of the linked list
void printList() {
    ttemp = first;               // start from head
    while (ttemp != NULL) {      // traverse till end
        printf("%d ", ttemp->data);
        ttemp = ttemp->next;
    }
    printf("\n");
}

int main() {
    int x;

    // create first node
    x = 10;
    createFirst(x);
    printList();                 // 10

    // insert nodes at end
    x = 20;
    addNodeAtEnd(x);
    printList();                 // 10 20

    x = 30;
    addNodeAtEnd(x);
    printList();                 // 10 20 30

    return 0;
}