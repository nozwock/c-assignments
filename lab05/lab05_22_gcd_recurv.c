#include <stdio.h>

int gcd_euclidean(int, int);
int get_gcd(int[], size_t);

int main(void) {
    int size;
    printf("Enter array length: ");
    scanf("%d", &size);

    int n_arr[size];
    printf("Enter number: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &n_arr[i]);
    }
    printf("GCD = %d\n", get_gcd(n_arr, size));
}

int gcd_euclidean(int a, int b) {
    if (b == 0) {
        return a;
    } else if (a == 0) {
        return b;
    }
    return gcd_euclidean(b, a % b);
}

int get_gcd(int arr[], size_t size) {
    if (size == 0) {
        return 0;
    } else if (size == 1) {
        return arr[0];
    }
    int gcd = gcd_euclidean(arr[0], arr[1]);
    for (int i = 2; i < size; i++) {
        gcd = gcd_euclidean(gcd, arr[i]);
    }
    return gcd;
}