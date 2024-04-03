#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct LL {
    node *head;
} LL;

void cn(node **p, int data) {
    *p = (node *)malloc(sizeof(node));
    (*p)->data = data;
    (*p)->next = NULL;
}

int len(LL *head) {
    node *curr = head->head;
    int n = 0;
    while (curr != NULL) {
        n++;
        curr = curr->next;
    }
    return n;
}

int cmp(const void *a, const void *b){
    int *p = (int*)a;
    int *q = (int*)b;
    return *p-*q;
}

int median(LL *list) {
    int n = len(list);
    node *pt = list->head;

    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        // Handle memory allocation failure
        return -1;
    }

    int i = 0;
    while (pt != NULL) {
        arr[i] = pt->data;
        i++;
        pt = pt->next;
    }

    qsort(arr, n, sizeof(int), cmp);

    int median = arr[(n - 1) / 2];

    free(arr);

    return median;
}


int main() {
    LL *head = (LL *)malloc(sizeof(LL)); // Allocate memory for LL
    node *a, *b, *c;
    cn(&a, 6);
    cn(&b, 10);
    cn(&c, 9);
    head->head = a;
    a->next = b;
    b->next = c;

    int l = len(head);
    printf("%d\n", l);

    int med = median(head);




    printf("%d\n", med);

    // Free memory allocated for arr

    // Freeing memory
    node *curr = head->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    // Free memory allocated for LL
    free(head);

    return 0;
}