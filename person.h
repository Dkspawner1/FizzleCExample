#ifndef PERSON_H
#define PERSON_H

typedef struct Person
{
    char *name;
    unsigned int age;
    double balance;
} Person;

Person GetPerson();
void PrintPerson(const Person person);
#endif