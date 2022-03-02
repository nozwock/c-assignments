#include <stdio.h>
#include "../lib/helpers.h"
// compile via
// gcc lab09_40_print_primes_from_file.c ../lib/helpers.c -lm

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Prints prime numbers from 1 to 100 to [FILE]\n");
        printf("Usage: %s [FILE]\n", argv[0]);
        return 1;
    }

    // confirmation prompt
    char prompt;
    printf("Are you sure? \033[0;1;91m%s will be overwritten if exists!\033[0m "
           "[y/n]: ",
           argv[1]);
    prompt = fgetc(stdin);
    if (prompt != 'y' && prompt != 'Y') {
        printf("\033[0;91mexited\033[0m\n");
        return 2;
    }

    FILE *to_file = fopen(argv[1], "w"); // read from
    if (to_file == NULL) {
        printf("Error: Could not open file\n");
        return 3;
    }

    for (int i = 0; i < 100 + 1; i++) {
        if (is_prime(i)) {
            fprintf(to_file, "%d\n", i);
        }
    }

    printf("\033[0;1;92mSuccessfully wrote prime nums from 1 to 100 to "
           "%s\033[0m\n",
           argv[1]);

    fclose(to_file);
}