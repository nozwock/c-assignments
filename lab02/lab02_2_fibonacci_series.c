#include <stdio.h>

int main(void) {
    int n;
    printf("Enter upper limit(nth element): ");
    scanf("%lld", &n);

    unsigned long long fib[n];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < n; i++) {
        printf("%lld, ", fib[i]);
    }
    printf("\n");
}
