#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void swap_int(int *first, int *second);
void bubble_sort(int *arr, int size);

int main(void)
{
    int nnum;
    printf("how many nums to sort: ");
    scanf("%d", &nnum);

    int arr[nnum];
    printf("enter %d nums\n", nnum);
    for (int i = 0; i < nnum; i++) {
        printf("> ");
        scanf("%d", &arr[i]);
    }

    printf("\nunsorted nums:\n");
    for (int i = 0; i < nnum; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, nnum);
    printf("sorted nums:\n");
    for (int i = 0; i < nnum; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap_int(int *first, int *second)
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}