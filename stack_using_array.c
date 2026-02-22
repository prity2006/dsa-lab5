#include <stdio.h>
#define MAX 5   // Maximum size of stack

int stack[MAX];
int top = -1;   // Initialize top

// Function to push an element
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot insert %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed into stack\n", value);
    }
}

// Function to pop an element
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

// Function to display stack elements
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}