#ifndef DYANMICARRAYMATHLIB

#include <stdlib.h>

#define DYANMICARRAYMATHLIB

typedef struct {
    double* ptr;
    size_t size;
    size_t capacity;
}LoList;

void printLoList(LoList myLoList);
void growArray(LoList *myLoList);
void push(LoList *myLoList, double value);
void clearLoList(LoList *myLoList);
double addLoList(LoList *myLoList);
double subLoList(LoList *myLoList);
double mulLoList(LoList *myLoList);
double divLoList(LoList *myLoList);

#endif
