#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}
int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n, p, k;
        scanf("%d %d %d", &n, &p, &k);
        
        int price[300001];
        int cost[300001];
        for(int i = 1; i<= n; i++) scanf("%d", &price[i]);
        qsort(price + 1, n, sizeof(int), compare);
        for(int i = 1; i <= n ; i++){
            if(i < k) cost[i] = cost[i - 1] + price[i];
            else cost[i] = cost[i - k] + price[i];
        }
        int ans = 0;
        for(int i = n; i > 0; i--){
            if(cost[i] <= p){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    
}