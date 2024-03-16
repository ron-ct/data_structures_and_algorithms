#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* detectCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

       while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break; // Cycle detected
        }
    }

    // If there's no cycle, return NULL
    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }

    // Reset slow pointer to head and move both pointers one step at a time
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Return the starting node of the cycle
    return slow;
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

    // Detect the starting node of the cycle
    struct Node *cycleStart = detectCycle(head);

    if (cycleStart != NULL) {
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    } else {
        printf("No cycle detected.\n");
    }

    // Freeing the memory
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
