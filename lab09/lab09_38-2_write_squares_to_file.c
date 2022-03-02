#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 1000000

// Writing to a buffer...
// https://stackoverflow.com/questions/2029103/correct-way-to-read-a-text-file-into-a-buffer-in-c
// Reading ints from a buffer...
// https://stackoverflow.com/questions/22982917/ignoring-everything-other-than-integers-scanf

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

    char buf[MAX_BUF_SIZE + 1];
    size_t file_content_sz = fread(buf, sizeof(*buf), MAX_BUF_SIZE, from_file);
    buf[file_content_sz++] = '\0';

    // reading ints from the buffer
    char *buf_ptr = buf;
    do {
        if (!isdigit(*buf_ptr)) // check if current character is a digit
            continue;           // if not...
        long num = strtol(buf_ptr, &buf_ptr, 10); // read a number
        fprintf(to_file, "%ld\n", num * num); // writing square of ints to file
    } while (*buf_ptr++);                     // ...move to next character

    printf(
        "\033[0;1;92mSuccessfully wrote squares of nums in %s to %s\033[0m\n",
        argv[1], argv[2]);

    fclose(from_file);
    fclose(to_file);
}