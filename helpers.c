#include <math.h>
#include <stdbool.h>

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

bool is_armstrong(int n) {
    int i = n, r, sum = 0;

    while (i > 0) {
        r = i % 10;
        sum += (r * r * r);
        i /= 10;
    }

    if (n == sum) {
        return true;
    }

    return false;
}