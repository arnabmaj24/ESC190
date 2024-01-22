#include <stdio.h>

int same(char *a, char *b, int index);

int main() {

    char *s1 = "Gay";
    char *s2 = "gay";

    int result = same(s1, s2, 0);
    printf("Result: %d\n", result);

}

int same(char *a, char *b, int index){
    
    if (a[index] == b[index]){

        if (a[index] == '\0'){
            return 0;
        }

        return same(a, b, index+1);

    }else{

        if (a[index] > b[index]){
            return 1; 
    }else{
        return 2;
        }
    }
}
    