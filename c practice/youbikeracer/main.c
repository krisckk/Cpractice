#include <stdio.h>


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    long long int ckpt[n + 1];
    long long int dis[n + 1];
    for(int i = 0; i < n; i++){
        scanf("%lld", &ckpt[i]);
    }
    for(int i = 0; i < n; i++){
        if(i == 0) dis[i] = ckpt[i];
        else dis[i] = ckpt[i] - ckpt[i - 1];
    }
    long long int current = 0;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(dis[i] > k) { 
            printf("The Legend Falls."); 
            return 0; 
        }
        if(current + dis[i] > k) { 
            ans++;
            current = 0; 
        }
        current += dis[i];
    }
    printf("%d", ans);
}