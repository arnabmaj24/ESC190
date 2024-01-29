#include <stdio.h>
#include <stdlib.h>

typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void create_block1(student1 **p_p_s, int n_students){

    *p_p_s = (student1 *)malloc(n_students * (sizeof(student1)));    
    
}

int main(){

    student1 *studentBlock;
    create_block1(&studentBlock, 5);
    free(studentBlock);
}