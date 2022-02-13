#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrWithSize {
    int *_arr;
    size_t arr_size;
} ArrWithSize;

int get_approx_num_of_primes(int);
ArrWithSize get_prime_arr(int, int);

int main(void) {
    ArrWithSize prime = get_prime_arr(1, 300);
    for (int i = 0; i < prime.arr_size; i++) {
        printf("%d, ", prime._arr[i]);
    }
    printf("\n");
    free(prime._arr);
}

int get_approx_num_of_primes(int n) {
    // π(x) i.e. number of primes under x = (x/(ln(x)-1))*1.01
    // 1.01 is offset here
    // https://primes.utm.edu/howmany.html
    return (n / (log(n) - 1)) * 1.01;
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