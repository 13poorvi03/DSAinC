#include <stdio.h>
#include <stdlib.h>

// Node structure: stores data and pointer to next node
struct Node {
    int data;
    struct Node* next;
};

// Global pointers used for operations
struct Node *first = NULL, *temp, *ttemp;

// Create the first node of the linked list
void createFirst(int x) {
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = x;
    first->next = NULL;     // first node points to NULL
}

// Insert a new node at the beginning (head insertion)
void addNodeAtStart(int x) {
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;         // store value
    temp->next = first;     // link new node to old first
    first = temp;           // update head pointer
}

// Traverse and print all nodes
void printList() {
    ttemp = first;          // start from head
    while (ttemp != NULL) { // continue till end
        printf("%d ", ttemp->data);
        ttemp = ttemp->next;
    }
    printf("\n");
}

int main() {
    int x;

    // Create first node
    x = 10;
    createFirst(x);
    printList();

    // Insert more nodes at the beginning
    x = 20;
    addNodeAtStart(x);
    printList();

    x = 30;
    addNodeAtStart(x);
    printList();

    return 0;
}