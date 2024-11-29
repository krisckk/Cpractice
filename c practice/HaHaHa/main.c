#include <stdio.h>

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int sugar[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &sugar[i]);
        }

        int max_gcd = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int current_gcd = gcd(sugar[i], sugar[j]);
                if (current_gcd > max_gcd) {
                    max_gcd = current_gcd;
                }
            }
        }

        printf("%d\n", max_gcd);
    }

    return 0;
}
