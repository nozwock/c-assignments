#include "helpers.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

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

ArrWithSize get_fibonacci_arr(int n) {
    ArrWithSize fib;
    fib.arr_size = n;
    fib._arr = calloc(fib.arr_size, sizeof(int));

    fib._arr[0] = 0;
    fib._arr[1] = 1;

    for (int i = 2; i < fib.arr_size; i++) {
        fib._arr[i] = fib._arr[i - 1] + fib._arr[i - 2];
    }

    return fib;
}