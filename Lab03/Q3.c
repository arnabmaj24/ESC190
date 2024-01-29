#include <stdio.h>
#include <string.h>

typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void set_default_name(student1 *p_s){
    strcpy(p_s->name, "Default Student");
    (*p_s).year = 0;
}


void printStudentInfo(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}

void set_default_name_wrong(student1 s){

    // strcpy(s->) <- throwing an error.

}


int main() {
    // Create a sample student
    student1 sampleStudent = {"John Doe", "1234567890", 3};

    // Call the function to print the information
    set_default_name(&sampleStudent);

    printStudentInfo(sampleStudent);



    return 0;
}