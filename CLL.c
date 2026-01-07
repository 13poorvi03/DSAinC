#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
struct Node {
    int data;              // data field
    struct Node* next;     // pointer to next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of Circular Linked List
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        // First node → points to itself
        *head = newNode;
        newNode->next = *head;
        return;
    }

    // Traverse to last node
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Link new node at end
    temp->next = newNode;
    newNode->next = *head;  // last node points back to head
}

// Function to insert at beginning of Circular Linked List
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    // Traverse to last node
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // New node points to current head
    newNode->next = *head;

    // Last node points to new node
    temp->next = newNode;

    // Update head
    *head = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *curr = *head, *prev = NULL;

    // Case 1: Head node itself is to be deleted
    if (curr->data == key) {
        // If only one node
        if (curr->next == *head) {
            free(curr);
            *head = NULL;
            return;
        }

        // Find last node
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }

        // Last node points to next of head
        temp->next = curr->next;
        *head = curr->next;
        free(curr);
        return;
    }

    // Case 2: Other node
    prev = curr;
    curr = curr->next;
    while (curr != *head) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("Node with value %d not found!\n", key);
}

// Function to print Circular Linked List
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(head);

    insertAtBeginning(&head, 5);
    printList(head);

    // Delete nodes
    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 5);
    printList(head);

    return 0;
}