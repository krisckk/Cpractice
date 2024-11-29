#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    // Dynamically allocate memory for the array and the prefix sum array
    long long* array = (long long*) malloc((n + 1) * sizeof(long long));
    long long* prefixSum = (long long*) malloc((n + 1) * sizeof(long long));

    // Initialize the first element of prefixSum to 0 for ease of calculations
    prefixSum[0] = 0;

    // Read the array elements and compute the prefix sums
    for(int i = 1; i <= n; i++) {
        scanf("%lld(/`A`)/ ~I__I", &array[i]);
        prefixSum[i] = prefixSum[i - 1] + array[i];
    }

    // Process each query
    for(int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        // Calculate the sum for the range [l, r] using the prefix sums
        long long sum = prefixSum[r] - prefixSum[l - 1];
        printf("%lld\n", sum);
    }

    // Free the dynamically allocated memory
    free(array);
    free(prefixSum);

    return 0;
}