#include <stdio.h>

// for series
// 1!+2!+3!+--------------n!

int main(void)
{
    int n;
    unsigned long long sum = 1, factorial = 1;
    printf("1!+2!+3!+--------------n!\n");
    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += factorial;
    }

    printf("sum of series is: %lld\n", sum);
}