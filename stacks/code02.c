#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // INT_MIN ke liye

// Stack ko represent karne ke liye struct banayi
struct Stack {
    int capacity;    // stack ki maximum size (kitne elements aa sakte hain)
    int topIndex;    // stack ke top element ka index (initially -1 matlab empty)
    int* arr;        // dynamic array jo stack ke elements store karega
};

// Constructor jaisa function: stack create karna aur initialize karna
struct Stack* createStack(int c) {
    // ek naya stack object ke liye memory allocate karte hain
    struct Stack* st = (struct Stack*)malloc(sizeof(struct Stack));

    // capacity set karte hain (user ne jitni size di hai)
    st->capacity = c;

    // initially stack empty hai, isliye topIndex = -1
    st->topIndex = -1;

    // array allocate karte hain jo elements store karega
    st->arr = (int*)malloc(c * sizeof(int));

    // pointer return karte hain jo stack ko represent karega
    return st;
}

// Push function: naya element stack ke top pe daalna
void push(struct Stack* st, int data) {
    // agar stack full hai to overflow
    if (st->topIndex == st->capacity - 1) {
        printf("overflow\n");
        return;
    }

    // topIndex ko ek step aage badhao
    st->topIndex++;

    // naya element array ke topIndex position pe daal do
    st->arr[st->topIndex] = data;
}

// Pop function: top element ko remove karna
int pop(struct Stack* st) {
    // agar stack empty hai to underflow
    if (st->topIndex == -1) {
        printf("underflow\n");
        return INT_MIN;   // error ke liye INT_MIN return karte hain
    }

    // current top element ko store karo
    int poppedElement = st->arr[st->topIndex];

    // topIndex ko ek step peeche le jao (element remove ho gaya)
    st->topIndex--;

    // popped element return karo
    return poppedElement;
}

// Top function: current top element ko dekhna (remove nahi karna)
int top(struct Stack* st) {
    // agar stack empty hai to underflow
    if (st->topIndex == -1) {
        printf("underflow\n");
        return INT_MIN;
    }

    // current top element return karo
    return st->arr[st->topIndex];
}

// Size function: stack me kitne elements hai
int size(struct Stack* st) {
    return st->topIndex + 1;
}

// Empty check function: stack empty hai ya nahi
int isEmpty(struct Stack* st) {
    return st->topIndex == -1;
}

// Full check function: stack full hai ya nahi
int isFull(struct Stack* st) {
    return st->topIndex == st->capacity - 1;
}

// Main function: program execution start hota hai yaha se
int main() {
    // ek stack banaya jiska capacity 5 hai
    struct Stack* st = createStack(5);

    // elements push karte hain
    push(st, 10);
    push(st, 20);
    push(st, 30);

    // abhi top element print hoga (30)
    printf("Top element: %d\n", top(st));

    // ek element pop karte hain (30 remove hoga)
    printf("Popped: %d\n", pop(st));

    // ab top element 20 hoga
    printf("Top element: %d\n", top(st));

    // size print karte hain (2 elements bache hain)
    printf("Size: %d\n", size(st));

    return 0;
}