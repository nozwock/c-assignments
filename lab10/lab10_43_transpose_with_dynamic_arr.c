#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int matrix_rows, matrix_cols;
    printf("enter size of matrix [row] [columns]: ");
    scanf("%d%d", &matrix_rows, &matrix_cols);

    // allocate memory for 2d array
    int **matrix = malloc(matrix_rows * sizeof(int *));
    if (matrix == NULL) {
        return 1;
    }
    // allocate memory for each row
    for (int i = 0; i < matrix_rows; i++) {
        matrix[i] = malloc(matrix_cols * sizeof(int));
        if (matrix[i] == NULL) {
            // clean memory that was allocated before error
            while (--i >= 0) {
                free(matrix[i]);
            }
            free(matrix);
            return 2;
        }
    }

    printf("enter elements of matrix:\n");
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_cols; j++) {
            if (scanf("%d", &matrix[i][j]) == 0) {
                free(matrix);
                return 3;
            }
        }
    }

    // allocate memory for 2d array (transpose)
    int **transpose = malloc(matrix_cols * sizeof(int *));
    if (transpose == NULL) {
        return 1;
    }
    // allocate memory for each row
    for (int i = 0; i < matrix_cols; i++) {
        transpose[i] = malloc(matrix_rows * sizeof(int));
        if (transpose[i] == NULL) {
            // clean memory that was allocated before error
            while (--i >= 0) {
                free(transpose[i]);
            }
            free(transpose);
            return 2;
        }
    }

    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("transpose is:\n");
    for (int i = 0; i < matrix_cols; i++) {
        for (int j = 0; j < matrix_rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    free(matrix);
    free(transpose);
}