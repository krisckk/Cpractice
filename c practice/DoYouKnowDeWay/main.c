#include <stdio.h>

void find_queen(int l, int r) {
    for (int x = l; x <= r; x++) {
        for (int y = x + 1; y <= r; y++) {
            if (x % y == 0 || y % x == 0) {
                printf("%d %d\n", x, y);
                return;
            }
        }
    }
}

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    find_queen(l, r);
    return 0;
}