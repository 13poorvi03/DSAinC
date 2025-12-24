// implementation with linked list 

#include <stdio.h>      // for printf
#include <stdlib.h>     // for malloc, free
#include <limits.h>     // for INT_MIN (used in underflow case)

// ---------------- Node Structure ----------------
// Each node of the linked list will represent one element of the stack.
struct Node {
    int data;              // stores the integer value of the stack element
    struct Node* next;     // pointer to the next node (below current top)
};

// ---------------- Stack Structure ----------------
// This structure keeps track of the stack itself.
struct Stack {
    struct Node* head;     // pointer to the top node of the stack
    int capacity;          // maximum number of elements allowed in stack
    int currSize;          // current number of elements in stack
};

// ---------------- Initialize Stack ----------------
// Function to initialize a stack with given capacity
void initStack(struct Stack* st, int c) {
    st->capacity = c;      // set maximum size
    st->currSize = 0;      // initially stack is empty
    st->head = NULL;       // no nodes yet, so head = NULL
}

// ---------------- Check if Stack is Empty ----------------
int isEmpty(struct Stack* st) {
    return st->head == NULL;   // if head is NULL, stack has no elements
}

// ---------------- Check if Stack is Full ----------------
int isFull(struct Stack* st) {
    return st->currSize == st->capacity;   // full when current size == capacity
}

// ---------------- Push Operation ----------------
// Insert a new element at the top of the stack
void push(struct Stack* st, int data) {
    if (isFull(st)) {   // check overflow
        printf("Overflow\n");
        return;
    }

    // Step 1: Create a new node dynamically
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;        // assign data to new node
    new_node->next = st->head;    // link new node to current top

    // Step 2: Update head to point to new node (new top)
    st->head = new_node;

    // Step 3: Increase stack size
    st->currSize++;
}

// ---------------- Pop Operation ----------------
// Remove the top element from the stack and return its value
int pop(struct Stack* st) {
    if (isEmpty(st)) {   // check underflow
        printf("Underflow\n");
        return INT_MIN;  // return special value when stack is empty
    }

    // Step 1: Store current top node in temp
    struct Node* temp = st->head;

    // Step 2: Get data of top node
    int poppedElement = temp->data;

    // Step 3: Move head to next node (removing top)
    st->head = st->head->next;

    // Step 4: Free memory of old top node
    free(temp);

    // Step 5: Decrease stack size
    st->currSize--;

    // Step 6: Return popped element
    return poppedElement;
}

// ---------------- Top Operation ----------------
// Return the value of the top element without removing it
int top(struct Stack* st) {
    if (isEmpty(st)) {   // if stack empty
        printf("Underflow\n");
        return INT_MIN;
    }
    return st->head->data;   // head node contains top element
}

// ---------------- Size Operation ----------------
// Return current number of elements in stack
int size(struct Stack* st) {
    return st->currSize;
}

// ---------------- Main Function ----------------
int main() {
    struct Stack st;          // create stack object
    initStack(&st, 5);        // initialize stack with capacity = 5

    // Push operations
    push(&st, 10);   // stack = [10]
    push(&st, 20);   // stack = [20, 10]
    push(&st, 30);   // stack = [30, 20, 10]

    // Top element check
    printf("Top element: %d\n", top(&st));   // should print 30

    // Pop operation
    printf("Popped: %d\n", pop(&st));        // removes 30, prints 30

    // Top element again
    printf("Top element: %d\n", top(&st));   // now top is 20

    // Current size check
    printf("Current size: %d\n", size(&st)); // should print 2

    return 0;
}