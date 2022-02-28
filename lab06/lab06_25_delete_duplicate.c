#include <stdio.h>

int main(void)
{
    int size = 10;
    int arr[size], duplicates[size], dup_count = 0;
    // eg.
    // 1 1 2 4 3 5 6 5 7 1
    printf("enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                duplicates[dup_count] = arr[i];
                dup_count++;

                // shifting the elements
                for (int k = j; k < size; k++) {
                    arr[k] = arr[k + 1];
                }

                j--;
                size--;
            }
        }
    }

    printf("after removing duplicates:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}