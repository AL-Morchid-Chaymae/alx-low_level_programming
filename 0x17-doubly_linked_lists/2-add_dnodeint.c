#include <stdio.h>
#include <stdlib.h>

// Assuming a doubly linked list structure
struct dlistint_t {
    int data;
    struct dlistint_t *prev;
    struct dlistint_t *next;
};

// Function to add a new node at the beginning of a dlistint_t list
struct dlistint_t *add_dnodeint(struct dlistint_t **head, const int n) {
    // Allocate memory for the new node
    struct dlistint_t *new_node = (struct dlistint_t *)malloc(sizeof(struct dlistint_t));
    if (new_node == NULL) {
        // Allocation failed
        return NULL;
    }

    // Initialize the new node
    new_node->data = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL) {
        // If the list is not empty, update the previous of the current head
        (*head)->prev = new_node;
    }

    // Update the head to point to the new node
    *head = new_node;

    return new_node; // Return the address of the new element
}

// Function to print all elements of a dlistint_t list
void print_dlistint(const struct dlistint_t *h) {
    while (h != NULL) {
        printf("%d\n", h->data);
        h = h->next;
    }
}

// Example usage
int main() {
    // Create an empty doubly linked list
    struct dlistint_t *head = NULL;

    // Add nodes to the beginning of the list
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 1);

    // Print the updated list
    printf("Doubly Linked List after adding nodes:\n");
    print_dlistint(head);

    return 0;
}
