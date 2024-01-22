#include <stdio.h>
#include <string.h>

void stricatforce(char *s1, char *s2, int len1, int len2);

int main() {
   char str1[100] = "ESC", str2[] = "190";

   // concatenates str1 and str2
   // the resultant string is stored in str1.
   strcat(str1, str2);

   puts(str1);
   puts(str2);

   return 0;
}


void stricatforce(char *s1, char *s2, int len1, int len2){

    for (int i = len1; i < len1+len2+1; i++){

        s1[len1] = s2[i-len1];
    }
}

