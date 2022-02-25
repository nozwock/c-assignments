#include <stdio.h>

int gcd_euclidean(int, int);
int get_gcd(int[], size_t);

int main(void)
{
    int size;
    printf("Enter array length: ");
    scanf("%d", &size);

    int num_arr[size];
    printf("Enter number: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &num_arr[i]);
    }
    printf("GCD = %d\n", get_gcd(num_arr, size));
}

int gcd_euclidean(int num1, int num2)
{
    if (num2 == 0) {
        return num1;
    } else if (num1 == 0) {
        return num2;
    }
    return gcd_euclidean(num2, num1 % num2);
}

int get_gcd(int arr[], size_t size)
{
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