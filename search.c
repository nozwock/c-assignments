#include "search.h"

int binary_search(int *arr, int lower, int upper, int val) {
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