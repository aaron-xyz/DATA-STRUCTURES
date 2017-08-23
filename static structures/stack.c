#include <stdio.h>
#include <stdlib.h>
#include "basic_structures.h"

// Main function
int main(void)
{
    // Setting values for STACK
    int n = 0, out = 0;
    int rando = 0;
    
    //Setting a struct type
    struct Stack *ps;
    ps = createStack(ps);

    printStack(ps);

    printf("How many elements do you want to append to the stack? ");
    scanf("%i", &n);

    // Push n elements
    for (int i = 0; i < n; i++)
    {
        rando = (rand() % 100);
        push(ps, rando);
        printStack(ps);
    }

    printf("How many elements do you want to pop from the stack? ");
    scanf("%i", &out);

    // Pop [out] elements
    for (int j = 0; j < out; j++)
    {
        pop(ps);
        printStack(ps);
    }

    // Free the space - Remember!
    free(ps);
    // Make it point to nothing
    ps = NULL;
}