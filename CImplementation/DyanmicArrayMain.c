#include <stdio.h>
#include <stdlib.h>

#include "DyanmicArrayMathLib.h"

int main() {
    // Initilizing a new LoList
    LoList myLoList;

    // Give it default values
    myLoList.ptr = malloc(sizeof(double));
    myLoList.size = 0;
    myLoList.capacity = 1;

    if(myLoList.ptr == NULL) return 1; // Memorry allocation failed!

    push(&myLoList, 1.0);
    push(&myLoList, 2.0);
    push(&myLoList, 3.0);
    push(&myLoList, 4.0);
    push(&myLoList, 5.0);
    printf("Old list:\n");
    printLoList(myLoList);

    double result = subLoList(&myLoList);
    clearLoList(&myLoList);
    push(&myLoList, result);

    printf("Old list:\n");
    printLoList(myLoList);

    return 0;
}
