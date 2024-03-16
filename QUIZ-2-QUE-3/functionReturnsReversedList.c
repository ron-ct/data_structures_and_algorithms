#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse linked List
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head; // return the new head after reversing
}

// Function to push Node at beginning of list
void createNewNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

// Function to print Linked List
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;

    createNewNode(&head, 30);
    createNewNode(&head, 32);
    createNewNode(&head, 33);
    createNewNode(&head, 40);

    printf("Given linked List: \n");
    printList(head);

    head = reverseList(head); // Update head with the new head after reversing
    printf("\n");
    printf("Reversed Linked List: ");
    printList(head);

    // Freeing Memory
    struct Node* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
