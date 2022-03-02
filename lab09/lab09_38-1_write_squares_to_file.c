#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Write squares of int in 1st file to the 2nd file\n");
        printf("Usage: %s [FILE] [FILE]\n", argv[0]);
        return 1;
    }

    // confirmation prompt
    char prompt;
    printf("Are you sure? \033[0;1;91m%s will be overwritten if exists!\033[0m "
           "[y/n]: ",
           argv[2]);
    prompt = fgetc(stdin);
    if (prompt != 'y' && prompt != 'Y') {
        printf("\033[0;91mexited\033[0m\n");
        return 2;
    }

    FILE *from_file = fopen(argv[1], "r"); // read from
    FILE *to_file = fopen(argv[2], "w");   // write to
    if (from_file == NULL || to_file == NULL) {
        printf("Error: Could not open file\n");
        return 3;
    }

    int num;
    // for this impl, file should only have ints and not mixed with other
    // characters
    while (fscanf(from_file, "%d", &num) != 0) {
        fprintf(to_file, "%d\n", num * num); // writing square of nums to file
    }

    printf(
        "\033[0;1;92mSuccessfully wrote squares of nums in %s to %s\033[0m\n",
        argv[1], argv[2]);

    fclose(from_file);
    fclose(to_file);
}