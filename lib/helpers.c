#include "helpers.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int get_string_length(char str[])
{
    int offset = 0;
    while (str[offset] != '\0') {
        offset++;
    }
    return offset;
}

void reverse_string(char str[])
{
    char tmp;
    int len = get_string_length(str);
    for (int i = 0; i < len / 2; i++) {
        tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}

void get_reversed_string(char str_from[], char str_to[])
{
    size_t len = get_string_length(str_from);
    int i, j;
    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        str_to[j] = str_from[i];
    }
    str_to[j] = '\0';
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

bool is_armstrong(int num)
{
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

unsigned long long get_factorial(int num)
{
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

unsigned long long get_factorial_recurv(int num)
{
    // for +ve only
    if (num < 0) {
        return 0; // err
    }
    if (num == 0) {
        return 1;
    }
    return num * get_factorial_recurv(num - 1);
}

ArrWithSize_int64_t get_fibonacci_arr(int n)
{
    ArrWithSize_int64_t fib;
    fib.size = n;
    fib._arr = calloc(fib.size, sizeof(int));

    fib._arr[0] = 0;
    fib._arr[1] = 1;

    for (int i = 2; i < fib.size; i++) {
        fib._arr[i] = fib._arr[i - 1] + fib._arr[i - 2];
    }

    return fib;
}

ArrWithSize_int64_t get_prime_arr(int lower, int upper)
{
    ArrWithSize_int64_t prime;
    prime.size = 0;
    prime._arr = calloc(prime.size, sizeof(int));
    for (int i = lower; i < upper; i++) {
        // not a great impl but whatever
        int j;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (i % j != 0) {
            prime.size++;
            prime._arr = realloc(prime._arr, prime.size * sizeof(int));
            prime._arr[prime.size - 1] = i;
        }
    }
    return prime;
}
