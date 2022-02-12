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
    if (n == 0) {
        return 0;
    }
    return (n % 10) + get_digits_sum_recurv(n / 10);
}