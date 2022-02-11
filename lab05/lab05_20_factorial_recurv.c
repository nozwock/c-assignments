#include <stdio.h>
#include "../helpers.h"

int main(void) {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    unsigned long long factorial = get_factorial_recurv(n);
    printf("Factorial of %d = %lld\n", n, factorial);
}