#include <stdio.h>

void printFileContents(const char *filename) {
    char line[200];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    printf("Contents of file %s:\n", filename);
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

int main() {
    const char *filename = "example.txt";
    printFileContents(filename);
    return 0;
}