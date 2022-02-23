#include "sort.h"
#include <stdbool.h>
#include <stdio.h>

void swap_int(int *first, int *second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[min_index] > arr[j]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap_int(arr + i, arr + min_index);
        }
    }
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_int(arr + j, arr + j + 1);
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}