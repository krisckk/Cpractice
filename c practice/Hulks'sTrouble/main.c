#include <stdio.h>
#include <stdlib.h>
int lowerBound(int *arr, int L, int R, int x){
    
    while(L < R){
        int mid = (L + R) / 2;
        if(arr[mid] >= x) R = mid;
        else L = mid + 1;
    }
    return R;
}
int upperBound(int *arr, int L, int R, int x){
    while(L < R){
        int mid = (L + R) / 2;
        if(arr[mid] > x) R = mid;
        else L = mid + 1;
    }
    return R;
}
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int x;
        scanf("%d", &x);
        printf("%d\n", upperBound(a, 0, n, x) - lowerBound(a, 0, n, x));
    }
    return 0;
}