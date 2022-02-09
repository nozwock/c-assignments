#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n);

int main(void) {
    for (int i = 1; i <= 300; i++) {
        if (is_prime(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

bool is_prime(int n) {
    if (n < 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}