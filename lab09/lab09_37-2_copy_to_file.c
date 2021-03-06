#include <stdio.h>
#include <stdlib.h>

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

    int c, file_content_sz = 0;
    char *file_content = malloc(
        file_content_sz + 1 * sizeof(*file_content)); // extra space for '\0'
    while ((c = fgetc(from_file)) != EOF) {
        file_content = realloc(file_content,
                               ++file_content_sz + 1 * sizeof(*file_content));
        file_content[file_content_sz - 1] = c;
    }
    file_content[file_content_sz] = '\0';

    if (fprintf(to_file, "%s", file_content)) {
        printf("\033[0;1;92mSuccessfully copied contents of %s to %s\033[0m\n",
               argv[1], argv[2]);
    } else {
        printf("Error: Failed to copy contents\n");
    }

    free(file_content);
    fclose(from_file);
    fclose(to_file);
}
