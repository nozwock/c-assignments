#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma ONCE

// #ifndef HELPERS_H
// #define HELPERS_H

typedef struct ArrWithSize {
    unsigned int *_arr;
    size_t arr_size;
} ArrWithSize;

typedef struct StrWithSize_ {
    char *_str;
    size_t size;
} StrWithSize;

int get_str_len(char[]);

bool is_armstrong(int);
bool is_prime(int);

unsigned long long get_factorial(int);
unsigned long long get_factorial_recurv(int);

ArrWithSize get_fibonacci_arr(int);
ArrWithSize get_prime_arr(int, int);

// #endif
