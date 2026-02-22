#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse the list
void traverse(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete a node by value
struct Node* deleteNode(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->next;  // Change head
        free(temp);         // Free old head
        return head;
    }

    // Search for the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return head;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);

    return head;
}

int main() {
    struct Node* head = NULL;

    // Creating sample list: 10 -> 20 -> 30 -> 40
    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n4 = (struct Node*)malloc(sizeof(struct Node));

    n1->data = 10; n1->next = n2;
    n2->data = 20; n2->next = n3;
    n3->data = 30; n3->next = n4;
    n4->data = 40; n4->next = NULL;

    head = n1;

    printf("Original List:\n");
    traverse(head);

    head = deleteNode(head, 30);

    printf("List after deleting 30:\n");
    traverse(head);

    return 0;
}