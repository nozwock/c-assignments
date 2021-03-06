#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

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

uint64_t get_factorial(int);
uint64_t get_factorial_recurv(int);

ArrWithSize_int64_t get_fibonacci_arr(int);
ArrWithSize_int64_t get_prime_arr(int, int);

// #endif
