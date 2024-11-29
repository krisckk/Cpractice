#include <stdio.h>
#include <stdlib.h>

long long countOnesInRange(long long x) {
    if (x <= 0) {
        return 0;
    }
    if (x < 10) {
        return 1;
    }
    long long count = 0, factor = 1, n = x;
    while (n >= 10) {
        n /= 10;
        factor *= 10;
    }
    // Count ones in the highest place
    if (n == 1) {
        count += (x % factor) + 1;
    } else {
        count += factor;
    }
    // Count ones in the rest of the places
    count += n * countOnesInRange(factor - 1);
    // Count ones in the remaining number
    count += countOnesInRange(x % factor);
    return count;
}

long long countones(long long a, long long b) {
    return countOnesInRange(b) - countOnesInRange(a - 1);
}

int main() {
    long long testcase;
    scanf("%lld", &testcase);
    long long *answerarray = (long long*)malloc(sizeof(long long) * testcase);
    for (long long i = 0; i < testcase; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        answerarray[i] = countones(a, b);
    }
    for (long long i = 0; i < testcase; i++) {
        printf("%lld\n", answerarray[i]);
    }
    free(answerarray);
    return 0;
}