#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

void g(int *arr, int n){
    qsort(arr, n, sizeof(int), cmp);
    for (int i =0;i<n;i++){
        if (i == n-1){
            printf("%d", arr[i]);
            return;
        } else{
        printf("%d, ", arr[i]);}
    }

}


int main() {
    int arr[] = {5,6,1,3,4,7};
    int n = 6;
    g(arr, n);




    return 0;
}