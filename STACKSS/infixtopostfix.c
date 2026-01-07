#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isalnum() → checks if character is alphanumeric (operand)

// Define maximum size for stack
#define MAX 100

char stack[MAX];   // stack array to hold operators
int top = -1;      // stack top pointer

// Push function → adds element to stack
void push(char x) {
    stack[++top] = x;
}

// Pop function → removes element from stack
char pop() {
    if (top == -1) return -1;   // if stack empty, return -1
    else return stack[top--];   // return top element and decrease top
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '(') return 0;             // lowest precedence
    if (x == '+' || x == '-') return 1; // addition & subtraction
    if (x == '*' || x == '/') return 2; // multiplication & division
    if (x == '^') return 3;             // exponent highest precedence
    return -1;
}

// Function to convert infix expression to postfix
void infixToPostfix(char *exp) {
    char *e, x;
    e = exp;   // pointer to traverse expression

    while (*e != '\0') {   // loop until end of string
        // Case 1: Operand → directly print to output
        if (isalnum(*e)) {
            printf("%c", *e);
        }
        // Case 2: '(' → push to stack
        else if (*e == '(') {
            push(*e);
        }
        // Case 3: ')' → pop until '(' is found
        else if (*e == ')') {
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        // Case 4: Operator (+, -, *, /, ^)
        else {
            // Pop operators from stack with higher/equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                printf("%c", pop());
            }
            // Push current operator
            push(*e);
        }
        e++; // move to next character
    }

    // Pop remaining operators from stack
    while (top != -1) {
        printf("%c", pop());
    }
}

int main() {
    char exp[MAX];
    printf("Enter Infix Expression: ");
    scanf("%s", exp);

    printf("Postfix Expression: ");
    infixToPostfix(exp);
    printf("\n");

    return 0;
}