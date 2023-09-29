#include <stdio.h>
#include <stdlib.h>

// Node
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// Insert at front
void insert_at_front(struct Node** head, int data) {
  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = *head;
  new_node->prev = NULL;

  // Update the head pointer
  if (*head != NULL) {
    (*head)->prev = new_node;
  }
  *head = new_node;
}

// Insert at last
void insert_at_last(struct Node** head, int data) {
  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  // Update the last node's next pointer
  if (*head != NULL) {
    struct Node* last_node = *head;
    while (last_node->next != NULL) {
      last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
  } else {
    *head = new_node;
  }
}

// Insert after a given node
void insert_after_given_node(struct Node* prev_node, int data) {
  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = prev_node->next;
  new_node->prev = prev_node;

  // Update the next pointer of the previous node
  prev_node->next = new_node;

  // Update the previous pointer of the new node's next node
  if (new_node->next != NULL) {
    new_node->next->prev = new_node;
  }
}

// Insert before a given node
void insert_before_given_node(struct Node* prev_node, int data) {
  // Create a new node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = prev_node;
  new_node->prev = prev_node->prev;

  // Update the previous pointer of the new node
  prev_node->prev = new_node;

  // Update the next pointer of the new node's previous node
  if (new_node->prev != NULL) {
    new_node->prev->next = new_node;
  }
}

// Print doubly linked list
void print_doubly_linked_list(struct Node* head) {
  if (head == NULL) {
    printf("Doubly linked list is empty\n");
    return;
  }

  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

int main() {
  // Create a doubly linked list
  struct Node* head = NULL;

  // Insert some elements
  insert_at_front(&head, 10);
  insert_at_front(&head, 20);
  insert_at_front(&head, 30);
  insert_at_last(&head, 40);
  insert_at_last(&head, 50);
  insert_at_last(&head, 60);

  // Print the doubly linked list
  print_doubly_linked_list(head);

  // Insert an element after a given node
  insert_after_given_node(head->next, 70);

  // Insert an element before a given node
  insert_before_given_node(head->next->next, 80);

  // Print the doubly linked list
  print_doubly_linked_list(head);

  return 0;
}
