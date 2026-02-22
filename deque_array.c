#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

// Function to check if deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

// Function to check if deque is empty
int isEmpty() {
    return front == -1;
}

// Insert at front
void insertFront(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {  // Empty deque
        front = rear = 0;
    } else if (front == 0) {  // Wrap around
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front\n", value);
}

// Insert at rear
void insertRear(int value) {
    if (isFull()) {
        printf("Deque Overflow! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow! Queue is empty\n");
        return;
    }

    printf("%d deleted from front\n", deque[front]);

    if (front == rear) {  // Only one element
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow! Queue is empty\n");
        return;
    }

    printf("%d deleted from rear\n", deque[rear]);

    if (front == rear) {  // Only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// Display deque elements
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are:\n");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    display();

    insertRear(30);
    insertFront(2);
    display();

    deleteRear();
    display();

    return 0;
}