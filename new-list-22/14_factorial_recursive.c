#include <stdint.h>
#include <stdio.h>

uint64_t get_factorial_recv(int num);

int main(void)
{
    int num;
    printf("enter a number: ");
    scanf("%d", &num);

    printf("\nnum = %d\n", num);

    int64_t factorial = get_factorial_recv(num);
    printf("Factorial of %d = %lu\n", num, factorial);
}

uint64_t get_factorial_recv(int num)
{
    // for +ve only
    if (num < 0) {
        return 0; // err
    }
    if (num == 0) {
        return 1;
    }
    return num * get_factorial_recv(num - 1);
}