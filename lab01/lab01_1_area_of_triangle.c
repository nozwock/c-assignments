#include <math.h>
#include <stdio.h>
// use -lm flag for linking math.h

double get_triangle_area(double a, double b, double c);

int main(void) {
    double a, b, c;
    printf("Enter values for sides of triangle: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    printf("area of triangle = %.3lf\n", get_triangle_area(a, b, c));
}

double get_triangle_area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrtf(s * (s - a) * (s - b) * (s - c));
}
