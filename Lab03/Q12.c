#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"


void printStudentInfo(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}

int main() {

    student1 s = {"bob", "12345678901", 3};

    printStudentInfo(s);

    return 0;

}