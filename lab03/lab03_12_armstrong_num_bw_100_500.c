#include "../helpers.h"
#include <stdio.h>
// compile via
// gcc lab03_12_armstrong_num_bw_100_500.c ../helpers.c -lm

int main(void) {
    for (int i = 100; i <= 500; i++) {
        if (is_armstrong(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}