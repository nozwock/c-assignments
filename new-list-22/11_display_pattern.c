#include <stdio.h>

int main(void)
{
    int rows;
    printf("enter num of rows: ");
    scanf("%d%*c", &rows);

    printf("\n");

    // 5 4 3 2 1
    // 4 3 2 1
    // 3 2 1
    // 2 1
    // 1
    for (int i = rows; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\b\n");
    }

    printf("\n");

    //     *
    //    * *
    //   * * *
    //  * * * *
    // * * * * *
    // for reference:
    // http://www.cplusplus.com/reference/cstdio/printf/
    for (int i = 1; i <= rows; i++) {
        for (int k = 0; k < rows - i; k++) {
            printf(" ");
        }
        // printf("%*s", rows - i, ""); // or just use loops
        for (int j = i; j >= 2 - i; j--) {
            printf("*");
        }
        printf("\b\n");
    }

    printf("\n");

    // AAAAA
    // A   A
    // A   A
    // A   A
    // AAAAA
    for (int i = 1; i <= rows; i++) {
        if (i == 1 || i == rows) {
            for (int j = 0; j < rows; j++) {
                printf("A");
            }
            printf("\n");
            continue;
        }
        printf("A");
        printf("%*s", rows - 2, ""); // or just use loops
        printf("A\n");
    }
}