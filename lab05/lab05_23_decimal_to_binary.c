#include <stdio.h>
#include <stdlib.h>

typedef struct StrWithSize_ {
    char *_str;
    size_t size;
} StrWithSize;

StrWithSize decimal_to_binary(int);

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    StrWithSize bin = decimal_to_binary(num);
    printf("binary of %d is %s\n", num, bin._str);
    free(bin._str);
}

StrWithSize decimal_to_binary(int num) {
    StrWithSize bin;
    bin.size = 0;
    // have the size it returns be 1 less
    // which is length of string without \0 char
    bin._str = calloc(bin.size + 1, sizeof(char));
    bin._str[bin.size] = '\0';

    for (int i = num; i != 0; i /= 2) {
        bin.size++;
        bin._str = realloc(bin._str, bin.size + 1 * sizeof(char));
        bin._str[bin.size - 1] = i % 2 + '0';
    }

    // Swap character starting from two corners
    char tmp;
    for (int i = 0; i < bin.size / 2; i++) {
        tmp = bin._str[i];
        bin._str[i] = bin._str[bin.size - i - 1];
        bin._str[bin.size - i - 1] = tmp;
    }

    return bin;
}