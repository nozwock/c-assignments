#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 1000000

// Writing to a buffer...
// https://stackoverflow.com/questions/2029103/correct-way-to-read-a-text-file-into-a-buffer-in-c
// Reading all ints from a buffer...
// https://stackoverflow.com/questions/22982917/ignoring-everything-other-than-integers-scanf

const char *odd_file_name = "ODD.txt";
const char *even_file_name = "EVEN.txt";

int main(int argc, char **argv)
{

    if (argc != 2) {
        printf("Write odd nums in [FILE] to %s and even nums to %s\n",
               odd_file_name, even_file_name);
        printf("Usage: %s [FILE]\n", argv[0]);
        return 1;
    }

    // confirmation prompt
    char prompt;
    printf("Are you sure? \033[0;1;91m%s and %s will be overwritten if "
           "exists!\033[0m [y/n]: ",
           odd_file_name, even_file_name);
    prompt = fgetc(stdin);
    if (prompt != 'y' && prompt != 'Y') {
        printf("\033[0;91mexited\033[0m\n");
        return 2;
    }

    FILE *from_file = fopen(argv[1], "r");        // read from
    FILE *odd_file = fopen(odd_file_name, "w");   // write to
    FILE *even_file = fopen(even_file_name, "w"); // write to
    if (from_file == NULL || odd_file == NULL || even_file_name == NULL) {
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

        if (num % 2 == 0) {
            fprintf(even_file, "%ld\n", num);
        } else {
            fprintf(odd_file, "%ld\n", num);
        }
    } while (*buf_ptr++); // ...move to next character

    printf(
        "\033[0;1;92mSuccessfully wrote nums in %s and %s accordingly\033[0m\n",
        odd_file_name, even_file_name);

    fclose(from_file);
    fclose(odd_file);
    fclose(even_file);
}