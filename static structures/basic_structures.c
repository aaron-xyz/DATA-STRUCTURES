#include <stdio.h>
#include <stdlib.h>
#include "basic_structures.h"

/* 
 *
 * QUEUES 
 *
 */

// CREATE QUEUE
struct Queue *createQueue(struct Queue *ps)
{
    ps = (struct Queue *) malloc(sizeof(struct Queue));
    ps->front = 0;
    ps->last = -1;
    return ps;
}
//EMPTY QUEUE
int emptyQueue(struct Queue *ps)
{
    if (ps->front == ps->last + 1)
        return 1;
    else
        return 0;
}
//FULL QUEUE
int fullQueue(struct Queue *ps)
{
    if ( ps->last == QUEUESIZE - 1 )
        return 1;
    else
        return 0;
}
// ENQUEUE
void enqueue(struct Queue *ps, int i)
{
    // Is Full?
    if (ps->last == QUEUESIZE - 1)
        printf("The Queue is Full!\n");
    // Else add i at last position
    else
    {
        ps->last++;
        ps->nodes[ps->last] = i;
    }
}
// DEUQEUE
int dequeue(struct Queue *ps)
{
    int f;
    // Is empty?
    if (ps->front == ps->last + 1)
        printf("Queue is empty!\n");
    // Else eliminate the first element
    else
    {
        f = ps->nodes[ps->front];
        ps->nodes[ps->front] = 0; // Not necessary in this implementation
        ps->front++;
        return f;
    }
}
// PRINT QUEUE
void printQueue(struct Queue *ps)
{
    printf("Queue: ");
    for (int i = 0; ps->front + i < ps->last + 1; i++)
        printf("%i ", ps->nodes[ps->front + i]);
    
    printf("\n");
}



/*
 *
 * STACKS
 *
 */

// CREAR UNA PILA (STACK) 
// This is a function that returns a "struct Stack" type
// The function is called create_stack
// As input receives a "struct Stack" type
struct Stack *createStack(struct Stack *ps)
{
    ps = (struct Stack *) malloc(sizeof(struct Stack));
    ps->top = -1;
    return ps;
}
// OPERACIONES BASICAS
// PUSH
void push(struct Stack *ps, int i)
{
    // is full? 
    if ( ps->top == (STACKSIZE - 1) )
    {
        printf("Full Stack\n");
    }
    else
    {
        ps->top++; // ps->top = ps->top + 1  ps->top is the current value of "top" in the structure called "ps"
        ps->nodes[ps->top] = i; // be ps->top = 10, then nodes[ps->top] is equal to nodes[10]
    }
}
// POP
int pop(struct Stack *ps)
{
    // Setting variables
    int t = 0;

    // is empty?
    if (ps->top == -1)
    {
        printf("Empty Stack\n");
    }
    else
    {
        // Assign the top value to a new variables (t)
        t = ps->nodes[ps->top];
        // substract one from top
        ps->top--;
        // return the popped value (t)
        return t;
    }
}
// FULL
int fullStack(struct Stack *ps)
{
    // If full?
    if (ps->top == STACKSIZE - 1)
        return 1;
    
    else
        return 0;
}
// EMPTY
int emptyStack(struct Stack *ps)
{
    // if empty
    if (ps->top == -1)
        return 1;
    // else
    else
        return 0;
}
// PRINT STACK
void printStack(struct Stack *ps)
{
    printf("Stack: ");

    // is empty?
    if (emptyStack(ps))
    {
        printf("[]\n");
        return;
    }
    
    // print from zero to top
    for (int k = 0; k <= ps->top; k++)
    {
        if (k == 0)
            printf("["); // begin with [
        if (k  == ps->top)
            printf("%i]\n", ps->nodes[k]); // the top element close with ]
        else
            printf("%i, ", ps->nodes[k]);
    }
}



/*
 *
 * CIRCULAR QUEUE
 *
 */

// CREATE CIRCULAR QUEUE
struct CircularQueue *createCircQueue(struct CircularQueue *ps)
{
    // Find space
    ps = (struct CircularQueue *) malloc(sizeof(struct CircularQueue));

    // Assing values to its members
    ps->front = 0;
    ps->last = -1;
    ps->size = 0;
    
    // return the structure
    return ps;
}
// IS EMPTY
int emptyCircQueue(struct CircularQueue *ps)
{
    // is emty?
    if (ps->size == 0)
        return 1;
    
    else
        return 0;
}
// IS FULL
int fullCircQueue(struct CircularQueue *ps)
{
    // is full?
    if (ps->size == QUEUESIZE)
        return 1;
    
    else
        return 0;
}
// ENQUEUE
void enqueueCirc(struct CircularQueue *ps, int i)
{
    if (ps->size == QUEUESIZE)
        printf("Full Queue\n");

    else
    {
        // The avalaible postions must be between zero and QUESIZE - 1
        ps->last = (ps->last + 1) % QUEUESIZE;
        // Assing the value
        ps->nodes[ps->last] = i;
        // increase the size by one
        ps->size++;
    }
}
// DEQUEUE
int dequeueCirc(struct CircularQueue *ps)
{
    int cq = 0;

    // is empty?
    if (ps->size == 0)
        printf("Empty Queue\n");

    // remove the element in front
    else
    {
        // Store temporarily the current value in front
        cq = ps->nodes[ps->front];
        // Move the position of front by one without surpasing the size of the QUEUE
        ps->front = (ps->front + 1) % QUEUESIZE;
        // decrease by one the size of the current queue
        ps->size--;
        // return the value removed
        return cq;
    }
}
// PRINT CIRCULAR QUEUE
void printCircQueue(struct CircularQueue *ps)
{
    if (emptyCircQueue(ps))
        printf("[]\n");
    
    for (int i = 0, current; i < ps->size; i++)
    {
        current = (ps->front + i) % QUEUESIZE;
        printf("%i ", ps->nodes[current]);
    }

    printf("\n");
}