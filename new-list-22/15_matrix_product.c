#include <stdio.h>

int main(void)
{
    int order;
    printf("enter order of matrix: ");
    scanf("%d", &order);

    int matrix1[order][order];
    printf("enter elements of matrix1:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    int matrix2[order][order];
    printf("enter elements of matrix2:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    int product[order][order];
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            product[i][j] = 0;

            for (int k = 0; k < order; k++) {
                product[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("product of matrix is:\n");
    for (int i = 0; i < order; i++) {
        for (int j = 0; j < order; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
}