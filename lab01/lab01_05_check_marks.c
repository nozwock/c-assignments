#include <stdio.h>

int main(void) {
    float phy_marks, che_marks, math_marks;
    printf("Enter marks for physics, chemistry, maths: ");
    scanf("%f %f %f", &phy_marks, &che_marks, &math_marks);

    if (phy_marks >= 40 && che_marks >= 50 && math_marks >= 60 &&
        (phy_marks + math_marks >= 150 ||
         phy_marks + che_marks + math_marks >= 200)) {
        printf("eligible for course\n");
    } else {
        printf("not eligible for course\n");
    }
}
