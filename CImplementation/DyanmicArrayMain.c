#include <stdio.h>
#include <stdlib.h>

#include "DyanmicArrayMathLib.h"

int main() {
    LoList myLoList = {myLoList.ptr = malloc(sizeof(int)), 0, 1};

    if(myLoList.ptr == NULL) return 1; // Memorry allocation failed!

    push(&myLoList, 1);
    push(&myLoList, 2);
    push(&myLoList, 3);
    push(&myLoList, 4);
    push(&myLoList, 5);
    push(&myLoList, 6);
    push(&myLoList, 7);
    push(&myLoList, 8);
    push(&myLoList, 9);
    printf("Old list:\n");
    printLoList(myLoList);
                     
    int sum = addLoList(&myLoList);
    free(myLoList.ptr);
    myLoList.ptr = malloc(sizeof(int));
    myLoList.size = 0;
    myLoList.capacity = 1;
    push(&myLoList, sum);
    printf("New list:\n");
    printLoList(myLoList);

    return 0;
}
