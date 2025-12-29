
// stacks implementation using array 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Stack structure
struct Stack {
    int* arr;   // Dynamic array for stack elements
    int size;   // Maximum size of stack
    int top;    // Index of top element
};

// Function to initialize stack
void initStack(struct Stack* s, int size) {  //struct Stack* s ----- func ko stack ka address diya jta h taki changes directly usi stack mae ho 
    // Yahan 's' ek pointer hai, isliye arrow (->) use karna padega
    s->size = size;             //s is a pointer jo stack ko point kr rha h  jb function call hoga to s mae struct ka address store h toa hum s->mumber likhne se hum s (struct) ke member ko access kr payenge   
    s->top = -1;                   
    s->arr = (int*)malloc(size * sizeof(int)); 
}

// Push function
void push(struct Stack* s, int value) {
    // Arrow (->) use karte hain kyunki 's' ek pointer hai
    if (s->top == s->size - 1) {   // Agar stack full hai
        printf("overflow\n");
        return;
    } else {
        s->top++;                  // Top ko increment karo
        s->arr[s->top] = value;    // Value insert karo
        printf("Pushed %d into the stack\n", value);
    }
}

// Pop function
void pop(struct Stack* s) {
    if (s->top == -1) {            // Agar stack empty hai
        printf("stack underflow\n");
    } else {
        printf("popped %d from the stack\n", s->arr[s->top]);
        s->top--;                  // Top ko decrement karo
    }
}

// Peek function
int peek(struct Stack* s) {
    if (s->top == -1) {
        printf("stack is empty\n");
        return -1;
    } else {
        return s->arr[s->top];     // Top element return karo
    }
}

// Check if stack is empty
bool IsEmpty(struct Stack* s) {
    return s->top == -1;           // Agar top -1 hai toh empty
}

// Current size of stack
int IsSSize(struct Stack* s) {
    return s->top + 1;             // Top + 1 = total elements
}

int main() {
    struct Stack s;                 // Yahan 's' ek object hai
    initStack(&s, 5);               // '&s' pass kiya, matlab pointer gaya function me

    // Agar direct object hota toh dot (.) use karte: s.top
    // Lekin function me pointer gaya hai, isliye arrow (->) use karna zaroori hai

    push(&s, 5);
    push(&s, 6);
    push(&s, 7);
    push(&s, 8);

    pop(&s);   // Pop 8
    pop(&s);   // Pop 7

    printf("%d\n", peek(&s));  // Top element (6)

    // Extra check
    printf("Is stack empty? %s\n", IsEmpty(&s) ? "Yes" : "No");
    printf("Current size of stack: %d\n", IsSSize(&s));

    // Free allocated memory
    free(s.arr);

    return 0;
}