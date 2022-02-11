#include <stdio.h>

int get_digits_sum_recurv(int);

int main(void) {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int digits_sum = get_digits_sum_recurv(n);
    printf("Sum of digits of %d recursively = %d\n", n, digits_sum);
}

int get_digits_sum_recurv(int n) {
    int i = n;
    if (n == 0) {
        return 0;
    }
    n /= 10;
    return (i % 10) + get_digits_sum_recurv(n);
}