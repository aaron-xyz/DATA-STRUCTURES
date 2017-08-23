/*
 *
 * basic_structures.h
 *
 * this header must be included in the files:
 * - basic_structures.c
 * - queue.c
 * - stack.c
 * - circular_queue.c
 *
 * How to run them:
 * >> gcc main.c basic_structures.c basic_structures.h -o main
 *
 * Where main can be replaced with queue, stack, or circular_queue
 *
 */

// CONSTANTS
#define STACKSIZE 50
#define QUEUESIZE 50

// prototyping - STACK
struct Stack *createStack(struct Stack *ps);
void push(struct Stack *ps, int i);
int pop(struct Stack *ps);
int emptyStack(struct Stack *ps);
int fullStack(struct Stack *ps);
void printStack(struct Stack *ps);

// Prototyping - QUEUE
struct Queue *createQueue(struct Queue *ps);
void enqueue(struct Queue *ps, int i);
int dequeue(struct Queue *ps);
int emptyQueue(struct Queue *ps);
int fullQueue(struct Queue *ps);
void printQueue(struct Queue *ps);

// Prototyping - CIRCULAR QUEUE
struct CircularQueue *createCircQueue(struct CircularQueue *ps);
int emptyCircQueue(struct CircularQueue *ps);
int fullCircQueue(struct CircularQueue *ps);
void enqueueCirc(struct CircularQueue *ps, int i);
int dequeueCirc(struct CircularQueue *ps);
void printCircQueue(struct CircularQueue *ps);

// STACK STRUCTURE (PILA)
struct Stack {
    int top;
    int nodes[STACKSIZE];
};

// QUEUE STRUCTURE (COLA)
struct Queue {
    int front;
    int last;
    int nodes[QUEUESIZE];
};

// CIRCULAR QUEUE STRUCTURE (COLA CIRCULAR)
struct CircularQueue {
    int front;
    int last;
    int size;
    int nodes[QUEUESIZE];
};