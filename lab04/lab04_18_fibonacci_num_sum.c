#include <stdint.h>
#include <stdio.h>
#include "../lib/helpers.h"

int64_t get_fibonacci_sum(int);

int main(void) {
    int n;
    printf("Enter upper limit(nth element): ");
    scanf("%d", &n);

    printf("Sum of fibonacci series until %dth element = %ld\n", n,
           get_fibonacci_sum(n));
}

int64_t get_fibonacci_sum(int n) {
    int64_t sum = 0;
    ArrWithSize_int64_t fib = get_fibonacci_arr(n);

    for (int i = 0; i < fib.size; i++) {
        sum += fib._arr[i];
    }
    free(fib._arr);

    return sum;
}