#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void destroy(student1 *p_s){
    free(p_s);
}


void printStudentInfo(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}





int main() {
    // Create a sample student
    student1 sampleStudent = {"John Doe", "1234567890", 3};

    destroy(&sampleStudent);


    return 0;
}