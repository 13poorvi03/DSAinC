#include <stdio.h>
#include <stdlib.h>

// ✅ Node structure in C
struct Node {
    int data;
    struct Node* next;
};

// ✅ Create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// ✅ Delete the last node of the linked list
void deleteNodeAtEnd(struct Node** head) {

    // ✅ Case 1: List is empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // ✅ Case 2: Only one node in the list
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* second_last = *head;

    // ✅ Move until second_last->next->next becomes NULL
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    // ✅ Now second_last points to second last node
    struct Node* temp = second_last->next;  // last node

    second_last->next = NULL;  // Make second_last the last node

    free(temp);  // delete last node
}

// ✅ Display the linked list
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {

    // ✅ Creating a sample linked list: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    display(head);  // Print original list

    deleteNodeAtEnd(&head);  // Delete last node

    display(head);  // Print updated list

    return 0;
}