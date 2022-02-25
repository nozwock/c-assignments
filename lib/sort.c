#include "sort.h"
#include <stdbool.h>
#include <stdlib.h>

void swap_int(int *first, int *second)
{
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void selection_sort(int *arr, int size)
{
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

void bubble_sort(int *arr, int size)
{
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

void merge_sort(int *arr, int size, int start, int end)
{
    // i.e. there's only 2 elements left to sort
    if (end - start == 1) {
        if (arr[start] > arr[end]) {
            swap_int(arr + start, arr + end);
        }
    } else if (start != end) {
        // sort left half of the array
        merge_sort(arr, size, start, (start + end) / 2);
        // sort right half of the array
        merge_sort(arr, size, (start + end) / 2 + 1, end);
        __merge(arr, size, start, end);
    }

    // if start == end or i.e. there's only 1 element left then exit
    return;
}

void __merge(int *arr, int size, int start, int end)
{
    // stupid C doesn't have convinient array slices so we have to keep track
    // via indices
    int *buf = (int *)malloc(size * sizeof(int));
    int buf_index = start;
    int i, j;
    i = start;                 // starting index of left half subarray
    j = (start + end) / 2 + 1; // starting index of right half subarray

    while (i < ((start + end) / 2 + 1) && j < (end + 1)) {
        // ((start + end) / 2 + 1) is the length of the left half subarray
        // (end + 1) is the length of the right half subarray

        if (arr[i] <= arr[j]) {
            buf[buf_index] = arr[i];
            buf_index++;
            i++;
        } else {
            buf[buf_index] = arr[j];
            buf_index++;
            j++;
        }
    }

    // adding any remaining elements(from any one of the subarray) if any;
    // to the buffer array
    if (j == (end + 1)) {
        while (i < ((start + end) / 2 + 1)) {
            buf[buf_index] = arr[i];
            buf_index++;
            i++;
        }
    } else {
        while (j < (end + 1)) {
            buf[buf_index] = arr[j];
            buf_index++;
            j++;
        }
    }

    for (buf_index = start; buf_index < end + 1; buf_index++) {
        arr[buf_index] = buf[buf_index];
    }

    free(buf);
}