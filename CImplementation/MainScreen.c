#include <ctype.h>
#include <string.h>
#include <math.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "MathHandler.h"

int main() {
    struct List mainList;
    initializeList(&mainList);

    appendNewNode(&mainList, 1.0);
    appendNewNode(&mainList, 2.0);
    appendNewNode(&mainList, 3.0);
    appendNewNode(&mainList, 0.0);

    printf("The old list is:\n");
    printList(&mainList);
    printf("\n");

    printf("The value is zeroPresent is: %b\n", isZeroPresent(&mainList));
    double newValue = multiplyList(&mainList);
    appendNewNode(&mainList, newValue);

    printf("The new list is:\n");
    printList(&mainList);

    /* enqueue(&mainQueue, subtractQueue(&mainQueue, peek(&mainQueue))); */
    /* enqueue(&mainQueue, multiplyQueue(&mainQueue, peek(&mainQueue))); */
    /* enqueue(&mainQueue, divideQueue(&mainQueue, peek(&mainQueue))); */
    /* enqueue(&mainQueue, value); */

    return 0;
}
