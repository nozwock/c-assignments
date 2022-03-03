#include <stdint.h>
#include <stdio.h>

int64_t get_fibonacci_sum(int);

int main(void)
{
    int n;
    printf("enter upper limit (nth element): ");
    scanf("%d", &n);

    printf("\nn = %d\n", n);

    printf("sum of fibonacci series until %dth element = %ld\n", n,
           get_fibonacci_sum(n));
}

int64_t get_fibonacci_sum(int n)
{
    int64_t sum = 0;
    int64_t fib[n];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // calculating sum of series stored in an array
    for (int i = 0; i < n; i++) {
        sum += fib[i];
    }

    return sum;
}