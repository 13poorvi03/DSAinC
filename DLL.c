#include <stdio.h>
#include <stdlib.h>

// Define structure for a doubly linked list node
struct Node {
    int data;              // data field
    struct Node* prev;     // pointer to previous node
    struct Node* next;     // pointer to next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of DLL
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // New node's next points to current head
    newNode->next = *head;

    // If list is not empty, update old head's prev
    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    // Update head to new node
    *head = newNode;
}

// Function to insert at the end of DLL
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    // If list is empty → new node becomes head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link new node at the end
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print DLL forward
void printForward(struct Node* head) {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print DLL backward (using prev links)
void printBackward(struct Node* head) {
    struct Node* temp = head;

    // Go to last node
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    // Traverse backward
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // initially empty list

    // Insert nodes at beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    printForward(head);
    printBackward(head);

    // Insert nodes at end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printForward(head);
    printBackward(head);

    return 0;
}