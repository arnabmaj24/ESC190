#include <stdio.h>

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz);

int main(){

    int a[] = {5, 6, 7, 8, 6, 7};
    int b[] = {6, 7};
    seq_replace(a, 6, b, 2);

    int i = 0;
    for(i = 0; i < 6; i++){
        printf("%d ", a[i]);
        }
    printf("\n");

    return 0;
}

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){

    int i = 0;
    int j = 0;
    for (i=0; i < arr1_sz; i++){
        for (j=0; j < arr2_sz; j++){
            if (arr1[i] == arr2[j]){
                arr1[i] = 0;
            }
        }
    }


}
