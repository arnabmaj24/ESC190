#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student1{
char name[3];
int age;
} student1;


void chang(student1 *S, char* name){

    strcpy(S->name, name);
}

int main() {

    student1 S;

    strcpy(S.name, "ee");
    S.age = 11;

    chang(&S, "ab");

    printf(S.name);

    return 0;
}