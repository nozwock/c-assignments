#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void swap_char(char *c1, char *c2);
void bubble_sort_string(char *str);

int main(void)
{
    char str_buffer[1000];
    char *_str = str_buffer;
    printf("enter string: ");
    scanf("%[^\n]s%*c", _str);

    printf("\ngiven string: %s\n", _str);

    char sorted_str[1000];
    strcpy(sorted_str, _str);
    bubble_sort_string(sorted_str);
    printf("sorted string: %s\n", sorted_str);
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