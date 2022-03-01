#include <stdio.h>

int main(void)
{
    int matrix1_sz, diag_sum1 = 0;
    int matrix2_sz, diag_sum2 = 0;
    printf("enter size of 2 arrays: ");
    scanf("%d%d", &matrix1_sz, &matrix2_sz);

    int matrix1[matrix1_sz][matrix1_sz], matrix2[matrix2_sz][matrix2_sz];

    printf("enter elements of 1st matrix:\n");
    for (int i = 0; i < matrix1_sz; i++) {
        for (int j = 0; j < matrix1_sz; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("enter elements of 2nd matrix:\n");
    for (int i = 0; i < matrix2_sz; i++) {
        for (int j = 0; j < matrix2_sz; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < matrix1_sz; i++) {
        diag_sum1 += matrix1[i][i];
    }

    for (int i = 0; i < matrix2_sz; i++) {
        diag_sum2 += matrix2[i][i];
    }

    printf("Sum of sum of diagonal elements of these 2 matrices = %d\n",
           diag_sum1 + diag_sum2);
}