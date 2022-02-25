#include <stdio.h>
#include "../lib/helpers.h"

int main(void)
{
    int num;
    printf("Enter value of n: ");
    scanf("%d", &num);
    unsigned long long factorial = get_factorial_recurv(num);
    printf("Factorial of %d = %lld\n", num, factorial);
}