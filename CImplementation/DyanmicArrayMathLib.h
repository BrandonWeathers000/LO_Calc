#ifndef DYANMICARRAYMATHLIB

#include <stdlib.h>

#define DYANMICARRAYMATHLIB

typedef struct {
    int* ptr;
    size_t size;
    size_t capacity;
}LoList;

void printLoList(LoList myLoList);
void growArray(LoList *myLoList);
void push(LoList *myLoList, int value);
int addLoList(LoList *myLoList);

#endif
