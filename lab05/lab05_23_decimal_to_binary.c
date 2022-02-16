#include <stdio.h>
#include <stdlib.h>
#include "../lib/helpers.h"

char *_decimal_to_binary(int);

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    char *_str = _decimal_to_binary(num);
    printf("binary of %d is %s\n", num, _str);
}

char *_decimal_to_binary(int num) {
    int len = 0;
    char *bin = calloc(len + 1, sizeof(char));
    bin[len] = '\0';

    for (int i = num; i != 0; i /= 2) {
        len++;
        bin = realloc(bin, (len + 1) * sizeof(char));
        bin[len - 1] = i % 2 + '0';
    }

    reverse_string(bin);

    return bin;
}