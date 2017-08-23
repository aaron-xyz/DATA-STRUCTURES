#include <stdio.h>
#include <stdlib.h>
#include "basic_structures.h"

// MAIN
int main(void)
{
    int elements = 0, in = 0, out = 0;

    struct Queue *ps;
    ps = createQueue(ps);

    printf("How many elements do you want to append to the queue? ");
    scanf("%i", &elements);

    // Enqueue testing
    for (int i = 0; i < elements; i++)
    {
        // Request number by number
        printf("\nType the element: ");
        scanf("%i", &in);

        // Enqueue that number
        enqueue(ps, in);
        // Print the commplete queue
        printQueue(ps);
    }

    printf("\nHow many elements do you want to remove from the queue? ");
    scanf("%i", &out);

    // Dequeue testing
    for (int j = 0; j < out; j++)
    {
        // Dequeue element by element from the front
        dequeue(ps);
        printQueue(ps);
    }

    // Releasing memory space
    free(ps);
    // Then make it point to nothing
    ps = NULL;
}