#include <stdio.h>
#include <stdlib.h>

void merge_sort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

int main(){

    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void merge_sort(int a[], int l, int r){

    if (l < r){
        int m = l + (r-l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void merge(int a[], int l, int m, int r){

    int i, j, k;
    int x = m - l + 1;
    int y = r - m;

    int *L = (int *)malloc(x * sizeof(int));
    int *R = (int *)malloc(y * sizeof(int));
    
    for (i = 0; i < x; i++){
        L[i] = a[l + i];
    }

    for (j = 0; j < y; j++){
        R[j] = a[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < x && j < y){

        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        } else{
            a[k] = R[j];
            j++;
        }   
        k++;
    }

    while (i < x){
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < y){
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
    





