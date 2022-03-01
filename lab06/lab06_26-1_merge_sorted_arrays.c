#include <stdio.h>

int main(void)
{
    int arr1_sz;
    int arr2_sz;

    printf("size: ");
    scanf("%d", &arr1_sz);
    printf("elems:\n");

    int arr1[arr1_sz];
    for (int i = 0; i < arr1_sz; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("size: ");
    scanf("%d", &arr2_sz);
    printf("elems:\n");
    int arr2[arr2_sz];
    for (int i = 0; i < arr2_sz; i++) {
        scanf("%d", &arr2[i]);
    }

    int max_sz = arr1_sz + arr2_sz;
    int visited[max_sz], visited_sz = 0;
    int merged_arr[max_sz], merged_sz = 0;

    // merging
    int i = 0, j = 0;
    while (i < (arr1_sz) && j < (arr2_sz)) {
        if (arr1[i] <= arr2[j]) {
            merged_arr[merged_sz++] = arr1[i++];
        } else {
            merged_arr[merged_sz++] = arr2[j++];
        }
    }

    if (j == arr2_sz) {
        while (i < arr1_sz) {
            merged_arr[merged_sz++] = arr1[i++];
        }
    } else {
        while (j < arr2_sz) {
            merged_arr[merged_sz++] = arr2[j++];
        }
    }

    // removing duplicates
    for (int i = 0; i < merged_sz; i++) {
        for (int j = i + 1; j < merged_sz; j++) {
            if (merged_arr[i] == merged_arr[j]) {

                // shifting the elements
                for (int k = j; k < merged_sz - 1; k++) {
                    merged_arr[k] = merged_arr[k + 1];
                }

                j--;
                merged_sz--;
            }
        }
    }

    printf("arr1:\n");
    for (i = 0; i < arr1_sz; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("arr2:\n");
    for (i = 0; i < arr2_sz; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("merged:\n");
    for (i = 0; i < merged_sz; i++) {
        printf("%d ", merged_arr[i]);
    }
    printf("\n");
}