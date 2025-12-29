#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack structure (array-based implementation)
struct Stack {
    char* arr;   // Dynamic array banayenge stack ke characters store karne ke liye
    int size;    // Stack ka maximum size
    int top;     // Top pointer jo stack ke last element ko point karega
};

// Constructor equivalent in C (initialize stack)
struct Stack* createStack(int s) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = s;              // Step 1: Stack ka size initialize karo
    stack->top = -1;              // Step 2: Top ko -1 set karo (iska matlab stack abhi empty hai)
    stack->arr = (char*)malloc(s * sizeof(char)); // Step 3: Dynamic memory allocate karo 's' characters ke liye
    return stack;
}

// Push function (character ko stack me dalna)
void push(struct Stack* stack, char value) {
    if (stack->top == stack->size - 1) {   // Agar top last index pe hai toh stack full hai
        printf("overflow\n");
        return;
    } else {
        stack->top++;               // Top ko ek step aage badhao
        stack->arr[stack->top] = value;    // Naya character insert karo top position pe
    }
}

// Pop function (character ko stack se nikalna)
char pop(struct Stack* stack) {
    if (stack->top == -1) {         // Agar top -1 hai toh stack empty hai
        printf("stack underflow\n");
        return '\0';
    } else {
        char val = stack->arr[stack->top]; // Top element store karo
        stack->top--;               // Top ko ek step peeche le jao
        return val;                 // Popped character return karo
    }
}

// IsEmpty function (check karo stack empty hai ya nahi)
int IsEmpty(struct Stack* stack) {
    return stack->top == -1;        // Agar top -1 hai toh stack empty hai
}

// Function to reverse a string using Stack
void reverseString(char str[]) {
    int n = strlen(str);
    struct Stack* stack = createStack(n);   // Stack banaya jiska size string ke length ke barabar hai

    // Step 1: Har character ko stack me push karo
    for (int i = 0; i < n; i++) {
        push(stack, str[i]);
    }

    // Step 2: Har character ko pop karke string me overwrite karo
    for (int i = 0; i < n; i++) {
        str[i] = pop(stack);
    }

    // Free memory
    free(stack->arr);
    free(stack);
}

int main() {
    char str[] = "hello";   // Input string
    printf("Original string: %s\n", str);

    reverseString(str);     // Reverse function call
    printf("Reversed string: %s\n", str);

    return 0;
}