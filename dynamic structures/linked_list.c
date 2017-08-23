#include <stdio.h>
#include <stdlib.h>
#include "abstract_structures.h"

/* MAIN */
int main(void)
{
    // variables
    int n = 0, in = 0;
    char ans;

    printf("Do you want to create a List (y/n)?\n");
    scanf("%c", &ans);
    
    // init an empty list
    if (ans == 'y')
        head = initList();
    else
    {
        printf("Nothing done.\n");
        return 1;
    }

    // Reuesting the number of elements to input
    printf("How many elements do you want to add ?\n");
    scanf("%i", &n);

    // Requesting number by number
    for (int i = 0; i < n; i++)
    {
        // Getting inputs
        printf("Give me the element %i: ", i+1);
        scanf("%i", &in);

        // Add the inputs to the list
        insertFront(in);
        // Print the list
        printList();
    }

    // Reuesting the number of elements to input
    printf("How many elements do you want to delete?\n");
    scanf("%i", &n);

    // Requesting number by number
    for (int i = 0; i < n; i++)
    {
        // Add the inputs to the list
        deleteLast();
        // Print the list
        printList();
    }

    free(head);
    head = NULL;
}