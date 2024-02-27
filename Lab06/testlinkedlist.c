#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q1.h"


int main () {

    LL *list = (LL *)malloc(sizeof(LL));
    list->head = NULL;
    list->size = 0;

    LL_append(list, 10);
    LL_append(list, 11);
    LL_append(list, 12);

    printLinkedList(list);
    printf("%d\n", validatelistlength(list));
    del(list, 1);
    printLinkedList(list);
    freeLinkedList(list);
    return 0;
}