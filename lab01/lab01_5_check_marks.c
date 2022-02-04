#include <stdio.h>

int main() {
  float phy_marks, che_marks, mat_marks;
  printf("Enter marks for physics, chemistry, maths: ");
  scanf("%f %f %f", &phy_marks, &che_marks, &mat_marks);

  if (phy_marks >= 40 && che_marks >= 50 && mat_marks >= 60 &&
      (phy_marks + mat_marks >= 150 ||
       phy_marks + che_marks + mat_marks >= 200)) {
    printf("eligible for course\n");
  } else {
    printf("not eligible for course\n");
  }

  return 0;
}