#include <stdio.h>

void selectionsort(int a[], int size);
void bubblesort(int a[], int size);
void insertionsort(int arr[], int size);

int main(){
    int i = 0;
    int a[5] = {6, 2, 10, 3, 1};
    // initialize i to 0, run the loop while i < 5, and increase i by 1 every time;
    // Here, i++ is the same as i = i + 1
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
        }
    printf("\n");
    insertionsort(a, sizeof(a)/4);
    i = 0;
    while(i < 5){
        printf("%d ", a[i]);
        i++; // same as i = i + 1
}
   
}


void bubblesort(int a[], int size){
    int i = 0;
    int j = 0;
    for(i = 0; i < size; i++){
        for(j =0 ;j<(size-i-1);j++){
            if (a[j] < a[j+1]){
                int *pJ = &a[j];
                int *pJO = &a[j+1];
                
                int temp = *pJ;
                *pJ = *pJO;
                *pJO = temp;                          
            }
        }
    }
}

void selectionsort(int a[], int size){
    int i = 0;
    int j = 0;
    for (i = 1; i < size; i++){
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }

}

void insertionsort(int arr[], int size){
    int i, key, j;

    for (i=0;i<size;i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    
    }



}