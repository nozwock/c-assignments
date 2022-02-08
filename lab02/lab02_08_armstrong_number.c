#include <stdbool.h>
#include <stdio.h>

bool is_armstrong(int n);

int main(void) {
    int n;
    printf("Enter a number to check if it's armstrong: ");
    scanf("%d", &n);

    printf("%d\n", is_armstrong(n));
}

bool is_armstrong(int n) {
    bool check = false;
    int i = n, r, sum = 0;

    while (i > 0) {
        r = i % 10;
        sum += (r * r * r);
        i /= 10;
    }

    if (n == sum) {
        check = true;
    }

    return check;
}
