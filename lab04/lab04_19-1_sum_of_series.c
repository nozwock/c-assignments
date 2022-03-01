#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// for series
// 1!+2!+-----n!

int main(void)
{
    int n;
    uint64_t sum = 1, factorial = 1;
    printf("1!+2!+-----n!\n");
    printf("Enter value of n: ");
    scanf("%d", &n);
    n = abs(n);

    for (int i = 2; i <= n; i++) {
        factorial *= i;
        sum += factorial;
    }

    printf("sum of series is: %lu\n", sum);
}