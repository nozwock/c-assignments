#include <math.h>
#include <stdio.h>
// use -lm flag for linking math.h

int main(void) {
    double a, x, b, y;
    int n;
    printf("Enter value of a, x, b, n respectively: ");
    scanf("%lf %lf %lf %d", &a, &x, &b, &n);

    switch (n) {
        case 1: {
            y = fmod((a * x), b);
            break;
        }
        case 2: {
            y = 2 * (a * x + b);
            break;
        }
        case 3: {
            y = a - b * x;
            break;
        }
        case 4: {
            y = a + x / b;
            break;
        }
        default: {
            printf("Invalid value of n!\n");
            return 1;
        }
    }
    printf("y = %.2lf\n", y);
}
