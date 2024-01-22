#include<stdio.h>
#include<stdlib.h>


void func(char **c, int *length);

int main(){

    char *string;
    int length;

    func(&string, &length);

    printf("\nString obtained from user: %s\n", string);

    // Free the allocated memory
    free(string);


    return 0;
}

void func(char** c, int* length){

    printf("Enter the length of your string:");
    scanf("%d", length);

    *c = (char *)malloc((*length+1)*sizeof(char));

    printf("enter string line by line: \n");

    for (int i = 0; i < *length; ++i) {
        scanf(" %c", &(*c)[i]); // Note the space before %c to skip leading whitespaces
    }

    (*c)[*length] = '\0';






}