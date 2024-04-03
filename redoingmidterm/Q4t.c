#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void marks(const char *filename) {
    FILE *file = fopen(filename, "r");

    int highest_student = 0;
    int highest_avg = 0;

    char line[11 + 100*11];
    while (fgets(line, sizeof(line), file)) {
        int student_id, grade;
        int total_grade = 0;
        int num_grades = 0;

        char *token = strtok(line, " ");
        if (token == NULL)
            continue;
        student_id = atoi(token);

        while ((token = strtok(NULL, " ")) != NULL) {
            grade = atoi(token);
            total_grade += grade;
            num_grades++;
        }

        int average = num_grades > 0 ? total_grade / num_grades : 0;

        if (average > highest_avg) {
            highest_avg = average;
            highest_student = student_id;
        }
    }

    fclose(file);

    printf("Student with highest average: %d\n", highest_student);
    printf("Highest average: %d\n", highest_avg);
}

int main() {
    marks("stuff.txt");
    return 0;
}
