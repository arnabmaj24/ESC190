#include <stdio.h>

void pr(char *x);

int main(){

    pr("hello world");

    return 0;

}

void pr(char *x){
    printf("%s\n", x);
}
