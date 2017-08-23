#include <stdio.h>
#include <stdlib.h>
#include "abstract_structures.h"

/* Prototyping */
Node *initList();
void append(int value); // insert at first position
int pop(); // pop first element
void printList(); // print current elements


// Global variables
// Setting main node structures
Node *head;

/* MAIN */
int main(void)
{
    // init an empty list
    head = initList();

    //Adding some new nodes at the beginning
    append(10);
    append(20);
    pop();
    append(30);
    printList();//Print current list

    // Deleting Nodes
    pop();
    pop();
    append(40);
    pop();
}

/* FUNCTIONS */
/* INIT */
Node *initList()
{
    Node *init = NULL;
    return init;
}

// INSERT
void append(int value)
{
    // Allocating the node
    Node *temp = (Node *) malloc(sizeof(Node));

    // Check the node was allocated correctly
    if (temp == NULL)
    {
        printf("Memory allocation not possible!\n");
        exit(1);
    }

    else
    {
        temp->data = value;
        temp->link = head;
        head = temp;
    }
}


// pop
int pop()
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
    // pop the address too
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