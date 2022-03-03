#include <stdint.h>
#include <stdio.h>
#include "../lib/helpers.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Prints factorial of number\n");
        printf("Usage: %s [INT]\n", argv[0]);
        return 1;
    }

    uint64_t factorial;
    if ((factorial = get_factorial(atoi(argv[1]))) < UINT64_MAX / 10) {
        printf("%lu\n", factorial);
    } else {
        printf("MATH Error heHe\n");
    }
}