#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert at the beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    newNode->data = value;
    newNode->next = head;   // Link new node to current head
    head = newNode;         // Update head

    return head;
}

// Function to traverse the list
void traverse(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 50);
    head = insertAtBeginning(head, 40);
    head = insertAtBeginning(head, 30);

    printf("Linked List after inserting at beginning:\n");
    traverse(head);

    return 0;
}