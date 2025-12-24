#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // maximum size of stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* st) {
    st->top = -1;
}

// Push element
void push(struct Stack* st, int val) {
    if (st->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    st->arr[++st->top] = val;
}

// Pop element
void pop(struct Stack* st) {
    if (st->top == -1) {
        printf("Stack underflow\n");
        return;
    }
    st->top--;
}

// Get top element
int top(struct Stack* st) {
    if (st->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return st->arr[st->top];
}

// Check if stack is empty
int empty(struct Stack* st) {
    return st->top == -1;
}

int main() {
    struct Stack st;
    initStack(&st);

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);

    printf("top element of the stack : %d\n", top(&st));

    pop(&st);
    printf("after pop : %d\n", top(&st));

    push(&st, 7);
    printf("after push : %d\n", top(&st));

    printf("%d\n", empty(&st));

    return 0;
}