#include <stdio.h>

int swap_int(int *a, int *b);

int main(void)
{
    int a = 2, b = 4;
    printf("before swap: %d %d\n", a, b);
    swap_int(&a, &b);
    printf("after swap: %d %d\n", a, b);
}

int swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
