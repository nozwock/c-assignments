#include <stdio.h>
#include <stdlib.h>

typedef struct ArrWithSize {
    int *_arr;
    size_t arr_size;
} ArrWithSize;

ArrWithSize get_fibonacci_arr(int n);

int main(void) {
    int n;
    printf("Enter upper limit(nth element): ");
    scanf("%d", &n);

    ArrWithSize fib = get_fibonacci_arr(n);
    for (int i = 0; i < fib.arr_size; i++) {
        printf("%d, ", fib._arr[i]);
    }
    printf("\n");
    free(fib._arr);
}

ArrWithSize get_fibonacci_arr(int n) {
    ArrWithSize fib;
    fib.arr_size = n;
    fib._arr = calloc(fib.arr_size, sizeof(int));

    fib._arr[0] = 0;
    fib._arr[1] = 1;

    for (int i = 2; i < fib.arr_size; i++) {
        fib._arr[i] = fib._arr[i - 1] + fib._arr[i - 2];
    }

    return fib;
}
