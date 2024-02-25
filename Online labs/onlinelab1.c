#include <stdio.h>


int linear_search(int *a, int sz, int elem) {
    for (int i = 0; i < sz; ++i) {
        if (a[i] == elem) {
            return i; // return the index of the first occurrence
        }
    }
    return 1;
}


void reverse_arr(int *arr, int sz) {
    int temp;
    for (int i = 0; i < sz / 2; ++i) {
        temp = arr[i];
        arr[i] = arr[sz - i - 1];
        arr[sz - i - 1] = temp;
    }
}


int main (){

    return 0;
}

