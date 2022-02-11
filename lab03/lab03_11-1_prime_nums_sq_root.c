#include <math.h>
#include <stdio.h>
#include "../helpers.h"
// compile via:
// gcc lab03_11-1_prime_nums_sq_root.c ../helpers.c -lm

int main(void) {
    for (int i = 1; i <= 300; i++) {
        if (is_prime(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}