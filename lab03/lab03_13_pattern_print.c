#include <stdio.h>

int main(void)
{
    // 3 2 1
    // 2 1
    // 1
    for (int i = 3; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\b\n");
    }

    //   *
    //  * *
    // * * *
    // for reference:
    // http://www.cplusplus.com/reference/cstdio/printf/
    int size = 3;
    for (int i = 1; i <= size; i++) {
        printf("%*s", size - i, "");
        for (int j = i; j >= 1; j--) {
            printf("* ");
        }
        printf("\b\n");
    }
}