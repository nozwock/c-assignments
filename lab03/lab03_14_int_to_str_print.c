#include <stdio.h>
#include <string.h>

// some reference here:
// https://en.cppreference.com/w/c/io/fprintf
// http://www.cplusplus.com/reference/cstdio/snprintf/

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int length = snprintf(NULL, 0, "%d", num);
    // to get length of string required using NULL buffer
    // we could also find length using log10 but whatever
    // it won't take account for -ve
    char num_str[length + 1];
    sprintf(num_str, "%d", num);
    for (int i = 0; i < length; i++) {
        printf("%c\n", num_str[i]);
    }
    printf("\b");
}