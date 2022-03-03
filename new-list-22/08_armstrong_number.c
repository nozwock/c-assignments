#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_armstrong(int num);

int main(void)
{
    int num;
    printf("enter a number to check if it's armstrong: ");
    scanf("%d", &num);

    printf("\nnum=%d\n", num);

    if (is_armstrong(num)) {
        printf("%d is a armstrong number\n", num);
    } else {
        printf("%d is not a armstrong number\n", num);
    }
}

bool is_armstrong(int num)
{
    int tmp = num, rem, sum = 0;
    int ndigits = 0;

    while (tmp > 0) {
        tmp /= 10;
        ndigits++;
    }

    tmp = num;
    while (tmp > 0) {
        rem = tmp % 10;
        sum += pow(rem, ndigits);
        tmp /= 10;
    }

    if (num == sum) {
        return true;
    }

    return false;
}