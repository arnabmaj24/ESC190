#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autocomplete.h" // Include the provided header file

int compare_terms(const void *a, const void *b) {
    return strcmp(((struct term *)a)->term, ((struct term *)b)->term);
}

int compare_terms_by_weight(const void *a, const void *b) {
    const struct term *termA = (const struct term *)a;
    const struct term *termB = (const struct term *)b;
    if (termA->weight < termB->weight) return 1;
    if (termA->weight > termB->weight) return -1;
    return 0;
}



void read_in_terms(struct term **terms, int *pnterms, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    int capacity = 1000; // Initial capacity, you can adjust this as needed
    *terms = (struct term *)malloc(capacity * sizeof(struct term));
    if (*terms == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int count = 0;
    char line[200]; // Assuming a maximum line length of 200 characters
    while (fgets(line, sizeof(line), file) != NULL) {
        // Trim the newline character if it exists
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // printf("Read line: %s\n", line); // Debugging print statement

        if (count >= capacity) {
            capacity *= 2;
            
            *terms = (struct term *)realloc(*terms, capacity * sizeof(struct term));
            if (*terms == NULL) {
                fprintf(stderr, "Memory reallocation failed\n");
                exit(1);
            }
        }

        char *tab = strchr(line, '\t');
        if (tab != NULL) {
            *tab = '\0'; // Split line into weight and term
            // printf("Term: %s, Weight: %s\n", tab + 1, line); // Debugging print statement
            strcpy((*terms)[count].term, tab + 1);
            (*terms)[count].weight = atof(line); // Convert string before tab to double
            count++;
        }
    }

    fclose(file);

    *pnterms = count;

    // Sort the terms array in lexicographic order
    qsort(*terms, count, sizeof(struct term), compare_terms);
}

int lowest_match(struct term *terms, int nterms, char *substr) {
    int low = 0;
    int high = nterms - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(terms[mid].term, substr, strlen(substr));
        
        printf("Comparing \"%s\" with \"%s\". Result: %d\n", substr, terms[mid].term, cmp);

        if (cmp < 0) {
            printf("Moving right\n");
            low = mid + 1;
        } else {
            if (cmp == 0) {
                printf("Potential match found at index %d\n", mid);
                result = mid;
            }
            printf("Moving left\n");
            high = mid - 1;
        }
    }

    return result;
}

int highest_match(struct term *terms, int nterms, char *substr) {
    int low = 0;
    int high = nterms - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strncmp(terms[mid].term, substr, strlen(substr));
        
        printf("Comparing \"%s\" with \"%s\". Result: %d\n", substr, terms[mid].term, cmp);

        if (cmp > 0) {
            printf("Moving left\n");
            high = mid - 1;
        } else {
            if (cmp == 0) {
                printf("Potential match found at index %d\n", mid);
                result = mid;
            }
            printf("Moving right\n");
            low = mid + 1;
        }
    }

    return result;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr) {
    // Find the range of terms that match the given substring
    int first_index = lowest_match(terms, nterms, substr);
    int last_index = highest_match(terms, nterms, substr);

    // Debugging statements
    // printf("First Index: %d, Last Index: %d\n", first_index, last_index);

    // If no match found, return empty answer
    if (first_index == -1 || last_index == -1) {
        *n_answer = 0;
        *answer = NULL;
        return;
    }

    // Calculate the number of matching terms
    int num_matches = last_index - first_index + 1;

    // Debugging statement
    // printf("Number of Matches: %d\n", num_matches);

    // Allocate memory for the answer array
    *answer = (struct term *)malloc(num_matches * sizeof(struct term));
    if (*answer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Copy matching terms to the answer array
    memcpy(*answer, &terms[first_index], num_matches * sizeof(struct term));

    // Sort the answer array by weight in non-increasing order
    qsort(*answer, num_matches, sizeof(struct term), compare_terms_by_weight);

    // Update the number of answers
    *n_answer = num_matches;
}

int main() {
    struct term *terms;
    int nterms;

    // Example usage
    read_in_terms(&terms, &nterms, "cities.txt");

    // Sort the terms array in lexicographic order
    qsort(terms, nterms, sizeof(struct term), compare_terms);

    // Example usage of autocomplete
    char substr[] = "Tor";
    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, substr);

    // Displaying the autocomplete results
    printf("Autocomplete results for \"%s\":\n", substr);
    for (int i = 0; i < n_answer; i++) {
        printf("%s\t%.2f\n", answer[i].term, answer[i].weight);
    }

    // Free allocated memory
    free(answer);
    free(terms);

    return 0;
}