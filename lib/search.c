#include "search.h"

int linear_search(int *arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int size, int val) {
    int lower = 0, upper = size - 1;
    int mid;
    while (lower <= upper) {
        mid = (upper + lower) / 2;

        if (arr[mid] == val) {
            return mid;
        } else if (arr[mid] > val) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }

    return -1; // search failed
}