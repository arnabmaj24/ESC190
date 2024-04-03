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

int main() {
    LL *head;
    node *a,*b,*c;
    cn(&a, 0);
    cn(&b, 4);
    cn(&c, 6);
    head->head = a;
    a->next = b;
    b->next = c;

    int l = len(head);
    printf("%d\n", l);

    int *arr = (int *)malloc(sizeof(int) * l);
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head->head;
    int i = 0;
    while (ptr != NULL){
        arr[i] = ptr->data;
        i++;
        ptr = ptr->next;
    }

    qsort(arr,l,sizeof(int),cmp);

    int avg = arr[(l)/2 - 1];

    printf("%d", avg);
        // Freeing memory
    node *curr = head->head;
    while (curr != NULL) {
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}
