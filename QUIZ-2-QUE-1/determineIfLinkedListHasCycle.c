#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int val;
    struct Node *next;
};

// Function to detect if the linked list contains a cycle
bool hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    // Detect cycle using Floyd's Tortoise and Hare algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle detected
}

// Function to create a new node
struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    // Checking if the linked list contains a cycle
    bool cyclePresent = hasCycle(head);

    if (cyclePresent) {
        printf("The linked list contains a cycle.\n");
    } else {
        printf("The linked list does not contain a cycle.\n");
    }

    // Freeing the memory allocated for the linked list
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
