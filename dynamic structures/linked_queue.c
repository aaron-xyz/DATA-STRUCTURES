#include <stdio.h>
#include <stdlib.h>
#include "abstract_structures.h"

/* Prototyping */
Node *initList();
void enqueue(int value); // append at last position
int dequeue(); // dequeue first element
void printList(); // print current elements


// Global variables
// Setting main node structures
Node *head;

/* MAIN */
int main(void)
{
    // init an empty list
    head = initList();

    // Adding some nodes at the end
    enqueue(200);
    enqueue(300);
    enqueue(400);
    dequeue();
    enqueue(500);
    dequeue();
    dequeue();
    printList();// Print current list

    // Deleting Nodes
}

/* FUNCTIONS */
/* INIT */
Node *initList()
{
    Node *init = NULL;
    return init;
}

/* APPEND */
void enqueue(int value)
{
    // Allocate space for the new Node
    Node *t = (Node *) malloc(sizeof(Node));

    // Check for allocation correctness
    if (t == NULL)
    {
        printf("Memory allocation not possible\n");
        exit(1);
    }

    if (head == NULL)
    {
        temp->data = value; // set the value to the data
        temp->link = head; // 
        head = temp;
        return;
    }

    // Assign values for the new Node
    t->data = value;
    t->link = NULL;

    // Coy the pointer of head
    Node *t2 = head;

    // Check every node until find the last one
    while (t2->link != NULL)
        t2 = t2->link;

    // Link the previous last node with the new Node
    t2->link = t;
}

// DELETE
int dequeue()
{
    // It will sotre the data in the node to be deleted
    int deleted = 0;
    
    // A pointer to the first element
    Node *temp = head;

    // Check if the list is empty
    if (temp == NULL)
    {
        printf("Empty list\n");
        exit(1);
    }
    // Head points to the second element
    head = temp->link;
    
    // Save the data before be freed
    deleted = temp->data;
    
    // Free the node
    free(temp);
    // dequeue the address too
    temp = NULL;
    
    // Return the data for whatever purpose
    return deleted;
}


// PRINT
void printList()
{
    // Allocating space
    Node *t = head; //(NOde *) malloc(sizeof(Node));
    
    // Check if list is empty
    if (t == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    // Print the values from the begining
    printf("List: %i ", t->data);
    while (t->link != NULL)
    {
        t = t->link; // The next node
        printf("%i ", t->data);
    }
}