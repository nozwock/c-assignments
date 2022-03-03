#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/28524522/mallocing-a-2d-array-in-c

int **_alloc_int_arr(int nrows, int ncols);
int free_int_arr(int **ptr_arr, int nrows);

int main(void)
{
    int matrix_rows, matrix_cols;
    printf("enter size of matrix [row] [columns]: ");
    scanf("%d%d", &matrix_rows, &matrix_cols);

    int **matrix = _alloc_int_arr(matrix_rows, matrix_cols);

    printf("enter elements of matrix:\n");
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_cols; j++) {
            if (scanf("%d", &matrix[i][j]) == 0) {
                free(matrix);
                return 3;
            }
        }
    }

    int **transpose = _alloc_int_arr(matrix_cols, matrix_rows);

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

    free_int_arr(matrix, matrix_rows);
    free_int_arr(transpose, matrix_cols);
}

int **_alloc_int_arr(int nrows, int ncols)
// allocate memory for 2D array and returns pointer if successful or NULL if
// failed
{
    // allocate memory for nrows
    int **ptr_arr = malloc(nrows * sizeof(int *));
    if (ptr_arr == NULL) {
        return NULL;
    }
    // allocate memory for each row
    for (int r = 0; r < nrows; r++) {
        ptr_arr[r] = malloc(ncols * sizeof(int));
        if (ptr_arr[r] == NULL) {
            // clean memory that was allocated before error
            while (--r >= 0) {
                free(ptr_arr[r]);
            }
            free(ptr_arr);
            return NULL;
        }
    }
    return ptr_arr;
}

int free_int_arr(int **ptr_arr, int nrows)
// frees memory allocated for 2D array and returns 1 if successful or 0 if
// failed
{
    if (ptr_arr == NULL || nrows < 1) {
        return 0;
    }
    // free memory allocated for each row
    for (int r = 0; r < nrows; r++) {
        if (ptr_arr[r] != NULL) {
            free(ptr_arr[r]);
        }
    }
    // free memory allocated for rows pointers
    free(ptr_arr);
    return 1;
}