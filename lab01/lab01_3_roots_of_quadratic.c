#include <math.h>
#include <stdio.h>
// use -lm flag for linking math.h

int main() {
    double a, b, c, discriminant, root1, root2, real_part, imag_part;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // real and different roots
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.3lf\nroot2 = %.3lf\n", root1, root2);
    }

    // real and equal roots
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.3lf\n", root1);
    }

    // imaginary roots
    else {
        real_part = -b / (2 * a);
        imag_part = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.4lf+%.4lfi\nroot2 = %.4lf-%.4lfi\n", real_part,
               imag_part, real_part, imag_part);
    }

    return 0;
}
