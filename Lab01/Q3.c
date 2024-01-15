#include <stdio.h>

void change(char a[], int len);


int main() {
    // // Declare and initialize an array of characters
    // char myArray[] = {'I', 'a', 'm', 'g', 'a', 'y', '\0'};  // '\0' denotes the end of the string
    // // Print the string using printf
    // printf("%s\n", myArray);

    // change(&myArray[3]);

    // printf("%s\n", myArray);

    char a[100];

    change(a, 100);

    printf(a);


    return 0;
}

void change(char a[], int len){
    
    int i = 0;
    for (i=0;i<len;i++){
        a[i] = 'f';
    }
}