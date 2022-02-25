#include <stdbool.h>
#include <stdlib.h>

#pragma once

void swap(int *first, int *second);

// destructive
void selection_sort(int *arr, int size);
void bubble_sort(int *arr, int size);
void merge_sort(int *arr, int size, int start, int end);
void __merge(int *arr, int size, int start, int end);