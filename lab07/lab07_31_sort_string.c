#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void swap_char(char *c1, char *c2);
void bubble_sort_string(char *str);

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

    char sorted_str[50];
    strcpy(sorted_str, str);
    bubble_sort_string(sorted_str);
    printf("%s\n", sorted_str);
}

void swap_char(char *c1, char *c2)
{
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

// sorts in increasing order
void bubble_sort_string(char *str)
{
    for (int i = 0; i < strlen(str) - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < strlen(str) - 1 - i; j++) {
            if (str[j] > str[j + 1]) {
                swap_char(&str[j], &str[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}