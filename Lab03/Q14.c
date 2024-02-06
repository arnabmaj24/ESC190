#include <stdio.h>
#include <stdlib.h>

double calculateAverage(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return 0.0;
    }

    int sum = 0;
    int count = 0;
    char line[200];
    while (fgets(line, sizeof(line), fp)) {
        int num = atoi(line);
        sum += num;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No integers found in file %s\n", filename);
        return 0.0;
    }

    return (double)sum / count;
}

int main() {
    const char *filename = "numbers.txt";
    double average = calculateAverage(filename);
    printf("Average of integers in file %s: %.2f\n", filename, average);
    return 0;
}