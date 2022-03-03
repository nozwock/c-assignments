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
}