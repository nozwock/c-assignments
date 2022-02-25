#include <stdio.h>

long long get_factorial(int);

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    long long factorial = get_factorial(num);
    printf("Factorial of %d = %lld\n", num, factorial);
}

long long get_factorial(int num)
{
    // for +ve only
    long long out = 1;
    if (num < 0) {
        return 0;
    }
    for (int i = 1; i <= num; i++) {
        out *= i;
    }
    return out;
}