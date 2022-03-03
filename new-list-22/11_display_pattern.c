#include <stdio.h>

int main(void)
{
    // 3 2 1
    // 2 1
    // 1
    int pattern1_sz = 5;
    for (int i = pattern1_sz; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\b\n");
    }

    printf("\n");

    //   *
    //  * *
    // * * *
    // for reference:
    // http://www.cplusplus.com/reference/cstdio/printf/
    int pattern2_sz = 5;
    for (int i = 1; i <= pattern2_sz; i++) {
        printf("%*s", pattern2_sz - i, ""); // or just use loops
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
    int pattern3_sz = 5;
    for (int i = 1; i <= pattern3_sz; i++) {
        if (i == 1 || i == pattern3_sz) {
            for (int j = 0; j < pattern3_sz; j++) {
                printf("A");
            }
            printf("\n");
            continue;
        }
        printf("A");
        printf("%*s", pattern2_sz - 2, ""); // or just use loops
        printf("A");
        printf("\n");
    }
}