#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#pragma once

// #ifndef HELPERS_H
// #define HELPERS_H

typedef struct {
    int64_t *_arr;
    size_t size;
} ArrWithSize_int64_t;

int get_string_length(char[]);
void reverse_string(char[]);
void get_reversed_string(char[], char[]);

bool is_armstrong(int);
bool is_prime(int);

unsigned long long get_factorial(int);
unsigned long long get_factorial_recurv(int);

ArrWithSize_int64_t get_fibonacci_arr(int);
ArrWithSize_int64_t get_prime_arr(int, int);

// #endif
