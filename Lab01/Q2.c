#include <stdio.h>

int ten(int x);


int main(){

    int a = 5;
    printf("%d\n", a);
    a  = ten(a);
    printf("%d\n", a);


    return 0;
}

int ten(int x){
    x = 10;
    return x;

}