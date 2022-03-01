#include <ctype.h>
#include <stdio.h>
#include <string.h>

void remove_whitespaces(char *str);

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

    char new_str[str_sz];
    strcpy(new_str, str);
    remove_whitespaces(new_str);
    printf("%s\n%ld characters\n", new_str, strlen(new_str));
}

void remove_whitespaces(char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            // shifiting elems and reducing size of string
            int j;
            for (j = i; j < strlen(str) - 1; j++) {
                str[j] = str[j + 1];
            }
            i--;
            str[j] = '\0';
        }
    }
}