#include <stdio.h>
#define MAX 5   // Maximum size of queue

int queue[MAX];
int front = -1;
int rear = -1;

// Function to insert element (Enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Function to delete element (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;  // Reset queue after last element removed
    }
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}