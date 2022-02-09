#include <stdio.h>
#include <stdlib.h>

unsigned long long *get_fibonacci_arr(int n);

int main(void) {
    int n;
    printf("Enter upper limit(nth element): ");
    scanf("%d", &n);

    unsigned long long *fib = get_fibonacci_arr(n);
    for (int i = 0; i < n; i++) {
        printf("%lld, ", fib[i]);
    }
    printf("\n");
    free(fib);
}

unsigned long long *get_fibonacci_arr(int n) {
    unsigned long long *fib = malloc(n * sizeof(unsigned long long));

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib;
}
