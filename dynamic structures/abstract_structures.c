#include <stdio.h>
#include <stdlib.h>
#include "abstract_structures.h"

/* FUNCTIONS */
/* INIT */
Node *initList()
{
    Node *init = NULL;
    return init;
}

/* INSERT - AT THE FRONT OF THE LIST */
// ENQUEUE - QUEUE
// APPEND - STACK
void insertFront(int value)
{
    // Allocating the node
    Node *temp = (Node *) malloc(sizeof(Node));

    // Check the node was allocated correctly
    if (temp == NULL)
    {
        printf("Memory allocation not possible!\n");
        return;
    }

    else
    {
        temp->data = value;
        temp->link = head;
        head = temp;
    }
}

/* INSERT IN N - LIST */
/* ADD A NODE IN THE POSITION N */
void insertInPosition(int value, int position)
{
    // A valid position
    if (position == 0)
    {
        printf("The position must be an integer greater than zero\n");
        return;
    }

    // Insert at the begining of the list if postion == 1
    if (position == 1)
    {
        insertFront(value);
        return;
    }

    else
    {
        // Otherwise allocate memory for the new Node
        Node *t = (Node *) malloc(sizeof(Node));

        // Asign values
        t->data = value;
        t->link = NULL;

        // Start counting from the head
        Node *t2 = head; // copy the value of head

        // Iterate until the desired position
        for (int i = 0; i < position - 2; i++)
            t2 = t2->link; // Points to the next Node - one-by-one
        
        t->link = t2->link; // The new node points to the position n
        t2->link = t; // The new node is pointed by the node in the position n-1

        printList();
    }

}

/* APPEND - AT THE END OF THE LIST*/
// ENQUEUE - QUEUE
void insertLast(int value)
{
    // Allocate space for the new Node
    Node *t = (Node *) malloc(sizeof(Node));

    // Check for allocation correctness
    if (t == NULL)
    {
        printf("Memory allocation not possible\n");
        exit(1);
    }

    // Assign values for the new Node
    t->data = value;
    t->link = NULL;

    // Copy the pointer of head
    Node *t2 = head;

    // Check every node until find the last one
    while (t2->link != NULL)
        t2 = t2->link;

    // Link the previous last node with the new Node
    t2->link = t;
}

/* DELETE - DELETE THE FIRST ELEMENT OF THE LIST */
/* POP - STACK */
int deleteFront()
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
    // Delete the address too
    temp = NULL;
    
    // Return the data for whatever purpose
    return deleted;
}

/* DELETE IN N - DELETE AN ELEMENT IN THE POSITION N */
int deletePosition(int n)
{
    int deleted = 0;
    
    // A copy of head
    Node *p = head;

    // If the list is empty
    if (p == NULL)
    {
        printf("Empty List\n");
        return -1;
    }
    
    // if n == 1
    if (n == 1)
    {
        deleted = deleteFront();
        return deleted;
    }

    // Stop in n-1
    for (int i = 0; i < n - 2; i++)
        p = p->link;

    // Reasigning pointers
    Node *q = p->link; //q points to n
    p->link = q->link; // p now points to n+1
    q->link = NULL; // Delete the pointer in the node n
    deleted = q->data; // passing data to deleted
    free(q); // Free the element n
    q = NULL; // make q points to nothing

    return deleted;
}

/* POP - DELETE THE LAST ELEMENTE OF THE LIST */
/* POP - DEQUEUE */
int deleteLast()
{
    int deleted = 0;
    
    // Point to the first Node
    Node *p = head; // Point the first element
    Node *q = head->link; // Point the second element

    // If the list os of size 1 or less
    if (p == NULL || q == NULL)
    {
        deleted = deleteFront();
        return deleted;
    }

    // Search the last element
    while (q->link != NULL)
    {
        p = p->link;
        q = q->link;
    }

    // Save the data to be deleted
    deleted = q->data;

    // Free the last Node
    free(q);
    q = NULL;

    // Make point to NULL the current last element
    p->link = NULL;

    printList();
    return deleted;
}

/* PRINT - PRINTI IN ORDER (FROM FIRST TO LAST) */
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

    printf("\n");
}


/*
 *
 * Double linked list functions
 *
 */
// CREATE A NEW NODE
BiNode getBiNode(int value)
{
    // Allocating memory of size BiNode
    BiNode *temp = (BiNode *) malloc(sizeof(BiNode));

    // Assigining values
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;

    return tremp;
}

void insertAtHead(int value)
{
    BiNode *temp = getBiNode(value);
    // tpo be continued ...
}