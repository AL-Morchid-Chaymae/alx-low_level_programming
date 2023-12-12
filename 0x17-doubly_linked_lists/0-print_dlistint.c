#include <stdio.h>
#include <stddef.h> // for size_t

// Assuming a doubly linked list structure
struct dlistint_t {
    int data;
    struct dlistint_t *prev;
    struct dlistint_t *next;
};

// Function to print all elements of a dlistint_t list
size_t print_dlistint(const struct dlistint_t *h) {
    size_t node_count = 0; // Initialize node count

    // Traverse the list and print each element
    while (h != NULL) {
        printf("%d\n", h->data);
        h = h->next; // Move to the next node
        node_count++; // Increment node count
    }

    return node_count; // Return the total number of nodes
}

// Example usage
int main() {
    // Create a sample doubly linked list
    struct dlistint_t node1 = {1, NULL, NULL};
    struct dlistint_t node2 = {2, NULL, NULL};
    struct dlistint_t node3 = {3, NULL, NULL};

    node1.next = &node2;
    node2.prev = &node1;
    node2.next = &node3;
    node3.prev = &node2;

    // Call the print_dlistint function
    size_t count = print_dlistint(&node1);

    // Display the number of nodes
    printf("Number of nodes: %zu\n", count);

    return 0;
}
