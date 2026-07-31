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

    appendNewNode(&mainList, addList(&mainList));
    /* appendNewNode(&mainList, subtractList(&mainList)); */
    /* appendNewNode(&mainList, multiplyList(&mainList)); */
    /* appendNewNode(&mainList, divideList(&mainList)); */

    printf("The new list is:\n");
    printList(&mainList);

    return 0;
}
