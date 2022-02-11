#include <stdio.h>
#include "../helpers.h"

// for series
// 1!+2!+-----n!

int main(void) {
    int n;
    unsigned long long sum = 1;
    printf("1!+2!+-----n!\n");
    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 2; i <= n; i++) {
        sum += get_factorial(i);
    }

    printf("sum of series is: %lld\n", sum);
}