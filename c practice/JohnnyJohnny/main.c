#include <stdio.h>
#define MAX_N 30

int n, k;
int a[MAX_N];

int getans(int i, int sum){
    if(sum == k) return 1;
    if(i == n) return 0;
    return getans(i + 1, sum + a[i]) + getans(i + 1, sum);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%d\n", getans(0, 0));

}