#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 5000
#define MAX_Q 5000

typedef struct {
    int L, R;
} Soldier;

// Comparator for sorting soldiers by their start position
int compare(const void *a, const void *b) {
    Soldier *soldierA = (Soldier *)a;
    Soldier *soldierB = (Soldier *)b;
    if (soldierA->L != soldierB->L)
        return soldierA->L - soldierB->L;
    return soldierA->R - soldierB->R;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        
        Soldier soldiers[MAX_Q];
        for (int i = 0; i < q; ++i) {
            scanf("%d %d", &soldiers[i].L, &soldiers[i].R);
        }
        
        // Sort soldiers by L
        qsort(soldiers, q, sizeof(Soldier), compare);

        // Step 1: Calculate the total coverage of all soldiers
        int totalCoverage[MAX_N + 1] = {0};
        for (int i = 0; i < q; ++i) {
            for (int j = soldiers[i].L; j <= soldiers[i].R; ++j) {
                totalCoverage[j]++;
            }
        }

        // Step 2: Calculate the prefix sums for total coverage
        int prefixSum[MAX_N + 1] = {0};
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i - 1] + (totalCoverage[i] > 0 ? 1 : 0);
        }

        // Step 3: Find the maximum sections that can be guarded by excluding 2 soldiers
        int maxGuarded = 0;
        for (int i = 0; i < q; ++i) {
            for (int j = i + 1; j < q; ++j) {
                int overlap[MAX_N + 1] = {0};
                
                // Calculate the overlap removal for soldier i
                for (int x = soldiers[i].L; x <= soldiers[i].R; ++x) {
                    overlap[x]--;
                }
                
                // Calculate the overlap removal for soldier j
                for (int x = soldiers[j].L; x <= soldiers[j].R; ++x) {
                    overlap[x]--;
                }
                
                // Calculate the total sections guarded if excluding soldiers i and j
                int currentGuarded = 0;
                for (int x = 1; x <= n; ++x) {
                    if (totalCoverage[x] + overlap[x] > 0) {
                        currentGuarded++;
                    }
                }
                
                if (currentGuarded > maxGuarded) {
                    maxGuarded = currentGuarded;
                }
            }
        }

        printf("%d\n", maxGuarded);
    }

    return 0;
}
