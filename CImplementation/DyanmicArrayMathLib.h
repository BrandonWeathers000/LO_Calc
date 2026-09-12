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
double traditionalAdd(LoList myLoList);
double traditionalSubtract(LoList myLoList);
double traditionalMultiply(LoList myLoList);
double traditionalDivide(LoList myLoList);
double consecutiveAdd(LoList myLoList, int firstIndex, int secondIndex);
double traditionalFactorial(int input);
void listFactorial(LoList *myLoList);

#endif
