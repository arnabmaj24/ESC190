#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int last_occ(char *arr1, char *arr2) {
    int n = strlen(arr1);
    int m = strlen(arr2);
    int last = -1;

    for (int i = n - m; i >= 0; i--) {
        int same = 1;
        for (int j = 0; j < m; j++) {
            if (arr1[i + j] != arr2[j]) {
                same = 0;
                break;
            }
        }
        if (same == 1) {
            last = i;
            break;
        }
    }
    return last;
}

int main() {
    char arr[] = "EngSciEngSciTrackOne";
    char arr2[] = "EngSci";

    printf("%d\n", last_occ(arr, arr2));

    return 0;
}