#include "sort.h"

void swap(int *first, int *second) {
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
            swap(arr + i, arr + min_index);
        }
    }
}