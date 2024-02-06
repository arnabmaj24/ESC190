#include <stdio.h>

int main() {
    int *ptr = NULL; // Initialize pointer to NULL

    // Attempting to dereference a null pointer
    printf("%d\n", *ptr); // This will cause a segmentation fault

    return 0;
}