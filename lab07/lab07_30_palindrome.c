#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/helpers.h"

int main(void)
{
    int c, str_sz = 0;
    char str[50];
    printf("enter string: ");
    // Iteratively get characters from standard input, checking for CR (Mac OS),
    // LF (Linux), and CRLF (Windows)
    while ((c = fgetc(stdin)) != '\r' && c != '\n' && c != EOF) {
        str[str_sz++] = c;
    }
    str[str_sz] = '\0';

    char reversed_str[50];
    strcpy(reversed_str, str);
    reverse_string(reversed_str);
    printf("%s is ", str);
    if (!strcmp(str, reversed_str)) {
        printf("a palindrome\n");
    } else {
        printf("not a palindrome\n");
    }
}