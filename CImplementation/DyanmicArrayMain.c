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

    if(myLoList.ptr == NULL) return 1;

    push(&myLoList, 3.0);
    push(&myLoList, 4.0);
    push(&myLoList, 5.0);

    printf("Before: \n");
    printLoList(myLoList);

    listFactorial(&myLoList);

    printf("After: \n");
    printLoList(myLoList);

    return 0;
}
