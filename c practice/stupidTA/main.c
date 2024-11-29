#include <stdio.h>
#include <stdlib.h>

void findUniqueNumbers(int *arr, int n, int *num1, int *num2) {
    int xorAll = 0;
    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    // Find a set bit in xorAll (there must be at least one)
    int setBitNo = xorAll & ~(xorAll - 1);

    // Divide elements into two groups and XOR separately
    *num1 = 0, *num2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & setBitNo) {
            *num1 ^= arr[i];
        } else {
            *num2 ^= arr[i];
        }
    }

    // Ensure num1 is smaller than num2
    if (*num1 > *num2) {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int num1, num2;
        findUniqueNumbers(arr, n, &num1, &num2);
        printf("%d %d\n", num1, num2);

        free(arr);
    }
    return 0;
}