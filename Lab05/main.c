#include <stdio.h>
#include "intlist.h"
#include <stdlib.h>
#include <string.h>



int main() {
    IntList *theptr;

    int list[] = {1, 2, 34, 5, 6, 7, 5, 6, 6, 55};
    create_list_from_data(&theptr, list, 10);
    printy(theptr);

    list_append(theptr, 5);
    printy(theptr);
    list_insert(theptr, 100, 2);
    printy(theptr); 
    list_destroy(theptr);

    return 0;
}





void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    // Allocate memory for the IntList structure
    *p_IntList = (IntList*)malloc(sizeof(IntList));
    if (*p_IntList == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the data array
    (*p_IntList)->data = (int*)malloc(sizeof(int) * size);
    if ((*p_IntList)->data == NULL) {
        free(*p_IntList);  // Free the previously allocated structure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Initialize size and capacity
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size; 
    // Copy data_arr to the data array
    for (int i = 0; i < size; i++) {
        (*p_IntList)->data[i] = data_arr[i];
    }
}


void list_append(IntList *list, int new_elem){
    
    list->capacity += sizeof(int); //increase capacity by what we are adding

    list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    if (list->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    list->data[list->size] = new_elem;
    list->size++;
}

void list_insert(IntList *list, int new_elem, int index){

    list->capacity += sizeof(int);
    list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    list->data[list->size] = 0;

    for (int i = list->size;i>index;i--){
        int temp = list->data[i];
        list->data[i] = list->data[i-1];
        list->data[i-1] = temp;
    }

    list->data[index] = new_elem;
}

void list_delete(IntList *list, int index){

    list->data[index] = '\0'; //just to keep track ig

    for (int i = list->size-1;i>index;i--){
        int temp = list->data[i];
        list->data[i] = list->data[i-1];
        list->data[i-1] = temp;
    }
    list->size--;

}

void list_destroy(IntList *list){
    free(list->data);
    free(list);
}

int list_get(IntList *list, int index){
    return list->data[index];
}

void printy(IntList *list){
    for (int i=0; i<list->size;i++){
        printf("%d ", list->data[i]);
    }
    printf("\n");
}
