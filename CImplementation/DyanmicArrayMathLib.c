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
    double sum = myLoList.ptr[0];
    for(int i = 1; i < (int) myLoList.size; i++){
        sum += myLoList.ptr[i];
    }

    return sum;
}

// This method is about 10'000 times more efficient than traditional add!
double triangleAdd(LoList myLoList){
    double lastElement = myLoList.ptr[myLoList.size - 1];

    return (lastElement * (lastElement + 1)) / 2;
}

double consecutiveAdd(LoList myLoList, int firstIndex, int secondIndex){
    return (myLoList.size / 2) * (myLoList.ptr[firstIndex] + myLoList.ptr[secondIndex]);
}

double traditionalSubtract(LoList myLoList){
    double firstNumber = myLoList.ptr[0];
    double sum = traditionalAdd(myLoList);

    return firstNumber - sum;
}

double traditionalMultiply(LoList myLoList){
    double product = myLoList.ptr[0];
    for(int i = 1; i < (int) myLoList.size; i++){
        if(myLoList.ptr[i] == 0){
            return 0.0;
        }
        if(myLoList.ptr[i] == 1){
            break;
        }
        product *= myLoList.ptr[i];
    }

    return product;
}

double traditionalDivide(LoList myLoList){
    double quotient = myLoList.ptr[0];
    for(int i = 1; i < (int) myLoList.size; i++){
        printf("The current quotient is: %lf\n", quotient);
        quotient /= myLoList.ptr[i];
    }

    return quotient;
}
