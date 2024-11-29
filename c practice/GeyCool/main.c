#include <stdio.h>
#include <stdlib.h>
#define MAX_N 2000000
int arr[MAX_N+ 1];
long long pre[MAX_N + 1];

int main(){
    pre[0] = 0;
    int number, queries;
    int ans_a, ans_b;
    long long ans_sum = 0;
    while(scanf("%d%d", &number, &queries) != EOF){

        for(int i = 1; i <= number; ++i){
            scanf("%d", &arr[i]);
        }
        for(int i = 1; i <= number; ++i){
            pre[i] = pre[i - 1] + arr[i];
        }
        int ans_a, ans_b;
        long long ans_sum = 0;
        while(queries--){
            int a, b;
            long long sum = 0;
            scanf("%d %d", &a, &b);
            if(a > b){
                sum = pre[b] + (pre[number] - pre[a - 1]);
            }
            else if(a <= b){
                sum = pre[b] - pre[a - 1];
            }
            if(sum > ans_sum){
                ans_sum = sum;
                ans_a = a;
                ans_b = b;
            }
        }
        printf("Max_range: (%d,%d); Value: %lld\n", ans_a, ans_b, ans_sum);
    }
}
