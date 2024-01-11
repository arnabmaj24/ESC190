#include <stdio.h>

void change(char *pChange);


int main() {
    // Declare and initialize an array of characters
    char myArray[] = {'I', 'a', 'm', 'g', 'a', 'y', '\0'};  // '\0' denotes the end of the string
    // Print the string using printf
    printf("%s\n", myArray);

    change(&myArray[3]);

    printf("%s\n", myArray);

    return 0;
}

void change(char *pChange){
    *pChange = '0';
}