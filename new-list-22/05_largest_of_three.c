#include <stdio.h>

int main(void)
{
    // with nested if else
    double a, b, c;
    printf("Enter 3 numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("\n%.2f %.2f %.2f\n", a, b, c);

    if (a >= b) {
        if (a >= c) {
            printf("largest is %.2lf\n", a);
        } else {
            printf("largest is %.2lf\n", c);
        }
    } else if (b >= a) {
        if (b >= c) {
            printf("largest is %.2lf\n", b);
        } else {
            printf("largest is %.2lf\n", c);
        }
    }
}
