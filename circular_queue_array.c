#include <stdio.h>
#define MAX 5  // Maximum size of queue

int queue[MAX];
int front = -1, rear = -1;

// Function to insert element (Enqueue)
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {  // Empty queue
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Function to delete element (Dequeue)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty\n");
        return;
    }

    printf("%d deleted from queue\n", queue[front]);

    if (front == rear) {  // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);  // Queue full
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);  // Wrap around
    enqueue(70);  // Wrap around
    display();

    return 0;
}