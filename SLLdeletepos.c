
//delete a node at certain position 

#include <stdio.h>
#include <stdlib.h>

//  Node structure in C
struct Node {
    int data;
    struct Node* next;
};

//  Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//  Insert at tail (sirf list banane ke liye)
void insertAtTail(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {          // Agar list empty hai
        *head = newNode;
        return;
    }

    struct Node* temp = *head;    // temp ko head par rakha
    while (temp->next != NULL) {  // Jab tak last node na mil jaye
        temp = temp->next;        // temp ko next par move karte jao
    }

    temp->next = newNode;         // Last node ka next = new node
}

//  Delete node at ANY arbitrary position
void deleteAtPosition(struct Node** head, int position) {

    //  Case 1: List empty
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    //  Case 2: Delete at head (position = 1)
    if (position == 1) {
        struct Node* temp = *head;     // Purana head store kiya
        *head = (*head)->next;         // Head ko next par shift kiya
        free(temp);                    // Purana head free
        return;
    }

    //  Case 3: Delete at any other position
    struct Node* temp = *head;

    /*
         LOOP EXPLANATION
        Hume delete wale node ke *pehle* rukna hota hai.
        Isliye hum (position - 1)th node tak traverse karte hain.

        Example:
        Position = 3 delete karna hai → hume 2nd node par rukna hoga.
    */

    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;            // temp ko aage move karte jao
    }

    //  Agar position list se bahar ho
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    /*
         DELETE LOGIC

        temp → node before the one to delete
        temp->next → node to delete
        temp->next->next → node after delete
    */

    struct Node* nodeToDelete = temp->next;     // Delete hone wala node
    temp->next = temp->next->next;              // Link skip kiya (unlink)
    free(nodeToDelete);                         // Memory free
}

//  Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    //  Creating sample list: 10 -> 20 -> 30 -> 40 -> NULL
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printf("Original List: ");
    display(head);

    // Delete node at position 3 (i.e., delete 30)
    deleteAtPosition(&head, 3);

    printf("After deleting position 3: ");
    display(head);

    return 0;
}