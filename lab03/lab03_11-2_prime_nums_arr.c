#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct PrimeArr {
    int *_arr;
    size_t arr_size;
} PrimeArr;

int get_approx_num_of_primes(int n);
PrimeArr get_prime_arr(int lower, int upper);

int main(void) {
    PrimeArr prime = get_prime_arr(1, 300);
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

PrimeArr get_prime_arr(int lower, int upper) {
    PrimeArr out;
    out.arr_size = 0;
    out._arr = calloc(out.arr_size, sizeof(int));
    int k = 0;
    for (int i = lower; i < upper; i++) {
        // not a great impl but whatever
        int j;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                break;
            }
        }
        if (i % j != 0) {
            out.arr_size++;
            out._arr = realloc(out._arr, out.arr_size * (sizeof(int)));
            out._arr[k] = i;
            k++;
        }
    }
    return out;
}