#include <stdint.h>
#include <stdio.h>

// for series
// 1!+2!+3!+--------------n!

int main(void)
{
    int n;
    uint64_t sum = 1, factorial = 1;
    printf("1!+2!+3!+....n!\n");
    printf("enter value of n: ");
    scanf("%d", &n);

    printf("\nn=%d\n", n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += factorial;
    }

    printf("sum of series is: %lu\n", sum);
}