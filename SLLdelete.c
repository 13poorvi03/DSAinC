#include <stdio.h>
#include <stdlib.h>

// Node structure banaya
struct Node {
    int data;               // Node ka data store karega
    struct Node* next;      // Next node ka address store karega
};

// ✅ Head node ko delete karne ka function
void deleteAtHead(struct Node** head) {

    if (*head == NULL) {                 // Agar list empty hai
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;           // temp me current head store kiya
    *head = (*head)->next;               // head ko next node par shift kiya
    free(temp);                          // purane head ko free kar diya
}

// ✅ List ko print karne ka function
void display(struct Node* head) {

    struct Node* temp = head;            // temp pointer traversal ke liye

    while (temp != NULL) {               // Jab tak list khatam na ho
        printf("%d -> ", temp->data);    // current node ka data print karo
        temp = temp->next;               // next node par move karo
    }

    printf("NULL\n");                    // End of list
}

int main() {

    // ✅ Pehla node: 10
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;                     // head node ka data = 10

    // ✅ Dusra node: 20
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 20;               // second node ka data = 20

    // ✅ Teesra node: 30
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 30;         // third node ka data = 30
    head->next->next->next = NULL;       // last node ka next = NULL

    display(head);                       // Original list print: 10 -> 20 -> 30 -> NULL

    deleteAtHead(&head);                 // Head node delete (10 delete)

    display(head);                       // Updated list print: 20 -> 30 -> NULL

    return 0;
}