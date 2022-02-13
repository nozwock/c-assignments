#include <stdio.h>

int get_digits_sum_recurv(int);

int main(void) {
    int num;
    printf("Enter a num: ");
    scanf("%d", &num);

    int digits_sum = get_digits_sum_recurv(num);
    printf("Sum of digits of %d recursively = %d\n", num, digits_sum);
}

int get_digits_sum_recurv(int num) {
    if (num == 0) {
        return 0;
    }
    return (num % 10) + get_digits_sum_recurv(num / 10);
}