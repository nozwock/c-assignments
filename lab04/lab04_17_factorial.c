#include <stdio.h>

long long get_factorial(int);

int main(void) {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    long long factorial = get_factorial(n);
    printf("Factorial of %d = %lld\n", n, factorial);
}

long long get_factorial(int n) {
    // for +ve only
    long long out = 1;
    if (n < 0) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        out *= i;
    }
    return out;
}