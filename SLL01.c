#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
// Each node stores an integer and the address of the next node
struct Node {
    int data;               // data part of node
    struct Node* next;      // link part (points to next node)
};

// Insert a new node at the beginning of the list
// We use struct Node** because we want to modify the original 'first' pointer
void addAfterNode(struct Node** first, int d) {

    // allocate memory for new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = d;         // store value in new node
    temp->next = *first;    // new node will point to old first node

    *first = temp;          // update first pointer to new node
}

// Print all nodes of the linked list
// Traverses from first node to last node
void print(struct Node* first) {

    struct Node* temp = first;   // temp pointer used for traversal

    while (temp != NULL) {       // continue until end of list
        printf("%d ", temp->data);
        temp = temp->next;       // move to next node
    }
    printf("\n");
}

int main() {

    // create first node manually (head node)
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 10;            // assign data
    node1->next = NULL;          // last node points to NULL

    struct Node* first = node1;  // head pointer pointing to first node

    print(first);                // output: 10

    addAfterNode(&first, 12);    // insert at beginning
    print(first);                // output: 12 10

    addAfterNode(&first, 15);    // insert again at beginning
    print(first);                // output: 15 12 10

    return 0;
}