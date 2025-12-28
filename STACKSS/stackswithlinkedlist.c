#include <stdio.h>
#include <stdlib.h>   // malloc, free ke liye

// Node structure define karte hain
struct Node {
    int data;              // har node ek integer value store karega
    struct Node* next;     // pointer jo next node ko point karega
};

// Stack structure define karte hain
struct Stack {
    struct Node* top;      // stack ke top element ka pointer
    int size;              // stack ka current size
};

// Function to initialize stack
void initStack(struct Stack* s) {
    // Step 1: top ko NULL set karo (empty stack)
    s->top = NULL;
    // Step 2: size ko 0 set karo
    s->size = 0;
}

// Push operation
void push(struct Stack* s, int value) {
    // Step 1: naya node allocate karo
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        // Agar memory allocation fail ho gaya
        printf("Stack overflow\n");
        return;
    }

    // Step 2: naya node ka data set karo
    temp->data = value;
    // Step 3: naya node ka next purane top ko point karega
    temp->next = s->top;
    // Step 4: top ko update karo
    s->top = temp;
    // Step 5: size badhao
    s->size++;

    printf("Pushed %d into the stack\n", value);
}

// Pop operation
void pop(struct Stack* s) {
    if (s->top == NULL) {
        // Agar stack empty hai
        printf("Stack underflow\n");
        return;
    }

    // Step 1: current top ko temp mein store karo
    struct Node* temp = s->top;
    // Step 2: user ko batao kaunsa element pop ho raha hai
    printf("Popped %d from the stack\n", temp->data);
    // Step 3: top ko next node pe shift karo
    s->top = s->top->next;
    // Step 4: purane top ko free karo
    free(temp);
    // Step 5: size kam karo
    s->size--;
}

// Peek operation
int peek(struct Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;   // sentinel value
    }
    return s->top->data;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return (s->top == NULL);
}

// Return size of stack
int getSize(struct Stack* s) {
    return s->size;
}

// Main function
int main() {
    // Step 1: ek stack object banate hain
    struct Stack s;
    initStack(&s);

    // Step 2: push operations
    push(&s, 10);
    push(&s, 23);
    push(&s, 25);
    push(&s, 76);
    push(&s, 28);

    // Step 3: pop operation
    pop(&s);

    // Step 4: empty check
    printf("IsEmpty: %d\n", isEmpty(&s));

    // Step 5: size check
    printf("Size: %d\n", getSize(&s));

    // Step 6: peek demonstration
    printf("Peek: %d\n", peek(&s));

    return 0;
}