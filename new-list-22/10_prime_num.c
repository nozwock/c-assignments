#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_prime(int num);

int main(void)
{
    for (int i = 1; i <= 300; i++) {
        if (is_prime(i)) {
            printf("%d, ", i);
        }
    }
    printf("\n");
}

bool is_prime(int num)
{
    if (num < 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}