#include <stdio.h>
#include <stdlib.h>

int get_sum_odd_digits(int);

int main(void) {
    int sum_odd_digits, n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    sum_odd_digits = get_sum_odd_digits(n);
    printf("Sum of odd digits of %d = %d\n", n, sum_odd_digits);
}

int get_sum_odd_digits(int n) {
    int sum = 0;
    n = abs(n); // for -ve arg
    while (n > 0) {
        if ((n % 10) % 2 != 0) {
            sum += n % 10;
        }
        n /= 10;
    }
    return sum;
}