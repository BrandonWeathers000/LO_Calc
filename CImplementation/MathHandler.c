/**
    Author: Brandon Weathers
    Date last modified: 7/31/2026
*/

#include<stdlib.h>
#include<stdio.h>

#define MAX_SIZE 255

// Start of data structure
struct Node{
    double data;
    struct Node *next;
};

struct List{
    struct Node *head;
    struct Node *tail;

    int zeroPresent;
};

void initializeList(struct List *list){
    list -> head = NULL;
    list -> tail = NULL;

    list -> zeroPresent = 0;
}

void appendNewNode(struct List *list, double newData){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode -> data = newData;
    if(newNode -> data == 0.0){
        list -> zeroPresent = 1;
    }
    newNode -> next = NULL;

    if (list -> head == NULL) list -> head = newNode;
    else list -> tail -> next = newNode;

    list -> tail = newNode;
}

void printList(struct List *list){
    struct Node *current = list -> head;

    while(current != NULL){
        printf("%.2lf\n", current -> data);
        current = current -> next;
    }
}

void emptylist(struct List *list){
    struct Node *current = list -> head;

    while(current != NULL){
        struct Node *temp = current;
        current = current -> next;
        free(temp);
    }

    initializeList(list);
}
// End of data structure

double addList(struct List *list) {
    struct Node *current = list -> head;

    double result = current -> data;
    current = current -> next;

    while(current != NULL){
        result += current -> data;
        current = current -> next;
    }

    emptylist(list);
    return result;
}

double subtractList(struct List *list) {
    struct Node *current = list -> head;

    double result = current -> data;
    current = current -> next;

    while(current != NULL){
        result -= current -> data;
        current = current -> next;
    }

    emptylist(list);
    return result;
}

double multiplyList(struct List *list) {
    if(list -> zeroPresent){
        emptylist(list);
        return 0;
    }
    struct Node *current = list -> head;

    double result = current -> data;
    current = current -> next;

    while(current != NULL){
        result *= current -> data;
        current = current -> next;
    }

    emptylist(list);
    return result;
}

double divideList(struct List *list) {
    struct Node *current = list -> head;

    double result = current -> data;
    current = current -> next;

    if(result == 0.0){
        return 0;
    }else if(list -> zeroPresent){
        printf("Cannot divide by 0!\n");
        return -999.0;
    }

    while(current != NULL){
        result /= current -> data;
        current = current -> next;
    }

    emptylist(list);

    return result;
}

/* double expoQueueRightToLeft(Queue *q) { */
/*     double base = peek(q); */
/*     dequeue(q); */
/*     if(base == 1.0) { */
/*         return 1; */
/*     }else if(base == 0.0) { */
/*         return NAN; */
/*     } */

/*     double expo = peek(q); */
/*     dequeue(q); */

/*     while(!isEmpty(q)) { */
/*         expo *= peek(q); */
/*         dequeue(q); */
/*     } */

/*     return powf(base, expo); */
/* } */

/* double logQueue(Queue *q, double result) { */
/*     dequeue(q); */

/*     if(isEmpty(q)) { */
/*         return result; */
/*     } */

/*     return logQueue(q, log(peek(q)) / log(result)); */
/* } */
