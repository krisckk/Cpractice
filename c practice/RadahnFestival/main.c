#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold intervals
typedef struct {
    double start;
    double end;
} Interval;

// Comparator function for sorting intervals by their start points
int cmp(const void* a, const void* b) {
    Interval* intervalA = (Interval*)a;
    Interval* intervalB = (Interval*)b;
    if (intervalA->start < intervalB->start) return -1;
    if (intervalA->start > intervalB->start) return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        double N;
        int Q;
        scanf("%lf %d", &N, &Q);

        Interval* intervals = (Interval*)malloc(Q * sizeof(Interval));

        for (int i = 0; i < Q; i++) {
            scanf("%lf %lf", &intervals[i].start, &intervals[i].end);
        }

        // Sort intervals based on the start position
        qsort(intervals, Q, sizeof(Interval), cmp);

        double safe_length = 0;
        double current_end = 0;

        for (int i = 0; i < Q; i++) {
            if (intervals[i].start > current_end) {
                safe_length += intervals[i].start - current_end;
            }
            if (intervals[i].end > current_end) {
                current_end = intervals[i].end;
            }
        }

        // Add the remaining safe space if there is any
        if (current_end < N) {
            safe_length += N - current_end;
        }

        double safe_ratio = safe_length / N;
        printf("%.6lf\n", safe_ratio);

        free(intervals);
    }

    return 0;
}
