#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../helpers.h"

int binary_to_decimal(char[]);

int main(void) {
    char bin[] = "11110111";
    printf("decimal value of %s is %d\n", bin, binary_to_decimal(bin));
}

int binary_to_decimal(char bin[]) {
    int num = 0;
    int length = get_str_len(bin);
    for (int i = length - 1; i >= 0; i--) {
        // do a bound check i.e. char should be only 0 or 1
        if (bin[i] - '0' != 0 && bin[i] - '0' != 1) {
            return 0;
        }
        num += (bin[i] - '0') * pow(2, length - 1 - i);
    }
    return num;
}