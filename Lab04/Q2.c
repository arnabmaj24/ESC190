#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double sum_constants(FILE *file) {
    double sum = 0.0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        char *equation = line;
        double value = 0.0;

        // Skip whitespace
        while (*equation != '\0' && isspace(*equation)) {
            equation++;
        }

        // Find the position of the equal sign
        char *equal_sign = equation;
        while (*equal_sign != '\0' && *equal_sign != '=') {
            equal_sign++;
        }

        // Skip if no equal sign found
        if (*equal_sign == '\0') {
            continue;
        }

        // Skip whitespace between variable name and equal sign
        while (equation != equal_sign && isspace(*equation)) {
            equation++;
        }

        // Parse the value after the equal sign
        value = strtod(equal_sign + 1, NULL);

        // Add the value to the sum
        sum += value;
    }

    return sum;
}

int main() {
    FILE *file = fopen("consts.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    double total = sum_constants(file);
    printf("Total sum of constants: %.15lf\n", total);

    fclose(file);
    return 0;
}