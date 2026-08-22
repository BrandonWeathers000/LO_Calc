#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* ptr;
    size_t size;
    size_t capacity;
}LoList;

void printLoList(LoList myLoList){
    for(int i = 0; i < (int) myLoList.size; i++){
        printf("%lf ", myLoList.ptr[i]);
    }
    printf("\n");
}

void growArray(LoList *myLoList){
    myLoList->capacity *= 2;

    double *new_ptr = realloc(myLoList->ptr, myLoList->capacity * sizeof(double));

    if (new_ptr == NULL){
        printf("New pointer for list expansion pointer memorry allocaiton failed\n");
        return;
    }

    myLoList->ptr = new_ptr;
}

void push(LoList *myLoList, double value) {
    if (myLoList->size == myLoList->capacity) {
        /* printf("The array needs to grow!\n"); */
        growArray(myLoList);
    }

    myLoList->ptr[myLoList->size] = value;
    myLoList->size++;
}

void clearLoList(LoList *myLoList){
    free(myLoList->ptr);
    myLoList->ptr = malloc(sizeof(double));
    myLoList->size = 0;
    myLoList->capacity = 1;
}

double addLoList(LoList *myLoList){
    double sum = myLoList->ptr[0];

    for(int i = 1; i < (int) myLoList->size; i++){
        sum += myLoList->ptr[i];
    }

    return sum;
}


double subLoList(LoList *myLoList){
    double subtrahend;
    // Making a copy wihtout first element
    LoList newMyLoList;
    newMyLoList.ptr = malloc(sizeof(double));
    newMyLoList.size = 0;
    newMyLoList.capacity = 1;

    for(int i = 0; i < ((int) myLoList->size) - 1; i++) {
            push(&newMyLoList, myLoList->ptr[i + 1]);
    }

    subtrahend = addLoList(&newMyLoList);

    return myLoList->ptr[0] - subtrahend;
}

double mulLoList(LoList *myLoList){
    double product = myLoList->ptr[0];

    for(int i = 1; i < (int) myLoList->size; i++){
        product *= myLoList->ptr[i];
    }

    return product;
}

double divLoList(LoList *myLoList){
    double quotient = myLoList->ptr[0];

    for(int i = 1; i < ((int) myLoList->size); i++) {
        quotient /= myLoList->ptr[i];
    }

    return quotient;
}
