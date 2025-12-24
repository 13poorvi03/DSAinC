#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // INT_MIN ke liye

// Stack ko represent karne ke liye struct
struct Stack {
    int capacity;   // stack ki maximum size
    int topIndex;   // stack ke top element ka index
    int* arr;       // dynamic array jo elements store karega
};

// Constructor jaisa function: stack initialize karna
struct Stack* createStack(int c) {
    struct Stack* st = (struct Stack*)malloc(sizeof(struct Stack)); // memory allocate
    st->capacity = c;              // capacity set karo
    st->topIndex = -1;             // initially empty
    st->arr = (int*)malloc(c * sizeof(int)); // array allocate karo
    return st;
}

// Push function: element ko stack ke top pe daalna
void push(struct Stack* st, int data) {
    if (st->topIndex == st->capacity - 1) { // agar stack full hai
        printf("overflow\n");
        return;
    }
    st->topIndex++;              // topIndex badhao
    st->arr[st->topIndex] = data; // element daal do
}

// Pop function: top element ko remove karna
int pop(struct Stack* st) {
    if (st->topIndex == -1) {     // agar stack empty hai
        printf("underflow\n");
        return INT_MIN;           // error ke liye INT_MIN
    }
    int poppedElement = st->arr[st->topIndex]; // top element store karo
    st->topIndex--;               // topIndex peeche le jao
    return poppedElement;         // popped element return karo
}

// Top function: current top element ko dekhna
int top(struct Stack* st) {
    if (st->topIndex == -1) {     // agar stack empty hai
        printf("underflow\n");
        return INT_MIN;
    }
    return st->arr[st->topIndex]; // top element return karo
}

// Stack empty check karna
int isempty(struct Stack* st) {
    return st->topIndex == -1;
}

// Stack ka size batana
int size(struct Stack* st) {
    return st->topIndex + 1;
}

// Stack full check karna
int isfull(struct Stack* st) {
    return st->topIndex == st->capacity - 1;
}

// Main function
int main() {
    struct Stack* st = createStack(5); // stack banaya capacity 5

    push(st, 1);   // element 1 push
    push(st, 2);   // element 2 push
    push(st, 3);   // element 3 push

    printf("Top element: %d\n", top(st));   // abhi top element 3 hoga

    printf("Popped: %d\n", pop(st));        // 3 pop hoga
    printf("Top element: %d\n", top(st));   // ab top element 2 hoga

    return 0;
}