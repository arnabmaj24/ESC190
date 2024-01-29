#include <stdio.h>

void cha(int *a);
void swap(int *a, int*b);

int main() {

    int a = 42;
    int b = 420;

    cha(&a);

    printf("%d\n", a);

    swap(&b, &a);

    printf("%d\n", a);

    return 0;
}

void cha(int *a){

    *a = 69;
}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}