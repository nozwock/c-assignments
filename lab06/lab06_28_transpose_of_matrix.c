#include <stdbool.h>
#include <stdio.h>

bool is_matrix_same(int matrix1_sz, int matrix1[matrix1_sz][matrix1_sz],
                    int matrix2_sz, int matrix2[matrix2_sz][matrix2_sz]);

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

    int transpose[matrix_sz][matrix_sz];
    for (int i = 0; i < matrix_sz; i++) {
        for (int j = 0; j < matrix_sz; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("transpose is:\n");
    for (int i = 0; i < matrix_sz; i++) {
        for (int j = 0; j < matrix_sz; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    printf("is it symmetric: %d\n",
           is_matrix_same(matrix_sz, matrix, matrix_sz, transpose));
}

bool is_matrix_same(int matrix1_sz, int matrix1[matrix1_sz][matrix1_sz],
                    int matrix2_sz, int matrix2[matrix2_sz][matrix2_sz])
{
    if (matrix1_sz != matrix2_sz) {
        return false;
    }

    for (int i = 0; i < matrix1_sz; i++) {
        for (int j = 0; j < matrix1_sz; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }

    return true;
}