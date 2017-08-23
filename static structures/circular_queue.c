#include <stdio.h>
#include <stdlib.h>
#include "basic_structures.h"

// MAIN
int main(void)
{
    //Initial settings
    int n = 0, out = 0;
    int d = 0;
    int rando = 0;
    char ans;
    struct CircularQueue *ps;

    // intialize the queue
    ps = createCircQueue(ps);

    // max size?
    printf("The size of the queue is: %i\n\n", QUEUESIZE);

    do
    {
        printf("Do you want to add or delete more elelents (y/n)? "); // se imprime dos veces,  revisar cuendo tenga tiempo
        scanf("%c", &ans);

        if (ans == 'y')
        {
            printf("\nHow many elements do you want to append to the queue? ");
            scanf("%i", &n);

            // enqueue
            for (int i = 0; i < n; i++)
            {
                rando = (rand() % 100);

                enqueueCirc(ps, rando * 2);
                //printf("added: [%i] -> %i; size = %i\n", ps->last, ps->nodes[i], ps->size);
                printCircQueue(ps);
            }

            printf("\n\n");
            printf("How many elements do you want to pop from the queue? ");
            scanf("%i", &out);

            // dequeue
            for (int j = 0; j < out; j++)
            {
                d = dequeueCirc(ps);
                //printf("removed: [%i] -> %i; size = %i\n",ps->front - 1 , d, ps->size);
                printCircQueue(ps);
            }
        }

    } while (ans != 'n');

    // Release memory space
    free(ps);
    // Make it point to nothing
    ps = NULL;
}