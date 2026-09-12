#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double* ptr;
    size_t size;
    size_t capacity;
}LoList;

// LoList operations
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

// Traditional arthmetic operations
double traditionalAdd(LoList myLoList){
    double sum = myLoList.ptr[0];
    for(int i = 1; i < (int) myLoList.size; i++){
        sum += myLoList.ptr[i];
    }

    return sum;
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

// This method is about 10'000 times more efficient than traditional add!
double consecutiveAdd(LoList myLoList, int firstIndex, int secondIndex){
    return ((myLoList.ptr[secondIndex] - myLoList.ptr[firstIndex] + 1) * (myLoList.ptr[secondIndex] + myLoList.ptr[firstIndex])) / 2;
}

double traditionalFactorial(double input){
    double product = 1.0;

    for(int i = 2; i < input + 1; i++){
        product *= i;
    }

    return product;
}

void listFactorial(LoList *myLoList){
    // Create spare list
    LoList spareLoList;
    spareLoList.ptr = malloc(sizeof(double));
    spareLoList.size = 0;
    spareLoList.capacity = 1;

    if(spareLoList.ptr == NULL){
        printf("Error in memorry creation!");
    }

    // Read in new input
    for(int i = 0; i < (int) myLoList->size; i++){
        double product = traditionalFactorial(myLoList->ptr[i]);
        /* printf("%lf\n", product); */
        push(&spareLoList, product);
    }

    // Set old LoList head to spareList head
    myLoList->ptr = spareLoList.ptr;
}
