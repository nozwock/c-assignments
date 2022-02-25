#include <math.h>
#include <stdio.h>
// use -lm flag for linking math.h

// for series
// (1)-(x^1/1!)+(x^2/2!)-............(x^n/n)!

int main(void)
{
    int x, n;
    unsigned long long sum = 1, factorial = 1;
    // note: initialized sum with 1 here
    printf("(1)-(x^1/1!)+(x^2/2!)-............(x^n/n)!\n");
    printf("Enter value of x, n: ");
    scanf("%d %d", &x, &n);

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += pow(-x, i) / factorial;
    }

    printf("sum of series is: %lld\n", sum);
}