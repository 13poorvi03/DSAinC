#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   // for isalnum() → checks if character is operand (A-Z, 0-9)

#define MAX 100

char stack[MAX];    // stack to hold operators and parentheses
int top = -1;       // stack top pointer

// Push function → adds element to stack
void push(char x) {
    stack[++top] = x;   // increment top and store element
}

// Pop function → removes element from stack
char pop() {
    if (top == -1) return -1;   // if stack empty, return -1
    else return stack[top--];   // return top element and decrement top
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '(') return 0;             // lowest precedence
    if (x == '+' || x == '-') return 1; // addition & subtraction
    if (x == '*' || x == '/') return 2; // multiplication & division
    if (x == '^') return 3;             // exponent highest precedence
    return -1;
}

// Function to convert infix to postfix (standard algorithm)
void infixToPostfix(char *exp, char *result) {
    char *e, x;
    e = exp;   // pointer to traverse expression
    int k = 0; // index for result string

    while (*e != '\0') {   // loop until end of string
        // Case 1: Operand → directly add to result
        if (isalnum(*e)) {
            result[k++] = *e;
        }
        // Case 2: '(' → push to stack
        else if (*e == '(') {
            push(*e);
        }
        // Case 3: ')' → pop until '(' is found
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                result[k++] = x;   // add popped operators to result
            }
        }
        // Case 4: Operator (+, -, *, /, ^)
        else {
            // Pop operators from stack with higher/equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                result[k++] = pop();
            }
            // Push current operator
            push(*e);
        }
        e++; // move to next character
    }

    // Pop remaining operators from stack
    while (top != -1) {
        result[k++] = pop();
    }
    result[k] = '\0'; // terminate result string
}

// Function to reverse a string and swap parentheses
void reverse(char *exp) {
    int len = strlen(exp);

    // Step 1: Reverse the string
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    // Step 1: Reverse the infix expression
    // Example: (A-B/C)*(A/K-L) → (L-K/A)*(C/B-A)
    reverse(infix);

    // Step 2: Convert reversed infix to postfix
    // Example: (L-K/A)*(C/B-A) → LKAK/-CB/A-*
    infixToPostfix(infix, postfix);

    // Step 3: Reverse postfix → gives prefix
    // Example: LKAK/-CB/A-* → *-A/BC-/AKL
    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}