#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student2{
char *name;
char *student_number;
int year;
} student2;

void create_block2(student2 **p_p_s, int num_students){

    *p_p_s = (student2 *)malloc(num_students * (sizeof(student2)));

    for (int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = NULL;
        (*p_p_s)[i].student_number = 0;
    }


}

void set_name2(student2 *p_s, const char *new_name){

    p_s->name = (char *)malloc((strlen(new_name)+1));
    if (p_s->name == NULL) {
        printf("Memory allocation failed\n");
        exit(1);

    }
    strcpy(p_s->name, new_name);
}

void destroy_block2(student2 *block, int num_students) {
    if (block == NULL) {
        printf("Block is already NULL\n");
        return;
    }
    // Free memory allocated for names and student_numbers for each student2
    for (int i = 0; i < num_students; i++) {
        free(block[i].name);
        free(block[i].student_number);
    }
    // Free memory allocated for the block itself
    free(block);
}

int main() {
    // Example usage
    int num_students = 3;
    student2 *block;
    create_block2(&block, num_students);

    // Set name for first student
    set_name2(&block[0], "John Doe");

    // Verify using printf
    printf("Name of first student: %s\n", block[0].name);

    // Destroy the block to free memory
    destroy_block2(block, num_students);

    return 0;
}
