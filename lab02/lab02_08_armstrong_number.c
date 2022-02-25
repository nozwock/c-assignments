#include <stdbool.h>
#include <stdio.h>

bool is_armstrong(int);

int main(void)
{
    int num;
    printf("Enter a number to check if it's armstrong: ");
    scanf("%d", &num);

    printf("%d\n", is_armstrong(num));
}

bool is_armstrong(int num)
{
    int tmp = num, rem, sum = 0;

    while (tmp > 0) {
        rem = tmp % 10;
        sum += (rem * rem * rem);
        tmp /= 10;
    }

    if (num == sum) {
        return true;
    }

    return false;
}
