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
    for (i=0; i < arr1_sz - arr2_sz + 1; i++){
        
        int true = 1; 

        printf("%d %d out\n", arr1[i+j], arr2[j]);

        for (j = 0; j < arr2_sz; j++){
            if (arr1[i+j] != arr2[j]){
                true = 0;
                break;
            }
        }

        if (true == 1){
            for (int l = 0; l < arr2_sz; l++){
                arr1[i+l] = 0;
            }
        }
    }
}

