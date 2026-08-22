#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* ptr;
    size_t size;
    size_t capacity;
}LoList;

void printLoList(LoList myLoList){
    for(int i = 0; i < (int) myLoList.size; i++){
        printf("%d\n", myLoList.ptr[i]);
    }
}

void growArray(LoList *myLoList){
    myLoList->capacity *= 2;

    int *new_ptr = realloc(myLoList->ptr, myLoList->capacity * sizeof(int));

    if (new_ptr == NULL){
        printf("New pointer for list expansion pointer memorry allocaiton failed\n");
        return;
    }

    myLoList->ptr = new_ptr;
}

void push(LoList *myLoList, int value) {
    if (myLoList->size == myLoList->capacity) {
        printf("The array needs to grow!\n");
        growArray(myLoList);
    }

    myLoList->ptr[myLoList->size] = value;
    myLoList->size++;
}

int addLoList(LoList *myLoList){
    int sum = 0;

    for(int i = 0; i < (int) myLoList->size; i++){
        sum += myLoList->ptr[i];
    }

    return sum;
}
