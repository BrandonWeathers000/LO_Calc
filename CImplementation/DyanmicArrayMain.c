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

    for(int i = 1; i < 10'001; i++){
        push(&myLoList, (double) i);
    }

    /* printLoList(myLoList); */

    for(int i = 1; i < 1'000'000; i++){
        consecutiveAdd(myLoList, 0, myLoList.size - 1);
    }

    return 0;
}
