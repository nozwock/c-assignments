#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int dynamic_arr_sz = 20;
    int *dynamic_arr = calloc(dynamic_arr_sz, sizeof(*dynamic_arr));

    // populating the array with random numbers and printing them
    for (int i = 0; i < dynamic_arr_sz; i++) {
        dynamic_arr[i] = rand() / pow(10, 7);
        printf("%d ", dynamic_arr[i]);
    }
    printf("\n");

    int max_num = dynamic_arr[0];
    for (int i = 1; i < dynamic_arr_sz; i++) {
        if (dynamic_arr[i] > max_num) {
            max_num = dynamic_arr[i];
        }
    }

    printf("max number in this array = %d\n", max_num);

    free(dynamic_arr); // altho there's no need to free explicitly; since it'll
                       // be mem will be freed by the os anyway upon process
                       // termination
}