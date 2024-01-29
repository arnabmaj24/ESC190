#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1{
char name[20];
char student_number[11];
int year;
} student1;

void set_name(student1 *p_s, char *new){
    strncpy(p_s->name, new, 20);
    p_s->name[19] = '\0';
}


void printStudentInfo(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}




int main() {
    // Create a sample student
    student1 student = {"John Doe", "1234567890", 3};

    printStudentInfo(student);

    set_name(&student, "This is a very long name which is longer than 199 charactersThis is a very long name which is longer than 199 characters.This is a very long name which is longer than 199 characters. This part should be truncated.his part should be truncated.This is a very long name which is longer than 199 characters.This is a very long name which is longer than 199 characters. This part should be truncated.his part should be truncated.. truncated..");

    // Verify the name using printf
    printStudentInfo(student);

    return 0;
}