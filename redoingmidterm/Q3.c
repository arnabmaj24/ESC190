#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int same(char a, char b){
    if (b == '\0'){
        return 0;
    }

    if (a == b){
        return 1;
    }
    return -1;
}

int recurr(char *a, char *b, int i, int j){
    if (same(a, b) == 0){
    return i;
    }

    if (same(a+i, b+j) == 1){
        recurr(a, b, 1+i, 1+j);
    }
    if (same(a+i, b+j) == -1){
        recurr(a,b,i+1,0);
    } 

}

int main() {
    char arr[] = "aEngSciEngSciTrackOne";
    char arr2[] = "EngSci";

    printf("%d\n", recurr(arr, arr2, 0, 0));

    return 0;
}