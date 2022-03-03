#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Write a program to find the largest no among 20 integers array using dynamic
// memory allocation.
// Huhh? whaat?

int main(void)
{
    // set seed with current time
    srand(time(0));

    int dynamic_arr_sz = 20;
    // is dis what u want?? -_-
    int *dynamic_arr = calloc(dynamic_arr_sz, sizeof(*dynamic_arr));

    // populating the array with random numbers and printing them
    for (int i = 0; i < dynamic_arr_sz; i++) {
        dynamic_arr[i] = rand() / pow(10, 6);
        printf("%d ", dynamic_arr[i]);
    }
    printf("\n");

    int max_num = dynamic_arr[0];
    for (int i = 1; i < dynamic_arr_sz; i++) {
        if (dynamic_arr[i] > max_num) {
            max_num = dynamic_arr[i];
        }
    }

    printf("Max numbers in this array = %d\n", max_num);

    free(dynamic_arr);
}