#include <stdio.h>
#include <stdlib.h>

int get_sum_odd_digits(int);

int main(void)
{
    int sum_odd_digits, num;
    printf("Enter a number: ");
    scanf("%d", &num);
    sum_odd_digits = get_sum_odd_digits(num);
    printf("Sum of odd digits of %d = %d\n", num, sum_odd_digits);
}

int get_sum_odd_digits(int num)
{
    int sum = 0;
    num = abs(num); // for -ve arg
    while (num > 0) {
        if ((num % 10) % 2 != 0) {
            sum += num % 10;
        }
        num /= 10;
    }
    return sum;
}