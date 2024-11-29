#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100001

int n;
int a[MAX_N];

int cmp(const void *L, const void *R) {
	int l = *(int*)L, r = *(int*)R;
	if(l > r) return 1;
	else if(l < r) return -1;
	else return 0;
}
int lower_bound(int *arr, int L, int R, int num) {
    int mid;
    while(L < R) {
        mid = (L + R) / 2;
        if(arr[mid] >= num) R = mid;
        else L = mid + 1;
    }
    return R;
}
int upper_bound(int *arr, int L, int R, int num) {
    int mid;
    while(L < R) {
        mid = (L + R) / 2;
        if(arr[mid] > num) R = mid;
        else L = mid + 1;
    }
    return R;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	qsort(a, n, sizeof(int), cmp);
	int q, x;
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &x);
		printf("%d\n", upper_bound(a, 0, n, x) - lower_bound(a, 0, n, x));
	}
}