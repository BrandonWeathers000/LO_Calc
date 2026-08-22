#ifndef MATHHANDLER_H

#define MATHHANDLER_H
#define MAX_SIZE 1000

struct Node{
    double data;
    struct Node *next;
};

struct List{
    struct Node *head;
    struct Node *tail;
};

// Start of data structures
void initializeList(struct List *list);
void appendNewNode(struct List *list, double newData);
void printList(struct List *list);
double addList(struct List *list);
double subtractList(struct List *list);
double multiplyList(struct List *list);
double divideList(struct List *list);
// End of data structures

/* double addQueue(Queue *q, double result); */
/* double subtractQueue(Queue *q, double result); */
/* double multiplyQueue(Queue *q, double result); */
/* double divideQueue(Queue *q, double result); */
/* double expoQueueRightToLeft(Queue *q); */
/* double logQueue(Queue *q, double result); */

#endif
