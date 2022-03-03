#include <stdint.h>
#include <stdio.h>

int64_t get_factorial(int);

int main(void)
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);

    printf("\nnum = %d\n", num);

    int64_t factorial = get_factorial(num);
    printf("Factorial of %d = %lu\n", num, factorial);
}

int64_t get_factorial(int num)
// for +ve only
{
    int64_t out = 1;
    if (num < 0) {
        return 0;
    }
    for (int i = 1; i <= num; i++) {
        out *= i;
    }
    return out;
}