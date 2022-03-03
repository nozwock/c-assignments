#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

long get_digits_sum_recv(long num);

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Prints sum of digits of a number\n");
        printf("Usage: %s [INT]\n", argv[0]);
        return 1;
    }

    printf("%ld\n", get_digits_sum_recv(atol(argv[1])));
}

long get_digits_sum_recv(long num)
{
    if (num == 0) {
        return 0;
    }
    return (num % 10) + get_digits_sum_recv(num / 10);
}