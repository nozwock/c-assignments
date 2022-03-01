#include <stdio.h>

int main(void)
{
    int matrix_sz;
    printf("enter size of matrix: ");
    scanf("%d", &matrix_sz);

    int matrix[matrix_sz][matrix_sz];
    printf("enter elements of matrix:\n");
    for (int i = 0; i < matrix_sz; i++) {
        for (int j = 0; j < matrix_sz; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int matrix_square[matrix_sz][matrix_sz];

    for (int i = 0; i < matrix_sz; i++) {
        for (int j = 0; j < matrix_sz; j++) {
            matrix_square[i][j] = 0;

            for (int k = 0; k < matrix_sz; k++) {
                matrix_square[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    printf("square of matrix is:\n");
    for (int i = 0; i < matrix_sz; i++) {
        for (int j = 0; j < matrix_sz; j++) {
            printf("%d ", matrix_square[i][j]);
        }
        printf("\n");
    }
}