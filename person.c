#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "person.h"

Person GetPerson()
{
    Person *tmp = malloc(sizeof(Person));
    fflush(stdin);

    printf("Name: ");
    tmp->name = malloc(2 * sizeof(char));
    scanf("%[^\n]%*c", tmp->name);
    printf("Age: ");
    scanf("%d", &tmp->age);
    tmp->balance = 0;
    return *tmp;
}

void PrintPerson(const Person person)
{
    printf("[%s] - %u - $%.2lf\n", person.name, person.age, person.balance);
}