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

    for(int i = 1; i < 10; i++){      // Pushes ints 1-9
        push(&myLoList, (double) i);  // When applying division, this is the lowest result.
    }

    printf("The product is: %lf\n", traditionalMultiply(myLoList));

    /* printLoList(myLoList); */

    return 0;
}
