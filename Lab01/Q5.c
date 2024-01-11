#include <stdio.h>

int strrrrlen(char s[]);

int main(){

    char str[] = "gay boy";
    printf("%s\n", str);
    int x = strrrrlen(str);
    printf("%d", x);
    return 0;
}

int strrrrlen(char s[]){
    int i =0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}