#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1 {
    char name[200];
    char student_number[11];
    int year;
} student1;

typedef struct student2 {
    char *name;
    char student_number[11];
    int year;
} student2;

void modify_student1_name(student1 *s) {
    strcpy(s->name, "Modified Name");
}

void modify_student2_name(student2 *s) {
    s->name = strdup("Modified Name");
    if (s->name == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void print_student1(student1 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}

void print_student2(student2 s) {
    printf("Name: %s\n", s.name);
    printf("Student Number: %s\n", s.student_number);
    printf("Year: %d\n", s.year);
    printf("\n");
}

int main() {
    // For student1
    student1 s1 = {"Original Name", "1234567890", 3};
    modify_student1_name(&s1);
    printf("After modification - Student1:\n");
    print_student1(s1); // Print to see if modification reflected

    // For student2
    student2 s2 = {"Original Name", "1234567890", 3}; // No memory allocation for name field
    modify_student2_name(&s2);
    printf("After modification - Student2:\n");
    print_student2(s2); // Print to see if modification reflected

    // Free dynamically allocated memory
    free(s2.name);

    return 0;
}