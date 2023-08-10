#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "person.h"
#include "program.h"

#define P_SIZE 2

int main(int argc, char *argv[])
{
    Person *people = malloc(P_SIZE * sizeof(Person));

    bool exit = false;

    do
    {
        int selection = GetSelection();
        switch (selection)
        {
        case -1:
        default:
            printf("INVALID Selection\n");
            break;
        case Add:
            for (int i = 0; i < P_SIZE; i++)
                people[i] = GetPerson();
            break;
        case Modify:
            break;
        case List:
            for (int i = 0; i < P_SIZE; i++)
                PrintPerson(people[i]);
            break;
        case Delete:
            break;
        case Exit:
            return EXIT_SUCCESS;
        }
    } while (true);
    free(people);
    return EXIT_SUCCESS;
}