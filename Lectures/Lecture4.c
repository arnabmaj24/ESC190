#include <stdio.h>

int main() {

    int a = 42; // int declare
    long int la = 1234567897; // longer int
    
    char c = 'f'; // just a char

    char *s = "String"; // string stored as the first characters pointer
    // int p_s = &s; //adress of s, problem

    // -------------------------------------------------------------------

    // arrays and stuff ig

    printf("%d\n", a);

    //double s = sum(1,2,3,45);
    //printf("%ld\n", s);

    char *str = "hello";
    //printf("%s\n is stored at adress %ld", str, (long int)str);
    

    int arr[] = {5,6,7};
    printf("%ld\n", arr);
    printf("%d\n", arr[0]);
    printf("%d\n", *arr+2);

    return 0;
}