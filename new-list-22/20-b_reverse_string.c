#include <stdio.h>
#include <string.h>

void get_reversed_string(char *str_from, char *str_to);

int main(void)
{
    char str_buffer[1000];
    char *_str = str_buffer;
    printf("enter a string: ");
    scanf("%[^\n]s%*c", _str);

    char *_reversed_str = &_str[strlen(_str) + 2];
    get_reversed_string(_str, _reversed_str);

    printf("\noriginal string:\n%s\n", _str);
    printf("reversed string:\n%s\n", _reversed_str);
}

void get_reversed_string(char *str_from, char *str_to)
// write revesed of *str_from to *str_to
{
    size_t len = strlen(str_from);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        str_to[j] = str_from[i];
    }
    str_to[j] = '\0';
}