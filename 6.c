#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void reverse(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    
    while (current != NULL) {
        // Swap next and prev pointers of the current node
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        // Move to the next node
        current = current->prev;
    }
    
    // Update the head pointer
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);

    printf("Original Doubly Linked List: ");
    printList(head);

    reverse(&head);

    printf("Reversed Doubly Linked List: ");
    printList(head);

    return 0;
}
