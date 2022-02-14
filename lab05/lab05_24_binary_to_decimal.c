#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../helpers.h"

// probab just get the size of str via a length() func or something
// so that there wont be a need to pass many args
int binary_to_decimal(StrWithSize);

int main(void) {
    StrWithSize bin;
    bin._str = "11110111";
    bin.size = 8;
    int num = binary_to_decimal(bin);
    printf("decimal value of %s is %d\n", bin._str, num);
}

int binary_to_decimal(StrWithSize bin) {
    int num = 0;
    for (int i = bin.size - 1; i >= 0; i--) {
        num += (bin._str[i] - '0') * pow(2, bin.size - 1 - i);
    }
    return num;
}