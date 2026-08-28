#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* ptr;
    size_t size;
    size_t capacity;
}LoList;

void printLoList(LoList myLoList){
    for(int i = 0; i < (int) myLoList.size; i++){
        printf("%lf\n", myLoList.ptr[i]);
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

double traditionalAdd(LoList myLoList){
    double sum = 0.0;
    for(int i = 0; i < (int) myLoList.capacity; i++){
        sum += myLoList.ptr[i];
    }

    return sum;
}

// This method is about 10'000 times more efficient than traditional add!
double triangleAdd(LoList myLoList){
    double lastElement = myLoList.ptr[myLoList.size - 1];
    /* printf("The last element is %lf\n", lastElement); */

    return (lastElement * (lastElement + 1)) / 2;
}

double consecutiveAdd(LoList myLoList, int firstIndex, int secondIndex){
    double firstNum = myLoList.ptr[firstIndex];
    double lastNum = myLoList.ptr[secondIndex];

    return (myLoList.size / 2) * (firstNum + lastNum);
}
