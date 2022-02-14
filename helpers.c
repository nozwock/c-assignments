#include "helpers.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int get_str_len(char str[]) {
    int i = 0;
    while (true) {
        if (str[i] == '\0') {
            return i;
        }
        i++;
    }
}

bool is_prime(int num) {
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

bool is_armstrong(int num) {
    int tmp = num, rem, sum = 0;

    while (tmp > 0) {
        rem = tmp % 10;
        sum += (rem * rem * rem);
        tmp /= 10;
    }

    if (num == sum) {
        return true;
    }

    return false;
}

unsigned long long get_factorial(int num) {
    // for +ve only
    unsigned long long out = 1;
    if (num < 0) {
        return 0;
    }
    for (int i = 1; i <= num; i++) {
        out *= i;
    }
    return out;
}

unsigned long long get_factorial_recurv(int num) {
    // for +ve only
    if (num < 0) {
        return 0; // err
    }
    if (num == 0) {
        return 1;
    }
    return num * get_factorial_recurv(num - 1);
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

ArrWithSize get_prime_arr(int lower, int upper) {
    ArrWithSize prime;
    prime.arr_size = 0;
    prime._arr = calloc(prime.arr_size, sizeof(int));
    for (int i = lower; i < upper; i++) {
        // not a great impl but whatever
        int j;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (i % j != 0) {
            prime.arr_size++;
            prime._arr = realloc(prime._arr, prime.arr_size * sizeof(int));
            prime._arr[prime.arr_size - 1] = i;
        }
    }
    return prime;
}
