#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../helpers.h"

// DONE: probab just get the size of str via a length() func or something
// so that there wont be a need to pass many args
int binary_to_decimal(char[]);

int main(void) {
    char bin[] = "11110111";
    printf("decimal value of %s is %d\n", bin, binary_to_decimal(bin));
}

int binary_to_decimal(char bin[]) {
    int num = 0;
    int length = get_str_len(bin);
    for (int i = length - 1; i >= 0; i--) {
        num += (bin[i] - '0') * pow(2, length - 1 - i);
    }
    return num;
}