#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Copy contents of 1st file to 2nd file\n");
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
        printf("Error: Could not open file");
        return 3;
    }

    char c;
    int char_count;
    while ((c = fgetc(from_file)) != EOF) {
        char_count++;
        fputc(c, to_file); // write char by char
    }

    printf("\033[0;1;92mSuccessfully copied contents of %s to %s\033[0m\n",
           argv[1], argv[2]);
    printf("char count: %d\n", char_count);

    fclose(from_file);
    fclose(to_file);
}
