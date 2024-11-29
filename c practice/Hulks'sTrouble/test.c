#include <stdio.h>
#include <stdlib.h>

int lowerBound(int *arr, int left, int right, int target){
    while(left < right){
        int mid = (left + right) / 2;
        if(arr[mid] >= target) right = mid;
        else left = mid + 1;
    }
    return right;
}
int higherBound(int *arr, int left, int right, int target){
    while(left < right){
        int mid = (left + right) / 2;
        if(arr[mid] > target) right = mid;
        else left = mid + 1;
    }
    return right;
}
int cmp(const void *left, const void *right){
    return *(int*)left - *(int*)right;
}
int main(){
    int N;
    scanf("%d", &N);
    int* array = (int*)malloc(sizeof(int));
    for(int i = 0; i < N; ++i)scanf("%d", array[i]);
    qsort(array, N, sizeof(int), cmp);
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int x;
        scanf("%d", &x);
        printf("%d\n", higherBound(array, 0, N, x) - lowerBound(array, 0, N, x));
    }
}