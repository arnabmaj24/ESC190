#include <stdio.h>

typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void printStudentInfo(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}

int main() {
    // Create a sample student
    student1 sampleStudent = {"John Doe", "1234567890", 3};

    // Call the function to print the information
    printStudentInfo(sampleStudent);

    return 0;
}