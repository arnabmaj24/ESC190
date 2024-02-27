#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
int data;
struct node *next;
} node;
typedef struct LL{
node *head;
int size;
} LL;

void LL_append(LL *my_list, int new_elem)
{
    node *appended = (node *)malloc(sizeof(node));
    appended->data = new_elem;
    appended->next = NULL;

    if (my_list->head == NULL){
        my_list->head = appended;
    } else {
        node *curr = my_list->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = appended;
    }

    my_list->size++;
}

void printLinkedList(LL *list) {
    node *current = list->head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(LL *list) {
    node *current = list->head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}


int validatelistlength(LL *list){

    int count = 0;

    node *current = list->head;
    while (current != NULL) {
        node *temp = current;
        current = current->next;
        count++;
    }
    if (count == list->size){
        return 1;
    } else {
        return 0;
    }
}

void del(LL *list, int index){


    
    node *current = list->head;
    if (index == 0) {
        list->head = current->next;
        free(current);
        list->size--;
        return;
    }


    for (int i = 0; i < index-1; i++){
        node *temp = current;
        current = current->next;
    }
    node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;

}