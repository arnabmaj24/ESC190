#include <stdio.h>
#include <ctype.h>

int my_atoi(char *str);

int main () {

    char c[] = "123456";

    printf("%d\n", my_atoi(c));

    return 0;
}

int my_atoi(char *str){

    int res = 0;
    int i = 0;

    while (str[i] != '\0'){

        if (isdigit(str[i])){
            res = res * 10 + str[i]-'0';
        }i++;
    }

    return res;



}